class Solution {
public:
    int countStudents(vector<int>& v, vector<int>& v2) {
        vector <int> cnt1(2), cnt2(2);
        for(auto& it : v){
            cnt1[it]++;
        }
        
        int ret = 0;
        int n = v2.size();
        for(int i = 0; i < n; i++){
            if(!cnt1[v2[i]]){
                return n - i;
            }
            cnt1[v2[i]]--;
        }
        return ret;
    }
};
