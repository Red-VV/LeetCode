class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)
            return false;
        int row = matrix.size() - 1;
        int col = 0;
        while(row >= 0 && col < matrix[row].size()) {
            if(matrix[row][col] < target)
                col++;
            else if(matrix[row][col] > target)
                --row;
            else
                return true;
        }
        return false;
    }
};