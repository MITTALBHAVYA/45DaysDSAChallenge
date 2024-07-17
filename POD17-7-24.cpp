//for detailed explanation visit
https://leetcode.com/problems/delete-nodes-and-return-forest/solutions/5491937/100-easy-solution-post-order-traversal-easy-to-apply/
/*

*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;
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
    TreeNode* postorder(TreeNode* node, unordered_set<int>& to_del, vector<TreeNode*>& ans) {
        if(!node) return nullptr;
        node->left = postorder(node->left, to_del, ans);
        node->right = postorder(node->right, to_del, ans);
        if(to_del.find(node->val) != to_del.end()) {
            if(node->left){
                ans.push_back(node->left);
            }
            if(node->right){
                ans.push_back(node->right);
            } 
            return nullptr;
        }
        return node;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> to_del(to_delete.begin(), to_delete.end());
        if(postorder(root, to_del, ans)){
            ans.push_back(root);
        }
        return ans;
    }
};
