class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int index = n;
        for(int i=0;i<n;i++){
            if(nums[i]== target || nums[i ]> target )
            {
               index = min(index,i);
            }
        }
        return index;
    }
};