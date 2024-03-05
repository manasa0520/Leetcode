// Time complexity - O(n)
// Approach 1
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> position(128, -1);
        int ans = 0;
        
        for(int i = 0, j = 0; j < n; j++){
            if(position[s[j]] != -1){
                i = max(i, position[s[j]]+1);
            }
            ans = max(ans, j-i+1);
            position[s[j]] = j;
        }
        
        return ans;
    }
};

// Time complexity - O(n^3)
// Approach 2
class Solution {
public:
    bool allUnique(string& s, int start, int end){
        set<char> chars;
        
        for(int i = start; i <= end; i++){
            auto res = chars.insert(s[i]);
            if(res.second == false) return false;
        }
        
        return true;
    };
    
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                if(allUnique(s, i, j)){
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};
