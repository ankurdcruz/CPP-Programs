//question link: https://leetcode.com/problems/serialize-and-deserialize-bst/
//code:

#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) {
            return "";
        }
        string left = serialize(root->left);
        string right = serialize(root->right);
        string curr = to_string(root->val);
        return curr+'x'+left+'x'+right;
    }
    TreeNode* addToBST(TreeNode*root, int data) {
        TreeNode* currNode = new TreeNode(data);
        if(root == NULL) {
            return currNode;
        }
        
        if(data >= root->val) {
            root->right = addToBST(root->right, data);
        } else {
            root->left = addToBST(root->left, data);
        }
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        string currData = "";
        for(char ch: data) {
            if(ch == 'x' && currData != "") {
                int val = stoi(currData);
                root = addToBST(root, val);
                currData = "";
            } else if(ch != 'x') {
                currData = currData + ch;
            }
        }
        return root;
    }
};

