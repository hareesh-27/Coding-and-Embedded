class Solution {
public:

    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        int rows = mat.size();
        int cols = mat[0].size();

        vector<int> ans;

        // traverse all diagonals
        for(int d = 0; d < rows + cols - 1; d++) {

            vector<int> temp;

            // collect all elements of current diagonal
            for(int row = 0; row < rows; row++) {

                int col = d - row;

                // valid cell check
                if(col >= 0 && col < cols) {
                    temp.push_back(mat[row][col]);
                }
            }

            // reverse alternate diagonals
            if(d % 2 == 0) {
                reverse(temp.begin(), temp.end());
            }

            // add into final answer
            for(int x : temp) {
                ans.push_back(x);
            }
        }

        return ans;
    }
};