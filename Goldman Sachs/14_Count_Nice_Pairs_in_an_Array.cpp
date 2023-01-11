#include<bits/stdc++.h>
using namespace std;

int rev(int n){

    int ans = 0;
    while(n){
        int rem = n%10;
        ans = ans*10 + rem;
        n /= 10;
    }

    return ans;
}

int countNicePairs(vector<int>& nums) {

    int ans=0, mod=1e9+7;
    unordered_map<int,int> mp;
    for(auto num : nums)
        ans = (ans + mp[num-rev(num)]++) % mod;
        
    return ans;
}

int main() {

    vector<int> nums1 = {42,11,1,97};
    cout<<countNicePairs(nums1)<<endl;

    vector<int> nums2 = {13,10,35,24,76};
    cout<<countNicePairs(nums2)<<endl;

    return 0;
}