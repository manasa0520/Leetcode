class Solution {
public:
    int timeRequiredToBuy(vector<int>& v, int k) {
        int ret = 0;
        
        while(v[k]){
            for(int j = 0; j < v.size(); j++){
                if(v[j]){
                    v[j]--;
                    ret++;
                }
                if(!v[j] && j == k) break;
            }
        }
        return ret;
    }
};
