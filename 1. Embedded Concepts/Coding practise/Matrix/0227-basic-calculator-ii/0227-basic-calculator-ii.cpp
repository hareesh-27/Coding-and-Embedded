#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int i = 0;
        return calculateHelper(s, i);
    }

private:
    int calculateHelper(const string& s, int& i) {
        vector<long long> stack; // Using long long to safely prevent intermediate overflow
        long long num = 0;
        char sign = '+';

        while (i < s.length()) {
            char c = s[i];

            // 1. If we see a digit, build the number
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            // 2. If we hit an opening parenthesis, solve it recursively
            if (c == '(') {
                i++; // Skip '('
                num = calculateHelper(s, i); // Treat the result as a single block number
            }

            // 3. If we see an operator or hit the end of an expression block
            if ((!isdigit(c) && c != ' ') || i == s.length() - 1) {
                if (sign == '+') stack.push_back(num);
                else if (sign == '-') stack.push_back(-num);
                else if (sign == '*') {
                    long long top = stack.back();
                    stack.pop_back();
                    stack.push_back(top * num);
                }
                else if (sign == '/') {
                    long long top = stack.back();
                    stack.pop_back();
                    stack.push_back(top / num);
                }
                
                sign = c; // Update operator sign for the next number
                num = 0;  // Reset number accumulator
            }

            // 4. If we hit a closing parenthesis, break out and return the sub-total
            if (c == ')') {
                break;
            }

            i++;
        }

        // Sum up all elements currently left in the stack
        long long total = 0;
        for (long long x : stack) {
            total += x;
        }
        return total;
    }
};

