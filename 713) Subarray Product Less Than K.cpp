typedef long long int lli;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        lli temp = 1;
        int j = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            temp *= nums[i];
            while(temp >= k && j <= i) {
                temp /= nums[j];
                j++;
            }
            ans += (i - j + 1);
        }
        return ans;
    }
};
