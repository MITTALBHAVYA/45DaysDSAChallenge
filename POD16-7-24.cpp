//for detailed explanation visit
/*
https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/solutions/5483471/easy-solution-detailed-explanation-93-7/
*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    bool findPath(TreeNode* root, int value, string& path) {
        if (root == NULL) {
            return false;
        }
        if (root->val == value) {
            return true;
        }
        path.push_back('L');
        if (findPath(root->left, value, path)) {
            return true;
        }
        path.pop_back();
        
        path.push_back('R');
        if (findPath(root->right, value, path)) {
            return true;
        }
        path.pop_back();
        
        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath = "";
        string destPath = "";
        
        findPath(root, startValue, startPath);
        findPath(root, destValue, destPath);
        
        int i = 0;
        while (i < startPath.size() && i < destPath.size() && startPath[i] == destPath[i]) {
            ++i;
        }
        
        string result = "";
        for (int j = i; j < startPath.size(); ++j) {
            result += 'U';
        }
        for (int j = i; j < destPath.size(); ++j) {
            result += destPath[j];
        }
        
        return result;
    }
};
