class Solution {
public:
    int longest(string &s, int l, int r)
    {
        for(int i=0;i<=s.size();i++)
        {
            if(l-i<0 || r+i==s.size() || s[l-i] != s[r+i])
                return i;
        }
        return 0;
    }

    string longestPalindrome(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = 0;
        string ans;
        for(int i=0;i<s.size();i++)
        {
            int l1 = longest(s, i, i+1)*2;
            int l2 = longest(s, i, i)*2-1;
            if( l1 > len)
            {
                len = l1;
                ans = s.substr(i-len/2+1, len);
            }
            if( l2 > len)
            {
                len = l2;
                ans = s.substr(i-len/2, len);
            }
        }
        return ans;
    }
};

