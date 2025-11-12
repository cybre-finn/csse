#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


void print_usage(void);
void traverse_list(node *list);
node *quicksort(node *list);

int main(int argc, char *argv[]) {
    int q_flag;
    int i;
    node *list;
    
    q_flag = 0;
    list = NULL;


    if (argc == 1) {
        fprintf(stderr, "No arguments provided\n");
        print_usage();
        return 1;
    }

    /*parse integers and flags*/
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-q") == 0) {
            q_flag = 1;
        }
        else {
            if(list == NULL) {
                list = create_node(atoi(argv[i]), NULL);
            }
            else {
                list = create_node(atoi(argv[i]), list);
            }
        }
    }

    if(list == NULL) {
        print_usage();
        return 1;
    }

    list = quicksort(list);

    assert(is_sorted(list));

    if (!q_flag) {
        traverse_list(list);
    }
    return 0;
}

node *quicksort(node *list) {
    node * list_larger;
    node * list_smaller;
    node *  new_list1;
    node *  new_list2;
    node * first;
    list_larger = NULL;
    list_smaller = NULL;
    if(list == NULL) {
        return NULL;
    }
    else if(list->next == NULL) {
        return list;
    }
    else {
        first = list;
        list = list->next;
        while(list != NULL) {
        if (list->data >= first->data) {
            list_larger = create_node(list->data, list_larger);
        }
        else {
            list_smaller = create_node(list->data, list_smaller);
        }
        list = list->next;
        }
        new_list1 = quicksort(list_smaller);
        new_list2 = quicksort(list_larger);

        new_list1 = append_lists(new_list1, create_node(first->data, NULL));
        new_list2 = append_lists(new_list1, new_list2);
        free_list(first);
        return new_list2;
    }
}

void traverse_list(node *list) {
    while(list != NULL) {
        printf("%d\n", list->data);
        list = list->next;
    }
}

void print_usage() {
    printf("Usage info: sorter [-b] [-q] number1 [number2 ... ] (unlimited numbers) \n"); /*BNF-like usage info*/
}