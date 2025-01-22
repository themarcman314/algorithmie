# coding: utf-8

class Link:
    pass
class Node:
    pass

class Link:
    current : Node
    destination : Node

class Node:
    name : str
    portals : list[Link] = []

class Graph:
    name : str
    start : Node
    end : Node

class Player:
    name : str
    current_room : Node

def main():
    my_first_node = createNode("A", None)
    printNode(my_first_node)
    my_second_node = createNode("B", my_first_node)
    printNode(my_second_node)



def createNode(name:str, destination_room:Node) -> Node:
    new_room:Node = Node()
    new_room.name = name
    if destination_room:
        new_room.portals.append(createLink(new_room, destination_room))
    return new_room

def createLink(current_room:Node, destination_room:Node) -> Link:
    new_link:Link = Link()
    new_link.current = current_room
    new_link.destination = destination_room
    return new_link

def createGraph() -> Graph:
    print("nice tits!")
def printNode(n:Node):
    print(f"Name : {n.name}")
    if n.portals:
        print(f"{n.portals.current} <-> {n.portals.destination}")


if __name__ == "__main__":
    main()
