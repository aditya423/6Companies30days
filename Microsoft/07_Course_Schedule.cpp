#include<bits/stdc++.h>
using namespace std;

// Detect if a graph has a cycle

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

    // make a graph
    vector<int> adj[numCourses];
    for(auto it : prerequisites)
        adj[it[1]].push_back(it[0]);
    
    vector<int> vis(numCourses, 0);
    for(int i=0; i<numCourses; i++){
        for(auto j : adj[i])
            vis[j]++;
    }

    queue<int> q;
    for(int node=0; node<numCourses; node++){
        if(vis[node] == 0)
            q.push(node);
    }

    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto i : adj[node]){
            vis[i]--;
            if(vis[i] == 0)
                q.push(i);
        }
    }
    
    return ans.size()==numCourses;
}

int main() {

    vector<vector<int>> p1 = {{1,0}};
    if(canFinish(2, p1)) cout<<"true"<<endl;
    else cout<<"false"<<endl;

    vector<vector<int>> p2 = {{1,0},{0,1}};
    if(canFinish(2, p2)) cout<<"true"<<endl;
    else cout<<"false"<<endl;

    return 0;
}