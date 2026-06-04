class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0;
        int r = heights.size()-1;

        int max = 0;
        while (l < r) {
            bool right_min = false;
            if (heights[r] < heights[l])
                right_min = true;

            int height = heights[l];
            if (right_min)
                height = heights[r];
            int cur = (r-l)* height;

            if (right_min)
                r = r-1;
            else
                l = l+1;

            if (max < cur)
                max = cur;
        }
        
        return max;
    }
};
