#include "../inc/libmx.h"

void mx_pop_front(t_list **head) {
    if (*head == NULL) {
        free(*head);
        return;
    }
    t_list *temp = *head;
    *head = temp->next;
    free(temp);
    temp = NULL;
}
