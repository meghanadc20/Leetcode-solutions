class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixSumCount;
        int prefixsum = 0;
        int count = 0;
        prefixSumCount[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            prefixsum += nums[i];
            int remove = prefixsum-k;
            if(prefixSumCount.find(remove) != prefixSumCount.end())
            {
                count += prefixSumCount[remove];
            }
            prefixSumCount[prefixsum]++;
        }
        return count;
    }
};