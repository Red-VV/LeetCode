class Solution {
public:
    vector<vector<string>> partition(string s) {
        int len = s.size();
        vector<vector<int>> flag(len, vector<int>(len, 0));
        for(int i = 0; i < len; ++i) {
            preProcessor(i, i, flag, s);
            preProcessor(i, i + 1, flag, s);
        }
        vector<string> path;
        vector<vector<string>> res;
        backtrace(0, path, res, s, flag);
        return res;
    }
private:
    void preProcessor(int left, int right, vector<vector<int>> &flag, string &s) {
        while(left >= 0 && right < flag.size() && s[left] == s[right]) {
            flag[left][right] = 1;
            --left;
            ++right;
        }
    }

    void backtrace(int start, vector<string> &path, vector<vector<string>> &res, string &s, vector<vector<int>> &flag) {
        if(start == s.size()) {
            res.push_back(path);
            return;
        }

        for(int i = start; i < s.size(); ++i) {
            if(flag[start][i] == 1) {
                path.push_back(s.substr(start, i - start + 1));
                backtrace(i + 1, path, res, s, flag);
                path.pop_back();
            }
        }
    }

};