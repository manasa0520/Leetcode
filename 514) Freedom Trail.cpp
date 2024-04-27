const int INF = 1e9;
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m = ring.size();
        int n = key.size();
        vector < vector <int> > dp(n + 1, vector <int>(m, INF));
        for(int i = 0; i < m; i++)dp[n][i] = 0;
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < m; j++){
                
                if(ring[j] != key[i]) continue;
                for(int k = 0; k < m; k++){
                    
                    int dist = abs(k - j);
                    dist = min(dist, m - dist);
                    dp[i][k] = min(dp[i][k], dist + dp[i + 1][j]);
                }
            }
        }
        return dp[0][0] + n;
    }
};
