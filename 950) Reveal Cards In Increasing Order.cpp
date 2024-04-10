class Solution {
public:
    void out(vector <int>& arr){
        for(int i = 0; i < arr.size(); i++)cout << arr[i] << " ";
        cout <<endl;
    }
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        //out(deck);
        int n = deck.size();
        queue <int> q;
        vector <int> ans(n);
        for(int i = 0; i < n; i++)q.push(i);
        int x;
        for(int i = 0; i < n; i++){
            x = q.front();
            q.pop();
            ans[x] = deck[i];
            x = q.front();
            q.pop();
            q.push(x);
        }
        return ans;
    }
};
