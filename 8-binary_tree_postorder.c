#include "binary_trees.h"
/**
 * binary_tree_postorder - function that goes through a binary
 * tree using post-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return:
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	if (tree->left && (tree->left->left || tree->left->right))
		binary_tree_postorder(tree->left, func);
	if (tree->left && !(tree->left->left || tree->left->right))
		func(tree->left->n);
	if (tree->right && (tree->right->left || tree->right->right))
		binary_tree_postorder(tree->right, func);
	else if (tree->right && !(tree->left->left || tree->left->right))
		func(tree->right->n);
	func(tree->n);
}
