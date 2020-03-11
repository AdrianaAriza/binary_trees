#include "binary_trees.h"
/**
 * binary_tree_insert_right - function that inserts a node
 * as the right-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 *
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

		if (!parent)
			return (NULL);
		new_node = binary_tree_node(parent, value);
		if (!new_node)
			return (NULL);
		if (parent->right)
		{
			parent->right->parent = new_node;
			new_node->right = parent->right;
		}
		else
		{
			new_node->right = NULL;
		}
		parent->right = new_node;
		new_node->left = NULL;
		new_node->n = value;
		new_node->parent = parent;
		return (new_node);
}
