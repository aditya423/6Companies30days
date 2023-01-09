#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

void preorder(TreeNode* root, vector<int>& ans){

    if(root == NULL)
        return;
    
    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}

vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {

    vector<int> ans;
    preorder(root1, ans);
    preorder(root2, ans);  
    sort(ans.begin(), ans.end());
    return ans;  
}

int main() {

    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);

    //      2
    //     / \ 
    //    1   4

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(0);
    root2->right = new TreeNode(3);

    //      2
    //     / \ 
    //    1   4

    vector<int> ans = getAllElements(root1, root2);
    for(auto it : ans)
        cout<<it<<" ";
    cout<<endl;

    return 0;
}