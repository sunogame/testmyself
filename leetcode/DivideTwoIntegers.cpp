class Solution {
public:

    int divide(long long dividend, long long divisor) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int flag = (dividend < 0 ) ^ (divisor < 0);
        if(dividend < 0) dividend = -dividend;
        if(divisor < 0) divisor = -divisor;

        if(divisor > dividend)
            if(flag)return 0;
            else return 0;


        int ans = 0;
        while(true)
        {
            int res;
            long long fac;
            divmod(dividend, divisor, res, fac);
            //printf("%d %d %d %d\n", dividend, divisor, res, fac);
            if(res == 0)break;
            ans += res;
            dividend -= fac;
        }
        if(flag) ans = -(ans);
        return ans;
    }

    void divmod(long long dividend, long long divisor, int& ans, long long& fac){
        ans = 0;
        fac = 0;
        if(dividend < divisor)
            return;
        ans = 1;
        while(true)
        {
            if(dividend < (divisor<<1))
                break;
            divisor <<= 1;
            ans += ans;
        }
        fac = divisor;
        return;
    }
};
