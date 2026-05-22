class Solution {
public:
    int divide(int dividend, int divisor) {
        //base case
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;

        //handling negatives using xor
        bool is_negative = (dividend < 0) ^ (divisor < 0);

        //main part
        long long dvd = abs((long long)dividend); //changing -ve to +ve
        long long dvs = abs((long long)divisor);
        long long ans = 0; // quotient/answer
        while(dvd >= dvs)
        {
            long long temp_divisor = dvs;
            long long multiple = 1;

            //loop to get max multiple
            while(dvd > (temp_divisor << 1))
            {
                temp_divisor = temp_divisor << 1;
                multiple = multiple << 1;
            }

            dvd-=temp_divisor;
            ans+=multiple;
        }

        return is_negative ? -ans:ans;
    }
};