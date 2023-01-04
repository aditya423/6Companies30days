#include<bits/stdc++.h>
using namespace std;

int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        
}

int main() {

    vector<vector<int>> edges = {{0,1}, {1,2}, {1,3}, {3,4}};
    int bob = 3;
    vector<int> amount = {-2, 4, 2, -4, 6};

    cout<<mostProfitablePath(edges, bob, amount)<<endl;

    return 0;
}