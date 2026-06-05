class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1, first = nums[0];
        if (nums[r] > nums[0])
            return nums[0];
        while (l < r) {
            int mid = (l + r) / 2;
            bool sorted = nums[mid] < nums[mid+1];
            if (sorted) {
                if (nums[mid] > first)
                    l = mid;
                else
                    r = mid;
            }
            else {
                return nums[mid+1];
            }
        }

        int index = (l + 1) % (nums.size());
        return nums[index];
        
    }
};
