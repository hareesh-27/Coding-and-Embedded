class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low_col=0;
        int high_col=mat[0].size()-1;

        while(low_col<=high_col)
        {
            int mid_col=(low_col+high_col)/2;

            //find max value in middle column
            int max_val = INT_MIN;
            int max_row;
            for(int i=0;i<mat.size();i++)
            {
                if(mat[i][mid_col] > max_val)
                {
                    max_val = mat[i][mid_col];
                    max_row = i;
                }
            }

            //comparing to left and right also taking care of imaginary boundaries
            int left_val = (mid_col - 1 >= 0) ? mat[max_row][mid_col-1] : -1;
            int right_val = (mid_col + 1 <= mat[0].size()-1) ? mat[max_row][mid_col+1] : -1;

            //making respective changes
            if(max_val > left_val && max_val > right_val) return {max_row, mid_col};
            else if(left_val > max_val) high_col=mid_col-1;
            else low_col=mid_col+1;
        }
        return {-1,-1};
    }
};