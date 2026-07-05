class Solution {
public:
    int search(vector<int>& nums, int target) {
         int n = nums.size();
        int i =0;
        int j = n-1;
     for(int i = 0; i <= j ; i++){
        if(nums[i]==target)
        {
            return i;
        }
        else if(nums[j]==target)
        {
            return j;
        }
        else j--;
     }
     return -1;
    }
};