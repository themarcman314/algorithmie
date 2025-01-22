#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include "link.h"

struct Graph
{
	const char *name;
	struct Node start;
	struct Node end;
};
struct Player
{
};

struct Node createNode(const char name[], struct List *portals);
struct Link *createLink(struct Node *initial, struct Node *destination);
struct Graph createGraph(const char *name);
void printNode(const struct Node room);

int main(void)
{
	struct List portals = create_list();
	
	struct Node first_room = createNode("A", &portals);
	//createLink(struct Node *initial, struct Node *destination);

	return 0;
}

struct Node createNode(const char name[], struct List *portals)
{
	struct Node room;
	room.name = name;


	//room.portals = ;
	
	return room;
}
struct Link *createLink(struct Node *initial, struct Node *destination)
{
	struct Link *portal = (struct Link *) malloc(sizeof(struct Link));
	if (portal != NULL)
	{
		portal->initial = initial;
		portal->destination = destination;
		portal->next = NULL;
		return portal;
	}
	else printf("Problem creating portal\n");
	return NULL;
}
struct Graph createGraph(const char *name)
{
	struct Graph dungeon;

	dungeon.name = name;
	//dungeon.start = 

	return dungeon;
}
void printNode(const struct Node room)
{
	printf("name : %s\n", room.name);
	//printf("",room.destination);
}
void printLink(struct Link *n)
{
	struct Link *current = n;
	unsigned int counter = 0;
	if(current == NULL)
		printf("There are no links in this room\n");
	else
	{
		while(current != NULL)
		{
			printf("Starting room of Link n°%d is : %s\n", counter, current->initial->name);
			printf("Destination room of Link n°%d is : %s\n", counter, current->destination->name);
			current = current->next;
			counter++;
		}
	}
}
struct List create_list(void)
{
	struct List l;
	l.n = 0;
	l.root = NULL;
	return l;
}
