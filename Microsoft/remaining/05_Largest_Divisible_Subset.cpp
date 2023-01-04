#include<bits/stdc++.h>
using namespace std;

// contiguous                + ordered   --> subarray
// contiguous/non-contiguous + ordered   --> subsequence
// contiguous/non-contiguous + unordered --> subset


// BRUTE-FORCE

// vector<int> solve(vector<int>& nums, int start){

//     if(start >= nums.size())
//         return {};
//     vector<int> ans;
//     for(int next=start+1; next<nums.size(); next++){
//         if(nums[next]%nums[start] != 0)
//             continue;
//         vector<int> res = solve(nums, next);
//         if(res.size() > ans.size())
//             ans = res;
//     }
//     ans.push_back(nums[start]);
//     return ans;
// }

// vector<int> largestDivisibleSubset(vector<int>& nums) {

//     vector<int> ans;
//     sort(nums.begin(), nums.end());  
//     for(int i=0; i<nums.size(); i++){
//         vector<int> res = solve(nums, i);
//         if(res.size() > ans.size())
//             ans = res;
//     }
//     return ans;  
// }

// TC --> O(n*2ⁿ)


// MEMOIZATION

unordered_map<int, vector<int>> dp;
vector<int> solve(vector<int>& nums, int start){

    if(start >= nums.size())
        return {};
    if(dp.count(start))
        return dp[start];
    vector<int> ans;
    for(int next=start+1; next<nums.size(); next++){
        if(nums[next]%nums[start] != 0)
            continue;
        vector<int> res = solve(nums, next);
        if(res.size() > dp[start].size())
            dp[start] = res;
    }
    dp[start].push_back(nums[start]);
    return dp[start];
}

vector<int> largestDivisibleSubset(vector<int>& nums) {

    vector<int> ans;
    sort(nums.begin(), nums.end());  
    for(int i=0; i<nums.size(); i++){
        vector<int> res = solve(nums, i);
        if(res.size() > ans.size())
            ans = res;
    }
    return ans;  
}

int main() {

    vector<int> nums1 = {1,2,3};
    vector<int> ans1 = largestDivisibleSubset(nums1);
    for(int i : ans1)
        cout<<i<<" ";
    cout<<endl;

    vector<int> nums2 = {1,2,4,8};
    vector<int> ans2 = largestDivisibleSubset(nums2);
    for(int i : ans2)
        cout<<i<<" ";
    cout<<endl;

    return 0;
}