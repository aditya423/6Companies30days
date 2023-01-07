#include<bits/stdc++.h>
using namespace std;

// contiguous                + ordered   --> subarray
// contiguous/non-contiguous + ordered   --> subsequence
// contiguous/non-contiguous + unordered --> subset

// Just check that the frequency of previous elements must be less than current element

bool isPossible(vector<int>& nums) {

    unordered_map<int,int> mp;
    for(auto num : nums)
        mp[num]++;
    
    for(auto num : nums){
        if(mp[num] == 0)
            continue;

        int curr=num, freq=mp[num], cnt=0;
        while(mp[curr] >= freq){
            freq = mp[curr++]--;
            cnt++;
        }
        if(cnt < 3)
            return false;
    }

    return true;
}

// TC --> O(n)
// SC --> O(n)

int main() {

    vector<int> n1 = {1,2,3,3,4,5};
    if(isPossible(n1)) cout<<"true"<<endl;
    else cout<<"false"<<endl;

    vector<int> n2 = {1,2,3,3,4,4,5,5};
    if(isPossible(n2)) cout<<"true"<<endl;
    else cout<<"false"<<endl;

    vector<int> n3 = {1,2,3,4,4,5};
    if(isPossible(n3)) cout<<"true"<<endl;
    else cout<<"false"<<endl;

    return 0;
}
