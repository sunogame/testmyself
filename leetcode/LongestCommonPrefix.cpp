class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string ans;
        if(strs.size() == 0)
            return ans;
        int pnt = 0;
        while(true)
        {
            if(pnt == strs[0].size())
                break;
            char a = strs[0][pnt];
            for(int i=1;i<strs.size();i++)
            {
                if(strs[i].size() == pnt || strs[i][pnt] != a)
                    return ans;
            }
            ans += a;
            pnt ++;
        }
        return ans;
    }
};
