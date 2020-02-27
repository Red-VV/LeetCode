class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.empty())
            return -1;
        int minIndex = 0;
        int minV = INT_MAX;
        int total = 0;
        for(int i = 0; i < gas.size(); ++i) {
            total += gas[i] - cost[i];
            if(total < minV) {
                minIndex = i;
                minV = total;
            }
        }
        
        return total >= 0 ? (minIndex + 1) % gas.size() : -1;
    }
};
