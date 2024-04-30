class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<int> unor(1024, 0);
        vector<int> v(10, 0);
        unor[0] = 1;
        int tmp = 0;
        int t = 0;
        long long answer = 0;
        for (int i = 0; i != word.size(); ++i)
        {
            ++v[word[i] - 'a'];
            tmp = 0;
            for (int j = 0; j != 10; ++j)
            {
                tmp += (1 << j)*(v[j] % 2);
            }
            for (int j = 0; j != 10; ++j)
            {
                if ((((1 << j)&tmp)) == 0)
                {
                    answer += unor[tmp|(1 << j)];
                }
                else
                {
                    answer += unor[tmp^(1 << j)];
                }
            }
            answer += unor[tmp];
            ++unor[tmp];            
        }
        return answer;    
    }
};
