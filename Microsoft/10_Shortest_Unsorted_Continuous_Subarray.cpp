#include<bits/stdc++.h>
using namespace std;

int findUnsortedSubarray(vector<int>& nums) {

    // TLE --> Brute Force

    // int l=nums.size(), r=0;
    // for(int i=0; i<nums.size()-1; i++){
    //     for(int j=i+1; j<nums.size(); j++){
    //         if(nums[j] < nums[i]){
    //             r = max(r, j);
    //             l = min(l, i);
    //         }
    //     }
    // }
    // return (r-l<0) ? 0 : r-l+1;

    // ACCEPTED --> Using Sorting

    vector<int> snums(nums.begin(), nums.end());
    sort(snums.begin(), snums.end());
    int l=nums.size(), r=0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i] != snums[i]){
            r = max(r, i);
            l = min(l, i);
        }
    }
    return (r-l<0) ? 0 : r-l+1; 
}

int main() {

    vector<int> nums = {2,6,4,8,10,9,15};

    cout<<findUnsortedSubarray(nums)<<endl;

    return 0;
}