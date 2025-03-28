#include <iostream>
using namespace std;


/* Given the root of a binary search tree, return the minimum absolute difference
 * between the values of any two different nodes in the tree.
 *
 * Inorder traversal: Perform an inorder traversal to obtain a sorted sequence
 * of values.
 * Adjacent comparison: The minimum absolute difference is always between two adjacent
 * values in a sorted BST.
 * Optimized tracking: Keep track of the previous node value during
 * traversal to avoid storing all values.
 * Edge cases: Handle cases where the tree has only two nodes or contains duplicate
 * values
 */
//Binary Tree structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void inorder(TreeNode *root, int& prev, int& diff) {
    if (!root) {
        return;
    }
    inorder(root->left, prev, diff);

    if (prev != -1) {
        diff = min(diff, abs(root->val - prev));
    }
    prev = root->val;

    inorder(root->right, prev, diff);
}

int MinDifference(TreeNode *root) {
    int diff = INT_MAX;
    int prev = INT_MIN;

    inorder(root, prev, diff);

    return diff;
}

int main() {
    auto *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    cout << "Output: ";
    cout << MinDifference(root) << endl;
    return 0;
}
