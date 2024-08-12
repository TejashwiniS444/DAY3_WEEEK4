#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new tree node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Helper function to calculate the maximum path sum
int helper(struct TreeNode* node, int* max_sum) {
    if (node == NULL) {
        return 0;
    }

    // Recursively get the maximum path sum from the left and right subtrees
    int left_max = helper(node->left, max_sum);
    int right_max = helper(node->right, max_sum);

    // Calculate the maximum path sum that includes the current node
    int max_single = node->val + (left_max > right_max ? left_max : right_max);
    int max_top = node->val + left_max + right_max;

    // Update the global maximum path sum
    if (max_single > *max_sum) {
        *max_sum = max_single;
    }
    if (max_top > *max_sum) {
        *max_sum = max_top;
    }

    // Return the maximum sum that can be extended to the parent node
    return max_single > node->val ? max_single : node->val;
}

// Function to find the maximum path sum
int maxPathSum(struct TreeNode* root) {
    int max_sum = INT_MIN;
    helper(root, &max_sum);
    return max_sum;
}

int main() {
    struct TreeNode* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(10);
    root->left->left = newNode(20);
    root->left->right = newNode(1);
    root->right->right = newNode(-25);
    root->right->right->left = newNode(3);
    root->right->right->right = newNode(4);

    printf("Maximum path sum is %d\n", maxPathSum(root));

    return 0;
}
