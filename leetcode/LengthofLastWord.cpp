class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = strlen(s);
        int ans = 0;
        int i = len-1;
        while(s[i] == ' ') i--;
        for(;i>=0;i--)
        {
            if(s[i]==' ')
                break;
            ans++;
        }
        return ans;
    }
};
