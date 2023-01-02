#include<bits/stdc++.h>
using namespace std;

int maxRotateFunction(vector<int>& nums) {

    // TLE 

    // int n=nums.size(), mx=INT_MIN;
    // for(int k=0; k<n; k++){
    //     int sum = 0;
    //     for(int i=0; i<n; i++){
    //         sum += i*nums[(i+k)%n];
    //     }
    //     mx = max(mx, sum);
    // }
    // return mx;


    // Optimized

    // sum = 1A + 1B + 1C + 1D

    // f(0) = 0A + 1B + 2C + 3D
    // f(1) = 0D + 1A + 2B + 3C

    // f(1) - f(0) = 1A + 1B + 1C - 3D = (1A + 1B + 1C + 1D) - 4D = sum - n*nums[n-1]
    // f(1) = f(0) + sum - n*nums[n-1]

    int n=nums.size(), f=0, sum=0;
    for(int i=0; i<n; i++){
        sum += nums[i];
        f += i*nums[i];
    }
    int mx = f;
    for(int k=n-1; k>0; k--){
        f = f + sum - n*nums[k];
        mx = max(mx, f);
    }
    return mx;
}

// TC --> O(N)
// SC --> O(1)

int main() {

    vector<int> nums = {4,3,2,6};

    cout<<maxRotateFunction(nums)<<endl;

    return 0;
}