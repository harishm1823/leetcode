#include <string>

class Solution {
public:
    bool isNumber(std::string s) {
        bool seenDigit = false;
        bool seenDot = false;
        bool seenExponent = false;

        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];

            if (ch >= '0' && ch <= '9') {
                seenDigit = true;
            } else if (ch == '+' || ch == '-') {
                // Sign is only valid at the start or immediately after 'e' / 'E'
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } else if (ch == '.') {
                // Dot is invalid if already seen or if after an exponent
                if (seenDot || seenExponent) {
                    return false;
                }
                seenDot = true;
            } else if (ch == 'e' || ch == 'E') {
                // Exponent is invalid if already seen or if no digits came before it
                if (seenExponent || !seenDigit) {
                    return false;
                }
                seenExponent = true;
                seenDigit = false; // Reset to ensure exponent is followed by digits
            } else {
                return false; // Any other character is invalid
            }
        }

        return seenDigit;
    }
};