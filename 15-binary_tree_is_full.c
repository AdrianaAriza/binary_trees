#include "binary_trees.h"
/**
 * binary_tree_is_full - ffunction that checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 *
 * Return: If tree is NULL, your function must return 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int h = 1;

	if (!tree)
		return (0);
	if (tree->left && (tree->left->left || tree->left->right))
		h = h && binary_tree_is_full(tree->left);
	if (tree->right && (tree->right->left || tree->right->right))
		h = h && binary_tree_is_full(tree->right);
	if (tree->right && tree->left)
		return (h && 1);
	return (h && 0);
}
