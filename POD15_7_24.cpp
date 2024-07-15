//for detailed explanation visite: 
// https://leetcode.com/problems/create-binary-tree-from-descriptions/solutions/5479572/very-easy-solution-o-n-easy-to-understand-detailed-explanation/
//here the solution

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
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>mp;
        unordered_set<int>prt,cld;
        int n = descriptions.size();
        for(int i=0;i<n;i++){
            int parent=descriptions[i][0];
            int child=descriptions[i][1];
            int isLeft=descriptions[i][2];
            prt.insert(parent);
            cld.insert(child);
            if(mp.find(parent)==mp.end()){
                TreeNode* temp = new TreeNode(parent);
                mp[parent]=temp;
            }
            if(mp.find(child)==mp.end()){
                TreeNode* temp = new TreeNode(child);
                mp[child]=temp;
            }
            if(isLeft){
                mp[parent]->left=mp[child];
            }
            else{
                mp[parent]->right=mp[child];
            }
        }
        int forefather=0;
        for(auto it : prt){
            if(cld.find(it)==cld.end()){
                forefather=it;
            }
        }
        return mp[forefather];
    }
};