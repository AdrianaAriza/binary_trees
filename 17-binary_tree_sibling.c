#include "binary_trees.h"
/**
 * binary_tree_sibling - function that finds the sibling of a node
 * @node: pointer to the node to find the sibling
 *
 * Return: If node is NULL or the parent is NULL, return NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !(node->parent))
		return (NULL);

	if (node->parent->right && node->parent->left)
	{
		if (node->parent->right == node)
			return (node->parent->left);
		else
			return (node->parent->right);
	}
	return (NULL);
}
