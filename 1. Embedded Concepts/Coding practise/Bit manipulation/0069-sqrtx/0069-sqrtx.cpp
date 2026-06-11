class Solution {
private:
    long long CheckPow(long long num, int n)
    {
        long long result = num*num;
        if(result > n) return 0;
        else if(result < n) return 1;
        else return 2;
    }
public:
    int mySqrt(int x) {
        int low=1;
        int high=x;
        int ans;
        while(low<=high)
      {
        int mid=low + (high-low)/2;

        long long status=CheckPow(mid,x);

        if(status == 0) high=mid-1;

        else if(status == 1)
        {
            low=mid+1;
            ans=mid;
        }

        else return mid;
      }

        return ans;
    }
};