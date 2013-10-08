class Solution {
public:
    int partition(int a[], int l, int r)
    {
        int p = rand()%(r-l+1) + l, rr = r;
        swap(a[l], a[p]);
        p = l++;
        while(1)
        {
            while(l<=r && a[l] < a[p]) ++l;
            while(l<=r && a[p] <= a[r]) --r;
            if( l > r ) break;
            swap(a[l++], a[r--]);
        }
        swap(a[p], a[r]);
        p = r+1;
        for(int i=r+1;i<=rr;i++)if(a[i] == a[r])
            swap(a[p++], a[i]);
        return r;
    }

    int find(int a[], int l, int r)
    {
        if(l > r)
            return -1;
        if(l == r)
            return a[l];
        int p = partition(a, l, r);
        if(p == r || a[p] != a[p+1])
            return a[p];
        if((p-l)%3!=0)
            return find(a, l, p-1);
        else
            return find(a, p+3, r);
    }

    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        find(A,0,n-1);
    }
};

