
#include "binary_trees.h"
/**
 * is_full - ffunction that checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 *
 * Return: If tree is NULL, your function must return 0
 */
int is_full(const binary_tree_t *tree)
{
	int h = 1;

	if (!tree)
		return (0);
	if (tree->left && (tree->left->left || tree->left->right))
		h = h && is_full(tree->left);
	if (tree->right && (tree->right->left || tree->right->right))
		h = h && is_full(tree->right);
	if ((tree->right && tree->left) || (!tree->right && !tree->left))
		return (h && 1);
	return (h && 0);
}
/**
 * binary_tree_is_complete - goes through a binary tree using
 * level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 *
 * Return:
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int c = 1;

	if (is_full(tree) == 1)
		return (c);
	c = 0;
	return (c);
}
