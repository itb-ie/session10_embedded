//
// Created by Bogdan Ratiu on 16.11.2023.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"

t_node* create_node(int value) {
    t_node *temp = (t_node*)malloc(sizeof(t_node));
    temp->value = value;
    temp->left = temp->right = NULL;
    temp->height = 1;
    return temp;
}

int max(int a, int b) {
    return (a>b)?a:b;
}

int height(t_node *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

t_node* rotate_right(t_node *z) {
    t_node *y = z->left;
    t_node *t3 = y->right;

    //rotate
    y->right = z;
    z->left = t3;

    z->height = 1 + max(height(z->left), height(z->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

t_node* rotate_left(t_node *z) {
    t_node *y = z->right;
    t_node *t2 = y->left;

    //rotate
    y->left = z;
    z->right = t2;

    z->height = 1 + max(height(z->left), height(z->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

t_node* insert_node(t_node *root, int value) {
    if (root == NULL) {
        t_node *temp = create_node(value);
        return temp;
    }
    //now insert via recursion
    if (root->value == value) {
        return root;
    } else if (root->value > value) {
        root->left = insert_node(root->left, value);
    } else {
        root->right = insert_node(root->right, value);
    }
    return root;
}

void traverse_tree(t_node *root, int level) {
    if (root->left)
        traverse_tree(root->left, level+1);
    printf("%d ", root->value);
    if (root->right)
        traverse_tree(root->right, level+1);
    if (level == 1)
        printf("\n");
}

t_list *add_to_list(t_list *start, t_node *val, int level) {
    // create the list element
    t_list *temp = (t_list*)malloc(sizeof(t_list));
    t_list *i;
    temp->value = val;
    temp->level = level;
    temp->next = NULL;

    // add it to the back of the list
    if (start == NULL)
        return temp;
    i = start;
    while(i->next)
        i = i->next;
    i->next = temp;
    return start;
}

void display_tree(t_node *root, t_list *start, int level) {
    char children[3] = "";
    if (root->left) {
        start = add_to_list(start, root->left, level+1);
        strcat(children, "L");
    }
    if (root->right) {
        start = add_to_list(start, root->right, level+1);
        strcat(children, "R");
    }
    printf("%d(%s) ", root->value, children);
    if (start) {
        if (start->level != level)
            printf("\n");
        display_tree(start->value, start->next, start->level);
    }
    if (level == 0)
        printf("\n");
}
