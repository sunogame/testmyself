class Solution {
public:
    double pow(double x, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        bool neg = false;
        if(n < 0)
        {
            n = -n;
            neg = true;
        }
        double ans=1;
        long long nn = 1;
        while(nn <= n)
        {
            if(nn&n)
            {
                ans *= x;
            }
            x*=x;
            nn<<=1;
        }
        if(neg)
            return 1/ans;
        return ans;
    }
}; 

