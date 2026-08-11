class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // Pointer to place the next valid element

        for (int i = 0; i < nums.size(); i++) {
            // If the current element is not equal to val, keep it
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++; // Increment count of non-val elements
            }
        }

        return k;
    }
};