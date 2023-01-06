#include<bits/stdc++.h>
using namespace std;

int maxPoints(vector<vector<int>>& points) {

    int n = points.size();
    if(n == 1)
        return 1;

    int ans = 0;
    for(int i=0; i<n; i++){

        unordered_map<double,int> mp;
        for(int j=i+1; j<n; j++){

            double x1 = points[i][0];
            double x2 = points[j][0];
            double y1 = points[i][1];
            double y2 = points[j][1];

            double slope;
            if((x2-x1) == 0)
                slope = INT_MAX;
            else 
                slope = (y2-y1)/(x2-x1);
                
            mp[slope]++;
            ans = max(ans, mp[slope]+1);
        }
    } 

    return ans;
}

// TC --> O(n²)
// SC --> O(n)

int main() {

    vector<vector<int>> p1 = {{1,1}, {2,2}, {3,3}};
    cout<<maxPoints(p1)<<endl;

    vector<vector<int>> p2 = {{1,1}, {3,2}, {5,3}, {4,1}, {2,3}, {1,4}};
    cout<<maxPoints(p2)<<endl;

    return 0;
}