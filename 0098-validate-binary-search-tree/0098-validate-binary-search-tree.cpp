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
    vector<int> v;
    bool isValidBST(TreeNode* root) {
        if(!root) return false;
        inorder(root);
       
        int l=0;
        int r=1;

        while(l<r && r<v.size()){
            if(v[l]>=v[r]){
                return false;
            }
            l++;
            r++;
        }

        return true;
        
    }
private:
    void inorder(TreeNode* root){//sorts BST in ascending order
        if(!root) return;

        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);

    }
};