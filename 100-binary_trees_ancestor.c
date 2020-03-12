#include "binary_trees.h"
/**
 * binary_tree_depth - function that measures the depth
 * of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 *
 * Return: If tree is NULL, your function must return 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t d = 0;

	if (!tree)
		return (0);
	if (tree->parent)
		d = 1 + binary_tree_depth(tree->parent);
	return (d);
}
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: If node is NULL or the parent is NULL, return NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	binary_tree_t *aux, *_first = (void *)first, *_second = (void *)second;
	int h_first, h_second, gap = 0;

	while (_first->parent)
		_first = _first->parent;
	while (_second->parent)
		_second = _second->parent;

	if (_first != _second)
		return (NULL);

	h_first = binary_tree_depth(first);
	h_second = binary_tree_depth(second);

	if (h_second > h_first)
	{
		aux = (void *)first;
		first = second;
		second = aux;
	}
	gap = binary_tree_depth(first) - binary_tree_depth(second);
	while (gap)
	{
		first = first->parent;
		gap--;
	}
	if (first == second)
		return ((void *)first);
	while (first && (first->parent != second->parent))
	{
		first = first->parent;
		second = second->parent;
	}
	return (first->parent);
}
