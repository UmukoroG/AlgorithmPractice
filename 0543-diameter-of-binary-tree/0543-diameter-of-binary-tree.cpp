/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int lTree=treeHeight(root->left);
        int rTree=treeHeight(root->right);
        int diameter = lTree+rTree;
        //this checks for maximum diameter between the left or the right subtree
        int sub = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
        int result = max(diameter, sub);
        return result;
    }
private:
    int treeHeight(TreeNode* root){
        if(!root) return 0;
        int height = 1 + max(treeHeight(root->left),treeHeight(root->right));
        return height;
    }
};