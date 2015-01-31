#include <stdlib.h>
#include <algorithm>
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        return check_height(root) == -1 ? false : true;
    }
    
    int check_height(TreeNode *node) {
        if ( node == NULL ) return 0;
        
        int height_left = check_height(node->left);
        int height_right = check_height(node->right);
        
        if ( height_left == -1 || height_right == -1 || abs(height_left-height_right) > 1 ) {
            return -1;
        }
        
        return max(height_left, height_right) + 1;  
    }
};
