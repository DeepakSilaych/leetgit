class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; i++){
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }
        std::vector<int> answer;
        for (int query : queries){
            int maxIndex = std::upper_bound(prefixSum.begin(), prefixSum.end(), query) - prefixSum.begin() - 1;
            answer.push_back(maxIndex);
        }
        return answer;
    }
};

