class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i < n;i++){
            mp[nums[i]]++;
        }
        for(auto& pair : mp)
        {
            if(pair.second > n/3) {
                 ans.push_back(pair.first);
            }
        }
        if(ans.empty()){
            return {};
        }
        return ans;
    }
};