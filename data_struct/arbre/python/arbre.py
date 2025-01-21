# coding: utf-8


class Node:
    pass

class Node:
    value : int
    left : Node
    right : Node

class SortedTree:
    root: Node
    number_of_nodes: int

def main():

    t = create_tree()
    display_tree(t)
    insert_in_sorted_tree(t, 9)
    print("\n\n")
    display_tree(t)
    insert_in_sorted_tree(t, 10)
    print("\n\n")
    display_tree(t)
    insert_in_sorted_tree(t, 2)
    print("\n\n")
    display_tree(t)
    insert_in_sorted_tree(t, 4)
    print("\n\n")
    display_tree(t)
    insert_in_sorted_tree(t, 7)
    print("\n\n")
    display_tree(t)
    insert_in_sorted_tree(t, 12)
    print("\n\n")
    display_tree(t)
    insert_in_sorted_tree(t, 3)
    print("\n\n")
    display_tree(t)
    insert_in_sorted_tree(t, 4)
    print("\n\n")
    display_tree(t)


    if is_present_sorted_tree(t, 2) == True:
        print("found!")
    else :
        print("not found :(")

    if is_present_sorted_tree(t, 5) == True:
        print("found!")
    else :
        print("not found :(")

    if is_present_sorted_tree(t, 10) == True:
        print("found!")
    else :
        print("not found :(")

    if is_present_sorted_tree(t, 4) == True:
        print("found!")
    else :
        print("not found :(")


def create_node(val:int):
    n:Node = Node()
    n.value = val
    n.left = None
    n.right = None
    return n

def display_node(n:Node, height=1):
    tabulation = "\t"*height
    print(f"{{\n{tabulation}value: {n.value}, \n{tabulation}left: ",end="")
    if n.left != None:
        display_node(n.left, height+1)
    else:
        print("{}")
    print(f"{tabulation}right: ",end="")
    if n.right != None:
        display_node(n.right, height+1)
    else:
        print("{}")
    print("}")

def insert_right(n_base:Node, n_fils:Node):
    n_base.right = n_fils

def insert_left(n_base:Node, n_fils:Node):
    n_base.left = n_fils

def create_tree():
    t:SortedTree = SortedTree()
    t.root = None
    t.number_of_nodes = 0
    return t

def insert_in_sorted_tree(t:SortedTree, value:int):
    new_node:Node = create_node(value)
    
    if t.number_of_nodes == 0 :
        t.root = new_node
    else :
        current_node = t.root
        while (current_node.left != None and value < current_node.value) or (current_node.right != None and value > current_node.value) :
            if value <= current_node.value :
                current_node = current_node.left
            else :
                current_node = current_node.right

        if value <= current_node.value :
            insert_left(current_node, new_node)
        else :
            insert_right(current_node, new_node)

    t.number_of_nodes = t.number_of_nodes + 1

def display_tree(t:SortedTree):
    if t.root == None :
        print("root has no value")
    else :
        display_node(t.root)
    print(f"There are {t.number_of_nodes} nodes")

def is_present_sorted_tree(t:SortedTree, value:int)->bool:
    print(f"looking for node with value : {value}")
    if t.number_of_nodes == 0 :
        return False
    if t.root == value :
        return True

    current_node = t.root

    while(current_node.value != value):
        if current_node.left != None and value < current_node.value :
                current_node = current_node.left

        elif current_node.right != None and value > current_node.value :
                current_node = current_node.right
        else :
            return False
    
    return True


if __name__ == "__main__":
    main()
