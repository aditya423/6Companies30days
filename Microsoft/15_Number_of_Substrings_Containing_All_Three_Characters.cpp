#include<bits/stdc++.h>
using namespace std;

// s = "abcabc"

// j=2 --> "abc"
// j=3 --> "abca" "bca"
// j=4 --> "abcab" "bcab" "cab"
// j=5 --> "abcabc" "bcabc" "cabc" "abc"

// In this example, 
// we are getting all counts>0 in each iteration after j=2
// so one new string gets added in answer in every step
// answer = previous_strings + 1_new_string

int numberOfSubstrings(string s) {

    vector<int> count(3, 0);
    int i=0, ans=0;
    for(int j=0; j<s.length(); j++){
        count[s[j]-'a']++;
        while(count[0] && count[1] && count[2])
            count[s[i++]-'a']--;
        ans += i;
    }

    return ans;
}

int main() {

    cout<<numberOfSubstrings("abcabc")<<endl;

    cout<<numberOfSubstrings("aaacb")<<endl;

    return 0;
}