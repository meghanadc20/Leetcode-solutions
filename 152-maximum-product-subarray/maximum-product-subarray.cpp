class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int prefixsum = 1;
        int sufixsum = 1;
        int result = INT_MIN;
        int n = nums.size();
        for(int i=0; i<n; i++ ){
            if(prefixsum==0) prefixsum = 1; //reset prefix if sum is 0
            if(sufixsum==0) sufixsum = 1; //reset sufix if sum is 0
            prefixsum *= nums[i];
            sufixsum *= nums[n-i-1];
            result = max(result, max(prefixsum,sufixsum));
        }
        return result;
    }
};