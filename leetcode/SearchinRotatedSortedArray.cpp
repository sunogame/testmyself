class Solution {
public:
    int search(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int l=0, r=n-1;
        while(l<=r)
        {
            int mid = (l+r) /2;
            if(A[mid] == target)
                return mid;
            if(A[l] <= A[mid])
            {
                if(A[mid] < target)
                {
                    l = mid+1;
                }
                else if(target < A[l])
                {
                    l = mid+1;
                }
                else
                {
                    r = mid-1;
                }
            }
            else
            {
                if(A[mid] > target)
                {
                    r = mid-1;
                }
                else if(target > A[r])
                {
                    r = mid-1;
                }
                else
                {
                    l = mid+1;
                }
            }
        }
        return -1;
    }
};
