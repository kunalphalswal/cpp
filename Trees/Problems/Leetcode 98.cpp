//Validate Binary Search Tree: Return whether the given tree is bst or not.
#define ll long long
class Solution {
public:
    bool validate(TreeNode* root, ll mn, ll mx){
        if(!root)return true;
        if(root->val<=mn || root->val>=mx)return false;
        return validate(root->left,mn,root->val) && validate(root->right, root->val,mx);
    }
    bool isValidBST(TreeNode* root) {
        return validate(root,LONG_MIN,LONG_MAX);
    }
};