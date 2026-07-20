class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = INT_MIN;
       for(int j=0;j<nums.size();j++){
        maxi = max(maxi,nums[j]);
       }
       int low = 1, high = maxi;
       int ans = -1;
       while(low<=high){
       int mid = low + (high-low)/2;
       if(isum(nums,mid, threshold)){
        ans = mid;
        high = mid-1;
       } else {
         low= mid+1;
       }
     }
     return ans;
    }
    bool isum (vector<int>& nums, int m, int  threshold){
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n;i++){
            sum += ceil((double)nums[i]/m);
        }
        return sum<= threshold;
    }
};