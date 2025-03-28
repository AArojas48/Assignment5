#include <iostream>
#include <climits>

using namespace std;

/* A path in a binary tree is a sequence of nodes where each pair of adjacent
 * nodes in the sequence has an edge connecting them. A node can only
 * appear in the sequence at most once. Note that the path does not
 * need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

DFS with return values: Use Depth-First Search (DFS) to calculate
the maximum sum at each node.
Path splitting: At each node, decide whether to continue the path
through a child or start a new path.
Global maximum tracking: Maintain a variable to track the highest
path sum encountered.
Edge cases: Handle cases with all negative values, single-node
trees, or long linear trees.
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxSum;

int DFS(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int Max_left = max(0, DFS(root->left));
    int Max_right = max(0, DFS(root->right));

    maxSum = max(maxSum, Max_left + Max_right + root->val);

    return root->val + max(Max_left, Max_right);
}

int MaxPath(TreeNode* root) {
    maxSum = INT_MIN;
    DFS(root);

    return maxSum;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    cout << "Output: " << MaxPath(root) << endl;

    return 0;
}