#define ff              first
#define ss              second
#define pb              push_back
#define MOD             1000000007
#define inf             1e18

typedef long long int lli;

class Solution {
public:
	int maxSubarrayLength(vector<int>& nums, int k) {
		int ret = 0;
		map<int, int> freq;
		int n = nums.size();
		for (int i = 0, j = 0; i < n; i++) {
			freq[nums[i]]++;
			while (j <= i && freq[nums[i]] > k) {
				freq[nums[j]]--;
				j++;
			}
			ret = max(ret, i - j + 1);
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
