#include "binary_trees.h"
/**
 * binary_tree_is_full - function that checks if a binary tree is full
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
/**
 * bt_height - function that measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0
 */
size_t bt_height(const binary_tree_t *tree)
{
	size_t hl = 0, hr = 0;

	if (!tree)
		return (0);
	if (tree->right)
		hr = 1 + bt_height(tree->right);
	if (tree->left)
	{
		hl = 1 + bt_height(tree->left);
	}
	if (hr > hl)
		return (hr);
	return (hl);
}
/**
 * binary_tree_leaves - function that counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the number of leaves
 *
 * Return: If tree is NULL, your function must return 0
 */
size_t _leaves(const binary_tree_t *tree)
{
	size_t hl = 0, hr = 0, h = 0;

	if (!tree)
		return (0);
	if (!(tree->left && tree->right))
		return (1);
	if (tree->left)
	{
		if (tree->left->left || tree->left->right)
			h = h + _leaves(tree->left);
		else
		{
			if (tree->right && tree->left)
				return (hl + 2);
			else
				return (hl++);
		}
	}
	if (tree->right)
	{
		if (tree->right->left || tree->right->right)
			h = h + _leaves(tree->right);
		else
		{
			if (tree->right && tree->left)
				return (hr + 2);
			else
				return (hr++);
		}
	}
	return (h);
}
/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: If tree is NULL, your function must return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	float f = binary_tree_is_full(tree), leaves = 0, h = 0, p = 1;


	if (!tree)
		return (0);
	if (f)
	{
		if (bt_height(tree->left) == bt_height(tree->right))
		{
			h = bt_height(tree);
			while (h)
			{
				p = p * 2;
				h--;
			}
			leaves = _leaves(tree);
			if (p == leaves)
				return (1);
		}
	}
	return (0);
}
