#include<bits/stdc++.h>
using namespace std;

int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

    // sort projects as per capital
    int n = profits.size();
    vector<pair<int,int>> projects;
    for(int i=0; i<n; i++)
        projects.push_back({capital[i], profits[i]});
    sort(projects.begin(), projects.end());

    // add up maximum profit using pq
    priority_queue<int> pq;
    int i = 0;
    while(k--){
        while(i<n && projects[i].first<=w)
            pq.push(projects[i++].second);
        if(pq.empty())
            break;
        w += pq.top();
        pq.pop();
    }

    return w;
}

int main() {

    int k1 = 2;
    int w1 = 0;
    vector<int> profits1 = {1, 2, 3};
    vector<int> capital1 = {0, 1, 1};
    cout<<findMaximizedCapital(k1, w1, profits1, capital1)<<endl;

    int k2 = 3;
    int w2 = 0;
    vector<int> profits2 = {1, 2, 3};
    vector<int> capital2 = {0, 1, 2};
    cout<<findMaximizedCapital(k2, w2, profits2, capital2)<<endl;

    return 0;
}