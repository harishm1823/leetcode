class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();

        // If needle is longer than haystack, it can't be contained in haystack
        if (n > m) return -1;

        // Slide a window of length n over haystack
        for (int i = 0; i <= m - n; i++) {
            if (haystack.substr(i, n) == needle) {
                return i; // Return the first matching index
            }
        }

        return -1; // Needle not found
    }
};