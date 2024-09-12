#include <stdio.h>

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
void add_value(struct List, int value);
struct Node create_node(int value);
struct List create_list();
void print_list(struct List);
void print_node(struct Node*);

int main(void)
{
	//struct List ma_liste = create_list();
	struct Node my_node = create_node(123);
	print_node(&my_node);
	//print_list(ma_liste);
	//add_value(ma_liste, 7);
	//add_value(ma_liste, 9);
	return 0;
}

struct Node create_node(int value)
{
	struct Node n;
	n.value = 123;
	n.next = NULL;
	return n;
}

void print_node(struct Node *n)
{
	struct Node *temp = n;
	unsigned int counter = 0;
	if(n == 0)
		printf("Empty list\n");
	else
	{
		while(temp != NULL)
		{
			printf("Value of node %u is : %d\n", counter, temp->value);
			temp = temp->next;
			counter++;
		}
	}
}
//void add_value(struct List list, int value)
//{
//	struct Node *current = list.root;
//	if(current == 0)
//	{
//		list.root = create_node(value);
//	}
//}

void print_list(struct List l)
{
	if(l.n != 0)
	{
		print_node(l.root);
	}
}

void node_exists(struct List l, int value)
{
}
