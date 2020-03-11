#include "binary_trees.h"
/**
 * binary_tree_leaves - function that counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the number of leaves
 *
 * Return: If tree is NULL, your function must return 0
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t hl = 0, hr = 0, h = 0;

	if (!tree)
		return (0);
	if (!(tree->left && tree->right))
		return (1);
	if (tree->left)
	{
		if (tree->left->left || tree->left->right)
			h = h + binary_tree_leaves(tree->left);
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
			h = h + binary_tree_leaves(tree->right);
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

