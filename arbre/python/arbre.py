class node:
    value = 0
    left = None
    right = None

def create_node(value):
    return node()

def print_node(my_node):
    if(my_node == None):
       print("Noeud vide")
    else:
        print("valeur du noeud courant : ", my_node.value)
        print_node(my_node.left)
        print_node(my_node.right)

def insere_droite(base, noeud_fils):

def insere_gauche(base, noeud_fils):
