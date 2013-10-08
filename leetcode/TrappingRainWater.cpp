class Solution {
public:
    int trap(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n < 3)
            return 0;
        int ans = 0;
        int *left = new int[n];
        left[0] = A[0];
        for(int i=1;i<n;i++)
            left[i] = max(A[i], left[i-1]);
        int right = A[n-1];
        for(int i=n-2;i>0;i--)
        {
            ans += max(0, min(right, left[i])-A[i]);
            right = max(right, A[i]);
        }
        return ans;
    }
};

