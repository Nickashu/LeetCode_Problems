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
    bool isSymmetric(TreeNode* root) {
        if(root->left != NULL){
            if(root->right != NULL)
                return compareTrees(root->left, root->right);
            return false;
        }
        else{
            if(root->right != NULL)
                return false;
            return true;
        }
    }

    bool compareTrees(TreeNode *root1, TreeNode *root2){
        if(root1 == NULL){
            if(root2 == NULL)
                return true;
            return false;
        }
        else{
            if(root2 == NULL)
                return false;
            else{
                if(root1->val == root2->val)
                    return (compareTrees(root1->left, root2->right) && compareTrees(root1->right, root2->left));
                return false;
            }
        }
    }
};