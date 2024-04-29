#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define pb              push_back
#define MOD             1000000007
#define inf             1e18

typedef long long int lli;
const int K = 32;
class Solution {
public:
	int GetBit(int mask, int idx) {
		return (mask >> idx) & 1;
	}
	int minOperations(vector<int>& nums, int k) {
		vector<int> bits(K);
		for (auto& it : nums) {
			for (int i = 0; i < K; i++) {
				bits[i] += GetBit(it, i);
			}
		}
		int ret = 0;
		for (int i = 0; i < K; i++) {
			int required = GetBit(k, i);
			ret += required != (bits[i] & 1);
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
