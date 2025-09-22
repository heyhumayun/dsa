int longestSubarrayWithSumK(vector<int>& nums, int K) {

    unordered_map<int, int> prefixSumIndex;
    int sum = 0;
    int maxLength = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];

        if (sum == K) {
            maxLength = i + 1; // subarray from index 0 to i
        }

        // If (sum - K) seen before, we found a subarray
        if (prefixSumIndex.find(sum - K) != prefixSumIndex.end()) {
            maxLength = max(maxLength, i - prefixSumIndex[sum - K]);
        }

        // Store the first occurrence of sum
        if (prefixSumIndex.find(sum) == prefixSumIndex.end()) {
            prefixSumIndex[sum] = i;
        }
    }

    return maxLength;
}
