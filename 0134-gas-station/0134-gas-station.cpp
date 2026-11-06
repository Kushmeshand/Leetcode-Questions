class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tank = 0;
        int ind = 0;
        int sumGas = accumulate(begin(gas),end(gas),0);
        int sumCost = accumulate(begin(cost),end(cost),0);
        if(sumGas < sumCost) return -1;
        for(int i = 0; i < n; i++){
            tank = tank - cost[i] + gas[i];
            if(tank < 0){
               tank = 0;
               ind = i+1;
            }            
            
        }
        return ind;
    }
};