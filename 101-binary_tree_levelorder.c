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
 * @hl: height
 * @v: vector
 * Return: v
 */
void _del(binary_tree_t *tree, int hl, int *v)
{
	binary_tree_t *aux;

	aux = tree;
		while (hl)
		{
			aux = aux->left;
			hl--; }
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
	int v[4] = {0, 0, 0, 0};

	if (!tree || !func)
		return;
	hl = _height(tree->left);
	hr = _height(tree->right);
	if (hl > hr)
	{
		_del((void *)tree, hl, v);
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
		binary_tree_levelorder(tree->left, func);
	}
	else if (tree->right)
	{
		func(tree->right->n);
		binary_tree_levelorder(tree->right, func); }
	if (!tree->parent)
	{
		if (v[0])
			func(v[1]);
		if (v[2])
			func(v[3]); }
}
