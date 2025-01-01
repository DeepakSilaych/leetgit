class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        return subArrayAllocation(nums, k);
    }
    bool isPossible(vector<int>& nums, int k, int mid) {
        int AllotedK = 1, currAllocation = 0;
        for (int i = 0; i < nums.size(); i++) {
            currAllocation += nums[i];
            if (currAllocation > mid) {
                AllotedK++;
                currAllocation = nums[i];
            }
        }
        return AllotedK <= k;
    }
    int subArrayAllocation(vector<int>& nums, int k) {
        if (k > nums.size())
            return -1;
        int s = *max_element(nums.begin(), nums.end()); // finding max
        int e = accumulate(nums.begin(), nums.end(),
                           0); // finding sum of all elements
        if (k == nums.size())
            return s;
        int ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (isPossible(nums, k, mid)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};