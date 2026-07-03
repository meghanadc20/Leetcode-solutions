class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            //check for duplicate i values
            if(i > 0 && nums[i]==nums[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j<k) {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum < 0) j++;
                else  if(sum > 0) k--;
                else {
                    vector<int> row = {nums[i],nums[j],nums[k]};
                    ans.push_back(row);
                    j++;
                    k--;
                //check for duplicate j and k values
                 while(j<k && nums[j] == nums[j-1]) j++;
                 while(j<k && nums[k] == nums[k+1]) k--;
                }

            }
        }
        return ans;
        
    }
};