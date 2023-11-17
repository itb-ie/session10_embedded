//
// Created by Bogdan Ratiu on 16.11.2023.
//

#ifndef SESSION10_EMBEDDED_TREE_H
#define SESSION10_EMBEDDED_TREE_H
#include <stdbool.h>

typedef struct node {
    int value, height;
    struct node *left, *right;
} t_node;

typedef struct list {
    t_node *value;
    int level;
    struct list *next;
} t_list;

t_node* create_node(int value);
t_node* insert_node(t_node *root, int value);
void traverse_tree(t_node *root, int level);
void display_tree(t_node *root, t_list *start, int level);
t_node* insert_avl(t_node *root, int value);
bool find_in_avl(t_node *root, int value);

#endif //SESSION10_EMBEDDED_TREE_H
