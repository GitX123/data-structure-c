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

info_link create_llist() {
    int num_nodes;
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
            return NULL;
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

    return head_ptr;
}

void query_llist(info_link head_ptr) {
    printf("--- llist traversal ---\n");
    
    while(1) {
        int num;
        info_link node_ptr = head_ptr;
        printf("Query number: ");
        scanf("%d", &num);

        while(node_ptr) {
            if(node_ptr->num == num) {
                printf("Name: %s\n", node_ptr->name);
                printf("Address: %s\n", node_ptr->address);
                break;
            }
            node_ptr = node_ptr->next_ptr;
            if(node_ptr == NULL) {
                printf("Number specified not found.\n");
            }
        }
    }
}

int main(int argc, char *argv[]) {
    info_link head_ptr = create_llist();

    if(!head_ptr) {
        return 1;
    }

    query_llist(head_ptr);
    return 0;
}