class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        int r = 0;
        int c = 0;

        vector<int> ans;

        for(int i = 0; i < m * n; i++) {

            ans.push_back(mat[r][c]);

            // even diagonal -> ↗
            if((r + c) % 2 == 0) {

                if(c == n - 1)
                    r++;

                else if(r == 0)
                    c++;

                else {
                    r--;
                    c++;
                }
            }

            // odd diagonal -> ↙
            else {

                if(r == m - 1)
                    c++;

                else if(c == 0)
                    r++;

                else {
                    r++;
                    c--;
                }
            }
        }

        return ans;
    }
};