/* Given the root of a binary tree, return the preorder traversal of its nodes' values. */

#include "../leetcode.h"
#include <stdlib.h>

int count_nodes(struct TreeNode *node)
{
    if (!node)
        return (0);
    int left_count = count_nodes(node->left);
    int right_count = count_nodes(node->right);
    return (left_count + right_count + 1);
}

void fill_arr(struct TreeNode *node, int *arr, int *i)
{
    if (!node)
        return;
    arr[*i] = node->val;
    (*i)++;
    fill_arr(node->left, arr, i);
    fill_arr(node->right, arr, i);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int tree_size = count_nodes(root);
    *returnSize = tree_size;
    int i = 0;
    int *arr = malloc(sizeof(int) * (tree_size + 1));
    fill_arr(root, arr, &i);
    return (arr);
}

int main(void)
{
    struct TreeNode n4 = {4, NULL, NULL};
    struct TreeNode n2 = {2, &n4, NULL};
    struct TreeNode n3 = {3, NULL, NULL};
    struct TreeNode n1 = {1, &n2, &n3};

    int returnSize = 0;
    int *ast = preorderTraversal(&n1, &returnSize);

    printf("Preorder traversal: ");
    for (int i = 0; i < returnSize; i++)
        printf("%d ", ast[i]);
    printf("\n");

    free(ast);
    return (0);
}