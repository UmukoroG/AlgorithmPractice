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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if(!root) return false;

        if(sameTree(root, subRoot)==true) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);        
    }

private:
    bool sameTree(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if(!p && q) return false;
        if(p && !q) return false;

        if(p->val == q->val){
            return sameTree(p->left, q->left) && sameTree(p->right, q->right);
        }
        return false;
        
    }
};