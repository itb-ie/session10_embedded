#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
    t_node *root = insert_avl(NULL, 50);
    root = insert_avl(root, 30);
    root = insert_avl(root, 80);
    root = insert_avl(root, 40);
    root = insert_avl(root, 70);
    root = insert_avl(root, 90);
    root = insert_avl(root, 20);
    root = insert_avl(root, 100);
    root = insert_avl(root, 200);
    root = insert_avl(root, 300);
    display_tree(root, NULL, 0);

    // test out the avl
//    t_node *avl_tree = insert_avl(NULL, 50);
//    avl_tree = insert_avl(avl_tree, 40);
//    avl_tree = insert_avl(avl_tree, 45);
//    display_tree(avl_tree, NULL, 0);
    int value_to_search = 180;
    printf("Value %d %s in the tree\n", value_to_search,
           find_in_avl(root, value_to_search)?"is":"is not");
    return 0;
}
