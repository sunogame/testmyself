class Solution {
public:
    string multiply(string num1, string num2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n1 = num1.size();
        int n2 = num2.size();
        vector<int> res(n1+n2+1, 0); 
        for(int i=0;i<n1;i++)
        {   
            for(int j=0;j<n2;j++)
            {   
                res[i+j] += (num1[n1-i-1]-'0')*(num2[n2-j-1]-'0');
            }   
        }   
        int inc = 0, high=0;
        for(int i=0;i<res.size();i++)
        {   
            res[i]+=inc%10;
            inc/=10;
            inc += res[i]/10;
            res[i] %= 10; 
            if(res[i] != 0)high = i;
        }   
        string ans;
        while(high>=0) ans += (char)(res[high--]+'0');
        return ans;
    }   
};

