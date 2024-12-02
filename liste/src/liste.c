#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
	int value;
	struct Node *next;
};
struct List
{
	int n;
	struct Node *root;
};

struct List create_list();
struct Node *create_node(int value);
void add_value(struct List *, int value);
void print_list(struct List);
void print_node(struct Node*);
void free_from_end(struct List *l);
void free_list(struct List *l);
bool search_value(struct List *l, int search);
struct List copy_list(struct List *l);
void remove_value(struct List *l, int);
void delete_node(struct List *l, struct Node *node_to_delete);

int main(void)
{
	struct List ma_liste = create_list();
	struct Node *my_node = create_node(123);
	printf("List 1\n");
	print_list(ma_liste);
	printf("\n");
	add_value(&ma_liste, 7);
	add_value(&ma_liste, 9);
	add_value(&ma_liste, 2);
	printf("List 1\n");
	print_list(ma_liste);
//	if(search_value(&ma_liste, 9) == true)
//		printf("Found node !\n");
//	else printf("No node exists with such value :(\n");
//
//	struct List new_list = copy_list(&ma_liste);
//	printf("\n");
//	printf("List 2\n");
//	print_list(new_list);
//
//		
//	printf("\n");
	free(my_node);
	//free_list(&ma_liste);
	//free_list(&new_list);
	printf("\n\n\n");
	remove_value(&ma_liste, 2);
	print_list(ma_liste);

	
	return 0;
}

struct List create_list(void)
{
	struct List l;
	l.n = 0;
	l.root = NULL;
	return l;
}
void print_list(struct List l)
{
	if(l.n != 0)
	{
		print_node(l.root);
	}
	printf("list contains %d elements\n", l.n);
}
struct Node *create_node(int value)
{
	struct Node *n = (struct Node *) malloc(sizeof(struct Node));
	if (n != NULL)
	{
		n->value = value;
		n->next = NULL;
		return n;
	}
	else printf("Problem creating node\n");
	return NULL;
	
}

void print_node(struct Node *n)
{
	struct Node *current = n;
	unsigned int counter = 0;
	if(current == NULL)
		printf("Empty list\n");
	else
	{
		while(current != NULL)
		{
			printf("Value of node %d is : %d\n", counter, current->value);
			current = current->next;
			counter++;
		}
	}
}
void add_value(struct List *list, int value)
{
	struct Node *current = list->root;
	if(current == NULL)
		list->root = create_node(value);
	else
	{
		// While not the end of the list
		while(current->next != NULL)
		{
			// Go to the next node
			current = current->next;
		}
		current->next = create_node(value);
	}
	list->n++;
}


bool search_value(struct List *l, int search)
{
	if(l->root == NULL)
	{
		printf("list has no nodes");
		return false;
	}
	else
	{
		struct Node *current = l->root;
		while(current != NULL)
		{
			printf("value of node in search : %d\n", current->value);
			if(current->value == search)
			{
				return true;
			}
			current = current->next;
		}
	}
	return false;
}

void free_from_end(struct List *l)
{
	struct Node *current = l->root;
	if(current->next == NULL)
		free(current);
	else
	{
		while(current->next->next != NULL)
		{
			current = current->next;
		}
		free(current->next);
		current->next = NULL;
	}
	l->n--;
	printf("Free'd memory associated with one node\n");
	printf("%d nodes remain\n", l->n);
}
void free_list(struct List *l)
{
	while(l->n != 0)
	{
		free_from_end(l);
	}
}
struct List copy_list(struct List *l)
{
	printf("\n\nCreating new list...\n");
	struct List new_list = create_list();

	struct Node *current_node = l->root;

	while(current_node != NULL)
	{
		printf("%d\n", new_list.n);
		add_value(&new_list, current_node->value);
		current_node = current_node->next;
	}
	printf("%d\n", new_list.n);

	return new_list;
}
void remove_value(struct List *l, int value_to_remove)
{
	if(l->root == NULL)
	{
		printf("List already empty");
		return;
	}

	// remove root value
	if(l->root->value == value_to_remove)
	{
		struct Node *temp;
		// store a reference of node pointer to delete
		temp = l->root;
		// assign new root node
		l->root = l->root->next;
		delete_node(l, temp);
		return;
	}

	// walk the list to find node
	struct Node *current = l->root;
	while(l->root != NULL && current->next->value != value_to_remove)
	{
		current = current->next;
	}

	// remove any other value
	if (current->next->value == value_to_remove)
	{
		struct Node *temp = current->next;
		current->next = current->next->next;
		delete_node(l, temp);
	}
}

void delete_node(struct List *l, struct Node *node_to_delete)
{
	free(node_to_delete);
	l->n--;
	printf("Free'd memory associated with one node\n");
	printf("%d nodes remain\n", l->n);
}
