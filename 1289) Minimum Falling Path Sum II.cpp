int dp[10005][205];
class Solution {
public:
    void pre(){
        for(int i = 0; i <= 10000; i++){
            for(int j = 0; j <=204; j++){
                dp[i][j] = -1;
            }
        }
    }
    
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        for(int i = 1; i < n; i++){
            vector <int> leftMin(m);
            vector <int> rightMin(m);
            leftMin[0] = arr[i-1][0];
            for(int j = 1; j < m; j++){
                leftMin[j] = min(leftMin[j-1], arr[i-1][j]);
            }
            rightMin[m-1] = arr[i-1][m-1];
            for(int j = m - 2; j >= 0; j--){
                rightMin[j] = min(arr[i-1][j], rightMin[j + 1]);
            }
            for(int j = 0; j < m; j++){
                int leftVal = (j - 1) >= 0?leftMin[j-1]:1000000;
                int rightVal = (j + 1) < m ?rightMin[j+1]:1000000;
                arr[i][j] += min(leftVal, rightVal);
                
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < m; i++)ans = min(ans, arr[n-1][i]);
        return ans;
    }
};
