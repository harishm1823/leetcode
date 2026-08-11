class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes (e.g., -121 -> 121-).
        // Also, if the last digit is 0, the first digit must be 0 (only true for x = 0).
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        // Reversing only half of the number to prevent integer overflow
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // For even-length numbers: x == reversedHalf (e.g., 1221 -> x = 12, reversedHalf = 12)
        // For odd-length numbers: x == reversedHalf / 10 (e.g., 12321 -> x = 12, reversedHalf = 123)
        return x == reversedHalf || x == reversedHalf / 10;
    }
};