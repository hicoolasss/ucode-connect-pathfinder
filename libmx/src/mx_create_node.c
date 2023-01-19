#include "../inc/libmx.h"

t_list *mx_create_node(void *data) {
    t_list *new_list = (t_list*)malloc(16);
    new_list->data = data;
    new_list->next = NULL;
    return new_list;
}
