#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        int size = 26;
        vector<int> letters(size, 0);
        for(const auto &c : s) {
            letters[c-'a']++;
        }
        for(const auto &c : t) {
            letters[c-'a']--;
        }
        for(auto letter : letters) {
            if(letter != 0)
                return false;
        }
        return true;
    }
};