#include <stdio.h>
#include <stdlib.h>

// node definition
struct info_node {
    int num;
    char name[20];
    char address[50];
    struct info_list  *next_ptr;
};
typedef struct info_node info_node;
typedef info_node *info_link;

void print_llist(info_link head_ptr) {
    info_link node_ptr = head_ptr;

    printf("--- llist data ---\n");
    while(node_ptr) {
        printf("Number: %d\n", node_ptr->num);
        printf("Name: %s\n", node_ptr->name);
        printf("Address: %s\n", node_ptr->address);
        printf("\n");
        node_ptr = node_ptr->next_ptr;
    }
}

int main() {
    int num_nodes = 1;
    printf("--- llist creation ---\n");
    printf("Number of nodes: ");
    scanf("%d", &num_nodes);

    info_link head_ptr;
    info_link prev_node_ptr = NULL;
    info_link node_ptr;
    for(int i=0; i<num_nodes; i++) {
        // memory allocation
        node_ptr = (info_link) malloc(sizeof(info_node));

        if(!node_ptr) {
            printf("Memory allocation failed.\n");
            return 1;
        } 

        if(i == 0) {
            head_ptr = node_ptr;
        }
        
        if(prev_node_ptr != NULL) {
            prev_node_ptr->next_ptr = node_ptr;
        }
        
        // fill in node data
        printf("Number: ");
        scanf("%d", &node_ptr->num);
        printf("Name: ");
        scanf("%s", node_ptr->name);
        printf("Address: ");
        scanf("%s", node_ptr->address);
        printf("\n");
        node_ptr->next_ptr = NULL;
        prev_node_ptr = node_ptr;
    }

    print_llist(head_ptr);
    return 0;
}