class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        //need to ensure that nums1 is shorter than or equal to nums2
        if(m > n){
            swap(nums1, nums2);
            swap(m, n);
        }
        
        int xstart = 0;
        int xend = m;
        
        while(xstart <= xend){
            //xmid ranges from 0 to m
            int xmid = (xstart+xend)/2;
            //if m > n, ymid may be negative!
            int ymid = (m+n+1)/2 - xmid;
            
            if(xmid < m && ymid > 0 && nums2[ymid-1] > nums1[xmid]){
                //xmid is too small
                xstart = xmid+1;
            }else if(xmid > 0 && ymid < n && nums1[xmid-1] > nums2[ymid]){
                //xmid is too large
                xend = xmid-1;
            }else{
                int maxLeft = max(xmid > 0 ? nums1[xmid-1] : INT_MIN, 
                                  ymid > 0 ? nums2[ymid-1] : INT_MIN);
                if((m+n) % 2 == 1) return maxLeft;
                
                int minRight = min(xmid < m ? nums1[xmid] : INT_MAX, 
                                   ymid < n ? nums2[ymid] : INT_MAX);
                
                return (maxLeft+minRight)/2.0;
            }
        }
        
        return 0.0;
    }
};
