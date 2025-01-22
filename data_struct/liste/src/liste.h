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
