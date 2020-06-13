#include <algorithm>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {

    std::vector<pair<int,int>> v1;
    v1.push_back({1,2});
    v1.push_back({2,0});
    v1.push_back({2,3});
    v1.push_back({3,4});
    v1.push_back({4,5});
    v1.push_back({5,6});
    v1.push_back({6,7});

    std::vector<pair<int,int>> v2;
    v2.push_back({2,8});
    v2.push_back({2,3});
    v2.push_back({4,5});
    v2.push_back({6,7});
    v2.push_back({8,9});

    // Ranges must be sorted!
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());

    std::vector<pair<int,int>> res; // Will contain the symmetric difference
    std::set_symmetric_difference(v1.begin(), v1.end(), 
                                  v2.begin(), v2.end(), 
                                  std::back_inserter(res));
    
    // Copy result to the output
    // std::copy(res.begin(), res.end(), std::ostream_iterator<int>(cout, " "));
    // Prints "1 3 5"
    for(int i = 0; i<res.size(); i++){
        cout << res[i].first << " " << res[i].second << endl;
    }
    return 0;
}