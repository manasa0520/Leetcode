class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0) return 0;

        sort(points.begin(), points.end(), 
            [](vector<int>& a, vector<int>& b){
                return a[1] < b[1];
            });
        
        //shot to the end of first balloon
        int arrowPos = points[0][1];
        int arrowCnt = 1;
        
        for(vector<int>& point : points){
            if(point[0] <= arrowPos){
                
                continue;
            }
           
            arrowCnt++;
            arrowPos = point[1];
        }
        
        return arrowCnt;
    }
};
