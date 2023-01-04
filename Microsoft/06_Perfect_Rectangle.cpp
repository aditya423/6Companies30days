#include<bits/stdc++.h>
using namespace std;

// If it is a valid rectangle, 
// all interior points should have count 0, 
// bottom left most and top right most point should have value 1, 
// and top left most and bottom right most should have count -1. 
// If it is different than this, it is not a perfect rectangle.

bool isRectangleCover(vector<vector<int>>& rectangles) {

    if(rectangles.size() == 1)
        return true;
    
    map<pair<int,int>, int> count;
    for(auto r : rectangles){
        count[{r[0], r[1]}]++;
        count[{r[2], r[3]}]++;
        count[{r[0], r[3]}]--;
        count[{r[2], r[1]}]--;
    } 

    int corners = 0;
    for(auto it=count.begin(); it!=count.end(); it++){
        if(it->second != 0){
            if(abs(it->second) != 1)
                return false;
            corners++;
        }
    }

    return corners == 4;
}

int main() {

    vector<vector<int>> r1 = {
        {1, 1, 3, 3},
        {3, 1, 4, 2},
        {3, 2, 4, 4},
        {1, 3, 2, 4},
        {2, 3, 3, 4}
    };
    if(isRectangleCover(r1)) cout<<"true"<<endl;
    else cout<<"false"<<endl;

    vector<vector<int>> r2 = {
        {1, 1, 3, 3},
        {3, 1, 4, 2},
        {1, 3, 2, 4},
        {2, 2, 4, 4}
    };
    if(isRectangleCover(r2)) cout<<"true"<<endl;
    else cout<<"false"<<endl;

    return 0;
}
