class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        for(int i=0, left_sum = 0; i<nums.size(); i++){
            if(left_sum == sum - left_sum - nums[i]) return i;
            else left_sum += nums[i];
        }
        return -1;
    }
};