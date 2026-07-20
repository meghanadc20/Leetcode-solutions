class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
         int high = accumulate(weights.begin(), weights.end(), 0);
         int ans = high;
         while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canShip(weights, days, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
    bool canShip(vector<int>& weights, int days, int capacity) {
        // Initialize required days and current load
        int requiredDays = 1;
        int currLoad = 0;

        // Iterate through all package weights
        for (int w : weights) {
            // If adding weight exceeds capacity, start new day
            if (currLoad + w > capacity) {
                requiredDays++;
                currLoad = 0;
            }
            // Add current weight to load
            currLoad += w;
        }
        return requiredDays <= days;
    }
};