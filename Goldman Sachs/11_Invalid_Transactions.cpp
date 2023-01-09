#include<bits/stdc++.h>
using namespace std;

vector<string> invalidTransactions(vector<string>& transactions) {

    int n = transactions.size();
    vector<string> name;
    vector<int> time;
    vector<int> amount;
    vector<string> city;
    vector<string> ans;

    for(auto transaction : transactions){
        stringstream ss(transaction);
        vector<string> data;
        string str;
        while(getline(ss, str, ','))
            data.push_back(str);
        name.push_back(data[0]);
        time.push_back(stoi(data[1]));
        amount.push_back(stoi(data[2]));
        city.push_back(data[3]);
    }     

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j)
                continue;
            if(name[i]==name[j] && abs(time[i]-time[j])<=60 && city[i]!=city[j]){
                ans.push_back(transactions[i]);
                break;
            }
            else if(amount[i]>1000){
                ans.push_back(transactions[i]);
                break;
            }
        }
    }

    return ans;
}

int main() {

    vector<string> t1 = {"alice,20,800,mtv", "alice,50,100,beijing"};
    vector<string> a1 = invalidTransactions(t1);
    for(auto it : a1)
        cout<<it<<" ";
    cout<<endl;
    vector<string> t2 = {"alice,20,800,mtv", "alice,50,1200,mtv"};
    vector<string> a2 = invalidTransactions(t2);
    for(auto it : a2)
        cout<<it<<" ";
    cout<<endl;

    return 0;
}