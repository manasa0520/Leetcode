class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26);
        for (char c : s) {
            int i = c - 'a';
            int cnt = 0;
            for (int j = max(0, i - k); j <= min(25, i + k); ++j) {
                cnt = max(cnt, dp[j]);
            }

            dp[i] = cnt + 1;
        }

        return *max_element(dp.begin(), dp.end());
    }
};
