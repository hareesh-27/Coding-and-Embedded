class Solution {
private:
    // Helper function that prevents overflow
    // Returns: 
    // 0 if mid^N == M
    // 1 if mid^N > M
    // 2 if mid^N < M
    int checkPower(int mid, int N, int M) {
        long long res = 1;
        for (int j = 1; j <= N; j++) {
            res *= mid;
            // The secret sauce: if it's already bigger than M, stop multiplying!
            if (res > M) return 1; 
        }
        if (res == M) return 0;
        return 2;
    }

public:
    int NthRoot(int N, int M) {
        int low = 1;
        int high = M;

        while (low <= high) {
            int mid = (low + high) / 2;

            int status = checkPower(mid, N, M);

            if (status == 0) {
                return mid; // Found the perfect match
            }
            else if (status == 2) {
                low = mid + 1; // mid^N is less than M, look higher
            }
            else {
                high = mid - 1; // mid^N is greater than M, look lower
            }
        }

        return -1;
    }
};
