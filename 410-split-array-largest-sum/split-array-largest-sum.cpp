class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n) return -1;
        int low  = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid = (low+high)/2;
            int value = countSubSum(nums,mid);
            if(value>k){
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return low;
    }
    int countSubSum(vector<int>& nums, int maxvalue){
         int n = nums.size();
         int count = 1;
         int subarraysum = 0;
         for(int i=0;i<n;i++) {
               if(subarraysum+nums[i]<=maxvalue){
                subarraysum+=nums[i];
               }
               else {
                count++;
                subarraysum = nums[i];
               }
           }
           return count;
    }
};