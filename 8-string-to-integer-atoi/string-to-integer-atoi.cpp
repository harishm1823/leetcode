#include <string>
#include <climits>
#include <cctype>

class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0;
        int n = s.length();

        // 1. Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Check for optional sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Process numerical digits and handle potential overflow
        int result = 0;
        while (i < n && std::isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check for overflow/underflow before multiplying result by 10
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};