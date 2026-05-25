class Solution {
public:
    long long multiplyTwoNumbers(int a, int b) {
        // Step 1: Determine the sign of the final result using XOR
        // True if signs are mismatched (one positive, one negative)
        bool is_negative = (a < 0) ^ (b < 0);

        // Step 2: Convert both numbers to positive absolute values
        // We cast to 'long long' first to prevent INT_MIN overflow
        long long A = abs((long long)a);
        long long B = abs((long long)b);
        
        long long result = 0;

        // Step 3: The Multiplication Loop (Doubling and Halving)
        while (B > 0) {
            // Check if the multiplier B is odd using bitwise AND
            if (B & 1) { 
                result += A; // Deposit current value of A into our vault
            }
            
            A <<= 1; // Left shift: Double A for the next round
            B >>= 1; // Right shift: Cut B in half for the next round
        }

        // Step 4: Apply the final sign from our notepad
        return is_negative ? -result : result;
    }
};
