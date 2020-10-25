//question link: https://leetcode.com/problems/minimum-depth-of-binary-tree/
//code:

#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        
        int leftH = minDepth(root->left);
        int rightH = minDepth(root->right);

        int ans = 1;
        if(leftH == 0) {
            ans += rightH;
        } else if(rightH == 0) {
            ans += leftH;
        } else {
            ans += min(leftH, rightH);
        }

        return ans;
    }
};