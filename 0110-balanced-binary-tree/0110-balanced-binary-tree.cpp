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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        int lTree = height(root->left);
        int rTree = height(root->right);

        if(abs(lTree-rTree) > 1){
            return false;
        }
        //checks the subtrees are also balanced and tree is not just overall height balanced/
        return isBalanced(root->left) && isBalanced(root->right);

    }
private:
    int height(TreeNode* root){
        if(!root) return 0;

        int h = 1 + max(height(root->left), height(root->right));
        return h;
    }
};