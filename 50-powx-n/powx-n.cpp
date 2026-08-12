class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1.0 / x;
            N = -N;
        }

        double result = 1.0;
        double currentProduct = x;

        while (N > 0) {
            // If N is odd, multiply currentProduct with result
            if (N % 2 == 1) {
                result *= currentProduct;
            }
            // Square currentProduct and halve N
            currentProduct *= currentProduct;
            N /= 2;
        }

        return result;
    }
};