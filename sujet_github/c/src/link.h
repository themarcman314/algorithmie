struct Link
{
	struct Node *initial;
	struct Node *destination;
	struct Link *next;
};
struct Node
{
	const char *name;
	struct Link *portals;
};
