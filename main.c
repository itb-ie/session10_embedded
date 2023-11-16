#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
    t_node *root = insert_node(NULL, 50);
    insert_node(root, 30);
    insert_node(root, 80);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 90);
    insert_node(root, 20);

    traverse_tree(root, 1);
    display_tree(root, NULL, 0);
    insert_node(root, 100);
    insert_node(root, 200);
    insert_node(root, 300);
    display_tree(root, NULL, 0);

    return 0;
}
