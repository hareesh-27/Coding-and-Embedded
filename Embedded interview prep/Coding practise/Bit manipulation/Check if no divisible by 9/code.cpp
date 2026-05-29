class Solution {
public:
    bool isDivisibleBy9(const string& s) {
        int sol=0;
        for(int i=0;i<s.length();i++)
        {
            char c = s[i];
            sol+=(c-'0');
        }

        return (sol%9 ==0)? 1: 0;
    }
};
