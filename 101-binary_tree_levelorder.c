#include "binary_trees.h"
/**
 * _height - function that measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0
 */
int _height(const binary_tree_t *tree)
{
	int hl = 0, hr = 0;

	if (!tree)
		return (0);
	if (tree->right)
		hr = 1 + _height(tree->right);
	if (tree->left)
	{
		hl = 1 + _height(tree->left);
	}
	if (hr > hl)
		return (hr);
	return (hl);
}
/**
 * _del - goes through a binary tree using
 * @tree: pointer to the root node of the tree to traverse
 * @hr: height
 * Return: v
 */
int *_del(binary_tree_t *tree, int hr)
{
	binary_tree_t *aux;
	int *v = NULL;

	aux = (void *)tree;
		while (hr)
		{
			aux = aux->left;
			hr--; }
		if (aux->left)
		{
			v[0] = 1;
			v[1] = aux->left->n;
			aux->left = NULL; }
		if (aux->right)
		{
			v[2] = 1;
			v[3] = aux->right->n;
			aux->right = NULL; }
		return (v);
}
/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return:
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int hr = 0, hl = 0;
	int *v = NULL;

	if (!tree || !func)
		return;
	hl = _height(tree->left);
	hr = _height(tree->right);
	if (hl > hr)
	{
		v = _del((void *)tree, hr);
	}
	if (tree->parent == NULL)
		func(tree->n);
	if (tree->left && tree->right)
	{
		func(tree->left->n);
		func(tree->right->n);
		binary_tree_levelorder(tree->left, func);
		binary_tree_levelorder(tree->right, func); }
	else if (tree->left)
	{
		func(tree->left->n);
		binary_tree_levelorder(tree->left, func); }
	else if (tree->right)
	{
		func(tree->right->n);
		binary_tree_levelorder(tree->right, func); }
	if (!tree->parent && v)
	{
		if (v[0])
			func(v[1]);
		if (v[2])
			func(v[3]); }
}
