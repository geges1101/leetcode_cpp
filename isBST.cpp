class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root->left && !root->right || !root) return true;
        return isValid(root, NULL, NULL);
    }

    bool isValid(TreeNode* curr, TreeNode* min, TreeNode* max){
        if(!curr) return true;
        if(min && curr->val <= min->val) return false;
        if(max && curr->val >= max->val) return false;

        return isValid(curr->left, min, curr) &&
               isValid(curr->right, curr, max);
    }
};