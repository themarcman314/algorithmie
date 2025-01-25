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
    portals : list[Link]

class Graph:
    name : str
    start : Node
    end : Node

class Player:
    name : str
    current_room : Node

def main():
    createGraph()

def createNode(name:str) -> Node
    new_room:Node = Node()
    new_room.name = name
    new_room.portals = []
    return new_room

def createLink(current_room:Node, destination_room:Node):
    new_link:Link = Link()
    # Create portal in one direction
    new_link.current = current_room
    new_link.destination = destination_room
    current_room.portals.append(new_link)

def createGraph() -> Graph:
    my_first_node = createNode("A")
    my_second_node = createNode("B")
    createLink(my_first_node, my_second_node)
    c = createNode("C")
    d = createNode("D")
    e = createNode("E")
    f = createNode("F")
    g = createNode("G")
    createLink(c, f)
    createLink(d, e)
    createLink(f, c)
    createLink(f, my_first_node)
    printNode(my_first_node)
    print()
    printNode(my_second_node)
    print()
    printNode(c)
    print()
    printNode(d)
    print()
    printNode(e)
    print()
    printNode(f)
    print()
    printNode(g)
    print()
    print()
    print()
    new_player = createPlayer("bob",c)
    printNode(c)
    printPlayerRoom(new_player)
    usePortal(new_player,0)
    printPlayerRoom(new_player)

def createPlayer(name:str, starting_room:Node) -> Player:
    new_player = Player()
    new_player.name = name
    new_player.current_room = starting_room
    return new_player

def printPlayerRoom(p:Player):
    print(f"Player {p.name} is in room {p.current_room.name}")

def usePortal(p:Player, index:int):
    # if portal to such index exists
    if p.current_room.portals[index]:
        p.current_room = p.current_room.portals[index].destination

def printNode(n:Node):
    print(f"Name : {n.name}")
    # Print all portals
    for i in range(len(n.portals)):
        print(f"{n.portals[i].current.name} -> {n.portals[i].destination.name}")

if __name__ == "__main__":
    main()
