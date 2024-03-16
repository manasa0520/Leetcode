//Approach 1
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> count2index;
        count2index[0] = -1;
        
        int ans = 0, count = 0;
        
        for(int i = 0; i < nums.size(); i++){
            count += (nums[i] == 0 ? -1 : 1);
            if(count2index.find(count) != count2index.end()){
                
                ans = max(ans, i-count2index[count]);
            }else{
               
                count2index[count] = i;
            }
        }
        
        return ans;
    }
};

//Approach 2
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       
        vector<int> arr(2*nums.size()+1, -2);
        
       
        arr[nums.size()] = -1; 
        int ans = 0, count = 0;
        
        for(int i = 0; i < nums.size(); i++){
            count += (nums[i] == 0 ? -1 : 1);
            if(arr[count + nums.size()] >= -1){
               
                ans = max(ans, i-arr[count+nums.size()]);
            }else{
               
                arr[count+nums.size()] = i;
            }
        }
        
        return ans;
    }
};
