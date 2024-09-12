#include <stdio.h>
#include <stdlib.h>

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
void add_value(struct List *, int value);
struct Node * create_node(int value);
struct List create_list();
void free_list(struct List *l);
void print_list(struct List);
void print_node(struct Node*);
void free_from_end(struct List *l);

int main(void)
{
	struct List ma_liste = create_list();
	struct Node *my_node = create_node(123);
	print_list(ma_liste);
	printf("\n");
	add_value(&ma_liste, 7);
	add_value(&ma_liste, 9);
	print_list(ma_liste);
	printf("\n");
	free(my_node);
	free_list(&ma_liste);
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
struct Node * create_node(int value)
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


void node_exists(struct List l, int value)
{
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
