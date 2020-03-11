#include "binary_trees.h"
/**
 * binary_tree_balance - function that measures
 * the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: If tree is NULL, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t hl = 0, hr = 0;

	if (!tree)
		return (0);
	if (tree->right)
		hr = 1 + binary_tree_balance(tree->right);
	if (tree->left)
	{
		hl = 1 + binary_tree_balance(tree->left);
	}
	return (hl - hr);
}
