class Solution{
public:
 bool searchMatrix(vector<vector<int>> &matrix, int target){
      int r=matrix.size();
      int c=matrix[0].size();

      int rows=0;
      int columns=c-1;

      while(rows<r && columns>=0)
      {
        if(matrix[rows][columns] == target) return true;

        else if(target > matrix[rows][columns]) rows++;

        else columns--;
      }

      return 0;
    }
};