class Solution {
public:
    bool g(vector<int> *a, vector<int> *b){
        return (abs(a->at(0) - a->at(1)) < abs(b->at(0) - b->at(1)));
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sum = 0;
        int count = 0;
        for(int i =0; i< costs.size(); i++){
            int t= min(costs[i][0] , costs[i][1]);
            sum += t;
            if(t == costs[i][1]){
                count++;
            }
        }
        if(costs.size()/2 == count)
            return sum;
        else{
            
            sort(v.begin() , v.end() , g);
            int difference = costs.size()/2 - count;
            for(int i = 0; i < abs(difference); i++){
                if(difference < 0){
                    sum -= costs[i][0];
                    sum += costs[i][1];
                }
                else{
                    sum += costs[i][0];
                    sum -= costs[i][1];
                }
            }
            return sum;
        }
    }
};