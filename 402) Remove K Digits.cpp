class Solution {
public:
    string removeKdigits(string num, int k) {
        stack <char> st;
        string ret = "";
        int n = num.size();
        for(int i = 0; i < n; i++){
            while(k && !st.empty() && st.top() > num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k--)st.pop();
        while(!st.empty()){
            ret += st.top();
            st.pop();
        }
        reverse(ret.begin(), ret.end());
        string ans = "";
        int i = 0;
        while(i < ret.size() && ret[i] == '0')i++;
        for(; i < ret.size(); i++)ans += ret[i];
        ret = ans;
        return ret.size() == 0? "0" : ret;
    }
};
