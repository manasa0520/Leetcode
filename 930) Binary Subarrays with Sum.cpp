class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int res = 0;
        unordered_map<int, int> m{};
        int presum = 0;

        m[0] = 1;
        for (int i=0;i<A.size();i++) {
            presum += A[i];
            res += m[presum - S];
            m[presum]++;
        }

        return res;
    }
};
