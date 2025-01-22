#include <stdbool.h>

struct List
{
	int n;
	struct Link *root;
};

struct List create_list();
//struct Link *create_node(struct Node *initial, struct Node *destination);
void add_value(struct List *, int value);
void print_list(struct List);
void print_node(struct Link*);
void free_from_end(struct List *l);
void free_list(struct List *l);
bool search_value(struct List *l, int search);
struct List copy_list(struct List *l);
void remove_value(struct List *l, int);
void delete_node(struct List *l, struct Link *node_to_delete);
