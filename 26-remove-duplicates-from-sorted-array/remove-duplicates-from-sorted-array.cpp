class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        // Pointer 'k' keeps track of the position for unique elements
        int k = 1;

        for (int i = 1; i < nums.size(); i++) {
            // Whenever a new unique element is found
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i]; // Place it at index k
                k++;               // Increment the count of unique elements
            }
        }

        return k;
    }
};