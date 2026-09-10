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
int findsum(TreeNode* root,int &cnt){
    if(root==nullptr) return 0;
    cnt++;
    int ls=findsum(root->left,cnt);
    int rs=findsum(root->right,cnt);
    return ls+rs+root->val;
}
    int averageOfSubtree(TreeNode* root) {
        if(root==nullptr) return 0;
        int cnt=0,result=0;
        int sum=findsum(root,cnt);
        if(root->val== sum / cnt) result+=1;
        result+=averageOfSubtree(root->left);
        result+=averageOfSubtree(root->right);
        return result;
    }
};