class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        bool vis[10][10][10][10] = {0};
        for(auto& d: deadends) vis[d[0]-'0'][d[1]-'0'][d[2]-'0'][d[3]-'0'] = true;
        if(vis[0][0][0][0]) return -1;
        queue<tuple<int8_t,int8_t,int8_t,int8_t>> q; q.push({0,0,0,0});
        tuple<int8_t,int8_t,int8_t,int8_t> t = {target[0]-'0', target[1]-'0', target[2]-'0', target[3]-'0'};
        
        constexpr static int8_t movs[8][4] = {{1,0,0,0},{-1,0,0,0},{0,1,0,0},{0,-1,0,0},{0,0,1,0},{0,0,-1,0},{0,0,0,1},{0,0,0,-1}};
        int steps = 0;
        while(!q.empty()) {
            int k = q.size();
            for(int z=0; z<k; z++) {
                if(q.front()==t) return steps;
                auto [a,b,c,d] = q.front(); q.pop();
                for(const auto& mov: movs) {
                    tuple<int8_t,int8_t,int8_t,int8_t> next{(a+mov[0]+10)%10,(b+mov[1]+10)%10,(c+mov[2]+10)%10,(d+mov[3]+10)%10};
                    if(!vis[get<0>(next)][get<1>(next)][get<2>(next)][get<3>(next)]) {
                        q.push(next);
                        vis[get<0>(next)][get<1>(next)][get<2>(next)][get<3>(next)] = true;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
