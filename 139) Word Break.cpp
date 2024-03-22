class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        
        for(int end = 1; end <= n; ++end){
            for(int start = 0; start < end; ++start){
                //dp[start]: s[0...start-1]
                if(dp[start] && find(wordDict.begin(), wordDict.end(), s.substr(start, end-start)) != wordDict.end()){
                    //s[0...end-1] can be split into s[0...start-1] and s[start...end-1]
                    dp[end] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};
