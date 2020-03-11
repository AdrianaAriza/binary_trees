#include "binary_trees.h"
/**
 * binary_tree_nodes - function that counts the nodes with
 * at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 *
 * Return: If tree is NULL, your function must return 0
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t h = 0;

	if (!tree)
		return (0);
	if (tree->right || tree->left)
	{
		h = 1;
		if (tree->right)
			h = h + binary_tree_nodes(tree->right);
		if (tree->left)
			h = h + binary_tree_nodes(tree->left);
	}
	return (h);
}
