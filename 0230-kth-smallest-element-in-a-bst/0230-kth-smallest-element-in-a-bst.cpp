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
    vector<int> res;
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;


        inorder(root);

        for(int i=0; i<res.size(); i++){
            cout<<res[i]<<endl;
        }
        return res[k-1];

    }

private:
    void inorder(TreeNode* root){
        if(!root) return;

        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);

    }
};
