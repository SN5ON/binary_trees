#include "binary_trees.h"

/**
 * binary_tree_sibling -  finds the sibling of a node
 * @node: a pointer to the node to find the sibling
 *
 * Return: node is NULL,node has no sibling or the parent is NULL,
 * return NULL
 *   
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
