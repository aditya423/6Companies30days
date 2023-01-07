#include<bits/stdc++.h>
using namespace std;

int minimumCardPickup(vector<int>& cards) {
    
    unordered_map<int,int> mp;
    int n=cards.size(), mn=INT_MAX;
    for(int i=0; i<n; i++){

        if(mp.find(cards[i]) != mp.end())
            mn = min(mn, i-mp[cards[i]]+1);

        mp[cards[i]] = i;
    }
    
    if(mn == INT_MAX)
        return -1;

    return mn;
}

int main() {

    vector<int> c1 = {3, 4, 2, 3, 4, 7};
    cout<<minimumCardPickup(c1)<<endl;

    vector<int> c2 = {1, 0, 5, 3};
    cout<<minimumCardPickup(c2)<<endl;

    return 0;
}