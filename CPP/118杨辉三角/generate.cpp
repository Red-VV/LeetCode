class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows, vector<int>());
        if(numRows == 0)
            return res;
        res[0].push_back(1);
        for(int i = 1; i < numRows; ++i) {
            res[i].push_back(1);
            for(int j = 0; j < res[i - 1].size() - 1; ++j) {
                res[i].push_back(res[i - 1][j] + res[i - 1][j + 1]);
            }
            res[i].push_back(1);
        }
        return res;
    }
};
