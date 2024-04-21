class Solution {
public:
    vector<int> parent;

    int Find(int x)
    {
        if (parent[x] != x)
            parent[x] = Find(parent[x]);
        return parent[x];
    }

    void union_set(int x, int y)
    {
        int root_x = Find(x);
        int root_y = Find(y);
        if (root_x != root_y)
            parent[root_x] = root_y;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto& edge : edges)
        {
            union_set(edge[0], edge[1]);
        }
        return Find(source) ==  Find(destination);
    }
};
