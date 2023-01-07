#include<bits/stdc++.h>
using namespace std;

int numberOfBoomerangs(vector<vector<int>>& points) {

    int ans = 0;
    unordered_map<int,int> mp;
    for(int i=0; i<points.size(); i++){
        for(int j=0; j<points.size(); j++){

            int xsquare = pow(points[j][0]-points[i][0], 2); 
            int ysquare = pow(points[j][1]-points[i][1], 2); 
            int d = xsquare + ysquare;
            ans += 2*mp[d]++;
        }
        mp.clear();
    }      

    return ans;
}

int main() {

    vector<vector<int>> points = {{0,0}, {1,0}, {2,0}};

    cout<<numberOfBoomerangs(points)<<endl;

    return 0;
}