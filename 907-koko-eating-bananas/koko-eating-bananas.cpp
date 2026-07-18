class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
    int low=1,high = findmax(piles);
    while(low<=high){
    int mid=low + (high - low) / 2;
    long long totalhours = calctothour(piles,mid);
    if(totalhours<=h){
        high=mid-1;
    }
    else{
            low=mid+1;
    }
    }
    return low;
  }
  int findmax(vector<int>& piles){
        int n =  piles.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);
        }
        return maxi;
    }
    long long calctothour(vector<int>& piles, int k){
        long long totalhours=0;
        int n = piles.size();
        for(int i=0;i<n;i++){
          totalhours += ceil((double)piles[i]/(double)k);
       }
        return totalhours;
    }
};