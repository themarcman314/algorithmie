#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node *left;
	struct node *right;
} node;

node *create_node(int value);
void print_tree(node *root_node);
void print_tree_rec(node *root_node, int level);
void print_tabs(int num_tabs);

int main(void)
{
	node *n1 = create_node(10);
	node *n2 = create_node(11);
	node *n3 = create_node(12);
	node *n4 = create_node(13);
	node *n5 = create_node(14);

	n1->left = n2;
	n1->right = n3;
	n3->left = n4;
	n3->right = n5;

	print_tree(n1);

	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);

	return 0;
}


node *create_node(int value)
{
node *result = malloc(sizeof(node));
	if(result != NULL)
	{
		result->value = value;
		result->left = NULL;
		result->right = NULL;
	}
	return result;
}

void print_tree(node *root_node)
{
	print_tree_rec(root_node, 0);
}

void print_tree_rec(node *root_node, int level)
{
	if(root_node == NULL)
	{
		print_tabs(level);
		printf("===<empty===\n");
		return;
	}
	print_tabs(level);
	printf("value = %d\n", root_node->value);
	print_tabs(level);
	printf("left\n");
	print_tree_rec(root_node->left, level+1);
	print_tabs(level);
	printf("right\n");
	print_tree_rec(root_node->right, level+1);
	print_tabs(level);
	printf("done\n");
}
void print_tabs(int num_tabs)
{
	for(int i=0; i < num_tabs; i++)
		printf("\t");
}
