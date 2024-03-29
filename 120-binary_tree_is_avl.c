#include "binary_trees.h"
#include "limits.h"

size_t height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int low, int high);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: If tree is NULL, your function must return 0, else return height
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + height(tree->left) : 1;
		r = tree->right ? 1 + height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * is_avl_helper - checks if a binary tree is a valid AVL tree
 * @tree: pointer to the root node of the tree to check.
 * @low: value of the smallest node visited thus far
 * @high: value of the largest node visited this far
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int is_avl_helper(const binary_tree_t *tree, int low, int high)
{
	size_t lhgt, rhgt, diff;

	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);
		lhgt = height(tree->left);
		rhgt = height(tree->right);
		diff = lhgt > rhgt ? lhgt - rhgt : rhgt - lhgt;
		if (diff > 1)
			return (0);
		return (is_avl_helper(tree->left, low, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, high));
	}
	return (1);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
