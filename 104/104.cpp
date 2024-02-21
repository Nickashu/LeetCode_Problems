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
    int depthRight=0, depthLeft=0;
    int maxDepth(TreeNode* root) {
        if(root != NULL){
            checkDepthRight(root->left, 2);
            checkDepthLeft(root->right, 2);
            if(depthRight == 0 && depthLeft == 0)
                return 1;
            return max(depthLeft, depthRight);
        }
        else
            return 0;
    }

    void checkDepthLeft(TreeNode *root, int currentDepth){
        if(root != NULL){
            depthLeft = max(currentDepth, depthLeft);
            checkDepthLeft(root->left, currentDepth+1);
            checkDepthLeft(root->right, currentDepth+1);
        }
    }

    void checkDepthRight(TreeNode *root, int currentDepth){
        if(root != NULL){
            depthRight = max(currentDepth, depthRight);
            checkDepthLeft(root->left, currentDepth+1);
            checkDepthLeft(root->right, currentDepth+1);
        }
    }
};