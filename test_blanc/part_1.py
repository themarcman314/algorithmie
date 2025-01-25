class Node:
    pass

class Node:
    value:int
    child:Node

class List:
    root:Node
    node_count:int

def main():
    my_list = createList()
    addNode(my_list, 2)
    #addNode(my_list, 1)
    #addNode(my_list, 7)
    printList(my_list)

def createList()->List:
    new_list = List()
    new_list.root = None
    new_list.node_count = 0
    return new_list

def createNode(value:int)->Node:
    new_node = Node()
    new_node.value = value
    new_node.child = None
    return new_node

def addNode(l:List, value:int):
    current_node = Node()
    current_node = l.root
    print(current_node)
    print(l.root)

    current_node = createNode(value)
    print(current_node)
    print(l.root)

    l.root = createNode(value)
    print(current_node)
    print(l.root)

    #l.root = createNode(value)
    while current_node != None:
        current_node = current_node.child

    l.node_count += 1

def printList(l:list):
    print(f"List has {l.node_count} values")
    current_node = Node()
    current_node = l.root
    while(current_node != None):
          print(f"{current_node.value}->")
          current_node = current_node.child





if __name__ == "__main__":
    main()
