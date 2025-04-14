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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;

        vector<int> result;
        q.push(root);

        while(!q.empty()){
            int count = q.size(); // level size

            for(int i=0; i<count; i++){
                TreeNode* current = q.front(); 
                q.pop();
                
                if(i == count - 1){
                    result.push_back(current->val);
                }

                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
        }
        return result;  
    }
};