class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    long long minflowers = m * 1ll * k * 1ll; 
   if(minflowers>n) return -1;
   int mini = INT_MAX;
   int maxi = INT_MIN;
  
   //find the range, that is minimum day and maximum day to bloom
   for(int i=0;i<n;i++){
     mini = min(mini,bloomDay[i]);
     maxi = max(maxi,bloomDay[i]);
   }
   int left = mini, right = maxi, ans = -1;
        while (left <= right) {
         int mid = left + (right - left) / 2; 
         if (possible(bloomDay, mid, m, k)) {
            ans = mid; 
             right = mid - 1; 
            } else {
                left = mid + 1; 
            }
        }
        return ans;
        }
   
  bool possible(vector<int> &bloomDay,int day, int m, int k){
    int n = bloomDay.size();
    int count = 0;
    int boqcount=0;
    for(int j=0;j<n;j++){
        if(bloomDay[j]<=day){
            count++;
        }
        else {
            boqcount += (count/k);
            count = 0; //reset count
        }
    }
    boqcount += (count/k); //when last elem satisfies if condition then it's boque count needs to be counted
  /*  if(boqcount>=m){
        return true;
    }
    else return false; */
    return boqcount >= m;
    }
};