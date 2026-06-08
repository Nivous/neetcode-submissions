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
    bool sameTrees(TreeNode *t1, TreeNode *t2) {
        if (t1 == nullptr && t2 == nullptr)
            return true;
        if ((t1 == nullptr && t2 != nullptr) || (t1 != nullptr && t2 == nullptr))
            return false;
        if (t1->val != t2->val)
            return false;
        return sameTrees(t1->left, t2->left) && sameTrees(t1->right, t2->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr)
            return true;
        if (root == nullptr)
            return false;
        bool answer;
        if (root->val == subRoot->val)
            answer = sameTrees(root->left, subRoot->left) && sameTrees(root->right, subRoot->right);
        return answer || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
