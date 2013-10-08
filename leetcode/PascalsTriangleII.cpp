class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> ans[2];
        ans[0] = vector<int>(rowIndex+3, 0);
        ans[1] = vector<int>(rowIndex+3, 0); 
        ans[0][1] = 1;
        for(int i=1;i<=rowIndex;i++)
        {   
            int pre = (i-1)&1;
            int cur = i&1;
            for(int j=1;j<=i+1;j++)
            {
                ans[cur][j] = ans[pre][j-1]+ans[pre][j];
            }
        }
        vector<int> res;
        for(int i=1;i<=rowIndex+1;i++)
            res.push_back(ans[rowIndex&1][i]);
        return res;
    }   
};
