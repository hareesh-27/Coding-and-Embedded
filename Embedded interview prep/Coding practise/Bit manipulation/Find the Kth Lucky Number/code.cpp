class Solution {
    public:
        string kthLuckyNumber(int k) {
            string ans="";
            int n=k+1;
            while(n>1)
            {
                if((n & 1) == 0) ans+='4';
                else ans+='7';

                n=n>>1;
            }
            reverse(ans.begin(),ans.end());

            return ans;
        }
};
