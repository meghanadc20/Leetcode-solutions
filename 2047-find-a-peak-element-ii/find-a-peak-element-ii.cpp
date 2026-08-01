class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
         int n = mat.size();     
        int m = mat[0].size();    
        int low = 0;           
        int high = m - 1;      
        while (low <= high) {
            int mid = (low + high) / 2;  
            int row = maxElement(mat, mid);
            int left;
            if(mid-1>=0){
                left = mat[row][mid-1];
            }
            else {
                left = INT_MIN;
            }
            int right;
            if(mid+1<m){
                right = mat[row][mid+1];
            }
            else {
                right=INT_MIN;
            }
            if (mat[row][mid] > left && mat[row][mid] > right) {
                return {row, mid};  
            } 
            else if (left > mat[row][mid]) {
                high = mid - 1;  
            } 
            else {
                low = mid + 1;
            }
        }
        // Return {-1, -1} if no peak element is found
        return {-1, -1};
    }
    int maxElement(vector<vector<int>>& mat, int col) {
        int n = mat.size();
        int max_val = INT_MIN;
        int index = -1;
        for (int i = 0; i < n; i++) {
            if (mat[i][col] > max_val) {
                max_val = mat[i][col];
                index = i;
            }
        }
        return index;
    }
};