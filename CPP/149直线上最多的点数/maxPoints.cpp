class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {        
        if(points.size() < 3)
            return points.size();
        int res = 0;
        for(int i = 0; i < points.size(); ++i) {
            int a = points[i][0];
            int b = points[i][1];
            map<pair<int, int>, int> count;
            int samePoint = 1;
            int maxPoints = 0;
            for(int j = i + 1; j < points.size(); ++j) {
                int c = points[j][0];
                int d = points[j][1];
                if(a == c && b == d) {
                    ++samePoint;
                } else {
                    pair<int, int> key = getSlope(a, b, c, d);
                    maxPoints = max(maxPoints, ++count[key]);
                }
                
            }
            res = max(res, maxPoints + samePoint);
        }
        return res;
    }
private:
    pair<int, int> getSlope(int x1, int y1, int x2, int y2) {
        int dx = x1 - x2;
        int dy = y1 - y2;
        if(dx == 0) {
            return make_pair(0, x1);
        }
        if(dy == 0) {
            return make_pair(y1, 0);
        }
        int num = gcd(dx, dy);
        return make_pair(dx / num, dy / num);
    }
    int gcd(int a, int b) {
        return a == 0 ? b : gcd(b % a, a);
    }
};