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
    bool isSymmetric(TreeNode *root) {
        unordered_map<int, vector<int> > helper;
        vector<int> flattened = flatten_tree(root, 1, helper);
    
        bool tree_pal = is_palindrome(flattened);
        if ( tree_pal == false ) return false;
        
        for ( auto it = helper.begin(); it != helper.end(); ++it ) {
            if ( is_palindrome(it->second) == false ) return false;
        }
        
        return true;
    }
    
    bool is_palindrome(vector<int> nums) {
        vector<int> reversed_nums = nums;
        reverse(reversed_nums.begin(), reversed_nums.end());
        return reversed_nums == nums;
    } 
    
    vector<int> flatten_tree(TreeNode *root, int level, unordered_map<int, vector<int>> &helper) {
        vector<int> result;
        if ( root == NULL ) {
            result.push_back(-1);
            return result;
        }
        if ( helper.find(level) == helper.end() ) {
            vector<int> nodes;
            nodes.push_back(root->val);
            helper[level] = nodes;
        } else {
            helper[level].push_back(root->val);
        }
        
        if ( root->left == NULL && root->right == NULL ) {
            result.push_back(root->val);
            return result;
        } 
        
        vector<int> result_left = flatten_tree(root->left,level+1, helper);
        vector<int> result_right = flatten_tree(root->right, level+1, helper);
        
        result_left.push_back(root->val);
        result_left.insert(result_left.end(), result_right.begin(), result_right.end());
        return result_left;
    }
};
