#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int number = 0;
        if(tryNumber(input, number)) {
            return {number};
        }

        vector<int> res;
        for(int i = 0; i < input.size(); i++) {
            char c = input[i];
            if(!isdigit(c)) {
                auto left = diffWaysToCompute(input.substr(0, i));
                auto right = diffWaysToCompute(input.substr(i+1));
                for(const auto & l : left) {
                    for(const auto & r : right) {
                        switch(c) {
                            case '+' : res.push_back(l + r); break;
                            case '-' : res.push_back(l - r); break;
                            case '*' : res.push_back(l * r); break;
                        }
                    }
                }
            }
        }
        return res;
    }
private:
    bool tryNumber(string str, int &number) {
        int val = 0;
        for(const auto &c : str) {
            if(isdigit(c)) {
                val = val * 10 + (c - '0');
            } else {
                return false;
            }
        }
        number = val;
        return true;
    }
};