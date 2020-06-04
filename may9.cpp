bool checkStraightLine(vector<vector<int>>& v) {
        // y = mx + c;
        // m = y2-y1 / x2 - x1;
        if(v.size()  == 0){
            return false;
        }
        if(v.size() < 3 ){
            return true;
        }
        
        int y2 = v[1][1] , y1 = v[0][1];
        int x2 = v[1][0] , x1 = v[0][0];
        if(x1 == x2){
            for(int i = 0; i < v.size(); i++){
                if(x1 != v[i][0]){
                    return 0;
                }
            }
            return 1;
        }
        float m = (y2 - y1) / (x2 - x1);
        for(int i = 2; i < v.size(); i++){
            x2 = v[i][0];
            y2 = v[i][1];
            float mm = (y2 - y1) / (x2 - x1);
            if(mm != m){
                return 0;
            }
        }
        return 1;
    }