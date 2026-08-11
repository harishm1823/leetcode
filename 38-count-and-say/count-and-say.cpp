class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string result = "1";

        // Generate sequence from 2 to n
        for (int i = 2; i <= n; i++) {
            string current = "";
            int count = 1;

            for (int j = 0; j < result.length(); j++) {
                // Check if the current character is the same as the next one
                if (j + 1 < result.length() && result[j] == result[j + 1]) {
                    count++;
                } else {
                    // Append frequency and character
                    current += to_string(count) + result[j];
                    count = 1; // Reset count for the next digit group
                }
            }

            result = current;
        }

        return result;
    }
};