#include "binary_trees.h"
/**
 * binary_tree_size - function that measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: If tree is NULL, your function must return 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    size_t h = 0;
       if (!tree)
            return (0);
        if(tree->left && (tree->left->left || tree->left->right))
                h = h + binary_tree_size(tree->left);
        if (tree->parent && tree->left)
            h++;
        if (tree->right && (tree->right->left || tree->right->right))
                h = h + binary_tree_size(tree->right);
        else if (tree->right)
            h++;
        h++;
        return (h);
}
