typedef long long int lli;

class Solution {
public:
	long long countSubarrays(vector<int>& nums, int k) {
		lli ret = 0;
		lli val = *max_element(nums.begin(), nums.end());
		int n = nums.size();
		vector<lli> pre(n);
		for (int i = 0; i < n; i++) {
			pre[i] = val == nums[i];
			if(i)pre[i] += pre[i - 1];
		}
    
		return Calc(pre, n) - Calc(pre, k - 1);
	}
	lli Calc( vector<lli>& pre, int k) {
		lli ret = 0;
		int n = pre.size();
		for (int i = 0; i < n; i++) {
			lli add = 0;
			lli low = 0, high = i;
			while (low <= high) {
				lli mid = low + (high - low) / 2;
                lli val = pre[i] - (mid ? pre[mid - 1] : 0);
				if ( val > k) {
					low = mid + 1;
				
				
				} else {
					high = mid - 1;
					add = i - mid  + 1;
                    
				}
			}
            
			ret += add;
		}
		return ret;
	}
};

#ifdef LOCAL
int main() {
	freopen("output.txt", "w", stdout);
	cout << "Compiled!" << endl;
}
#endif
