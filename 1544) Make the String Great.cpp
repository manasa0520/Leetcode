class Solution {
public:
    char getSmall(char x, char y){
        if(x >= 'a' && x <='z'){
            return y >='A' && y <= 'Z' && x == (y + 'a' - 'A');
        }else{
            return y >='a' && y <= 'z' && x == (y + 'A' - 'a');
        }
    }
    string makeGood(string s) {
        string ret = "";
        for(int i = 0; i < s.size(); i++){
            if(!ret.empty() && getSmall(ret.back(), s[i])){
                ret.pop_back();
            }else{
                ret += s[i];
            }
        }
        return ret;
    }
};
