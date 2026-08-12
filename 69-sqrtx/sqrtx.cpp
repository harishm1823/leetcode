class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        int left = 1;
        int right = x / 2;
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Use division to prevent potential 32-bit integer overflow (mid * mid)
            if (mid <= x / mid) {
                ans = mid;        // Candidate answer found, try to find a larger one
                left = mid + 1;
            } else {
                right = mid - 1;  // mid is too big
            }
        }

        return ans;
    }
};