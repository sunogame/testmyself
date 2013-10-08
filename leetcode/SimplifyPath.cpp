class Solution {
public:
    string uplevel(string s){
        if(s.size() == 0)
            return s;
        int i = s.size() - 1;
        while(s[i]!='/') i--;
        return s.substr(0, i);
    }

    string simplifyPath(string path) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string ans;
        string cur_word;
        path += '/';
        for(int i=0;i<path.size();i++)
        {
            if(path[i] != '/')
            {
                cur_word += path[i];
            }
            else if(cur_word.size())
            {
                if(cur_word == "..")
                {
                    ans = uplevel(ans);
                }
                else if(cur_word == ".")
                {

                }
                else
                {
                    ans += "/";
                    ans += cur_word;
                }
                cur_word = "";
            }
        }
        if(ans.size() == 0)
            return "/";
        return ans;
    }
};

