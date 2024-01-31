#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> vectorValues;
    vector<int> inorderTraversal(TreeNode* root) {
        fillVector(root);
        return vectorValues;
    }

    void fillVector(TreeNode* root) {
        if(root != NULL){
            if(root->left == NULL){
                vectorValues.push_back(root->val);
                if(root->right != NULL)
                    inorderTraversal(root->right);
            }
            else{
                inorderTraversal(root->left);
                vectorValues.push_back(root->val);
                if(root->right != NULL)
                    inorderTraversal(root->right);
            }
        }
    }
};