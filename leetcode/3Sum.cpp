ass Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        sort(num.begin(), num.end());
        int n = num.size();
        vector< vector<int> > ans;
        for(int i=0;i<n-2;i++)
        {
            int pnt = n - 1;
            for(int j=i+1;j<n-1;j++)
            {
                while(j < pnt && num[i]+num[j]+num[pnt]>0) pnt--;
                if(j == pnt )
                    continue;
                if(num[i] + num[j] + num[pnt] == 0)
                {
                    vector<int> v;
                    v.push_back(num[i]);
                    v.push_back(num[j]);
                    v.push_back(num[pnt]);
                    ans.push_back(v);
                }
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};
