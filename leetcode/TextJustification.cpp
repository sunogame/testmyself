class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int b = 0, cnt = 0, sum = 0;
        vector<string> res;
        for(int i=0;i<words.size();i++)
        {
            if(cnt != 0)
                cnt++;
            sum += words[i].size();
            cnt += words[i].size();
            if(i+1 == words.size() || cnt + words[i+1].size()+1 > L)
            {
                int emp = i-b, d, m;
                string line;
                if(emp>0)
                {
                    d = (L-sum)/emp;
                    m = (L-sum)%emp;
                }
                for(int j=b;j<i;j++)
                {
                    line+=words[j];
                    if(i+1 == words.size()) line += ' ';
                    else
                        for(int k=0;k<d+(m>0);k++)line+=' ';
                    m--;
                }
                line += words[i];
                int left = L-line.size();
                for(int k=0;k<left;k++) line += ' ';
                
                res.push_back(line);
                b = i+1;
                cnt = 0;
                sum = 0;
            }
        }
        return res;
    }
};
