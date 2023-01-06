#include<bits/stdc++.h>
using namespace std;

double dist(vector<int>& p1, vector<int>& p2){

    double xsquare = pow(p2[0]-p1[0], 2);
    double ysquare = pow(p2[1]-p1[1], 2);

    return xsquare + ysquare;
}

bool check(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4){

    bool basic = dist(p1,p2)>0;
    bool sides = dist(p1,p2)==dist(p2,p3) && dist(p2,p3)==dist(p3,p4) && dist(p3,p4)==dist(p4,p1);
    bool diagonals = dist(p1,p3)==dist(p2,p4);

    return basic && sides && diagonals;
}

bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {

    if(p1==p2 || p1==p3 || p1==p4 || p2==p3 || p2==p4 || p3==p4)
        return false;
    
    bool possibility_1 = check(p1, p2, p3, p4);
    bool possibility_2 = check(p1, p3, p2, p4);
    bool possibility_3 = check(p1, p2, p4, p3);

    return possibility_1 || possibility_2 || possibility_3;
}

int main() {

    vector<int> e1p1={0,0}, e1p2={1,1}, e1p3={1,0}, e1p4={0,1};
    if(validSquare(e1p1, e1p2, e1p3, e1p4)) cout<<"true"<<endl;
    else cout<<"false"<<endl;

    vector<int> e2p1={0,0}, e2p2={1,1}, e2p3={1,0}, e2p4={0,12};
    if(validSquare(e2p1, e2p2, e2p3, e2p4)) cout<<"true"<<endl;
    else cout<<"false"<<endl;

    vector<int> e3p1={1,0}, e3p2={-1,0}, e3p3={0,1}, e3p4={0,-1};
    if(validSquare(e3p1, e3p2, e3p3, e3p4)) cout<<"true"<<endl;
    else cout<<"false"<<endl;

    return 0;
}