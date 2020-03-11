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
	int hl = 0, hr = 0;

	if (!tree)
		return (0);
	if (tree->right)
		hr = binary_tree_height(tree->right);
	else
		hr = -1;
	if (tree->left)
		hl = binary_tree_height(tree->left);
	else
		hl = -1;
	return (hl - hr);
}
/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t hl = 0, hr = 0;

	if (!tree)
		return (0);
	if (tree->right)
		hr = 1 + binary_tree_height(tree->right);
	if (tree->left)
	{
		hl = 1 + binary_tree_height(tree->left);
	}
	if (hr > hl)
		return (hr);
	return (hl);
}
