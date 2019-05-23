#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node *prev;
    struct node *next;
} node;

typedef node* list;

void init(list* l) {
    *l = NULL;
}

void clear(list* l) {
    list tmp = (list)malloc(sizeof(l));
    while (*l != NULL) {
        tmp = *l;
        *l = (*l)->next;
        free(tmp);
    }
}

int isEmpty(list* l) {
    if (*l == NULL)
        return 1;
    else
        return 0;
}

node* find(list* l, int value) {
    list tmp = (list)malloc(sizeof(l));
    tmp = *l;
    while (tmp->value != value) {
        if (tmp->next == NULL)
            return NULL;
        tmp = (tmp)->next;
    }
    return tmp;
}

int push_back(list* l, int value) {
    if (*l == NULL) {
        list tmp = (list)malloc(sizeof(l));
        tmp->value = value;
        tmp->next = NULL;
        tmp->prev = NULL;
        *l = tmp;
        return 0;
    } else if ((*l)->next == NULL) {
        list tmp = (list)malloc(sizeof(l));
        tmp->value = value;
        tmp->next = NULL;
        tmp->prev = *l;
        (*l)->next = tmp;
        return 0;
    } else {
        list tmp = (list)malloc(sizeof(l));
        tmp->value = value;
        tmp->next = (*l)->next;
        tmp->prev = *l;
        (*l)->next->prev = tmp;
        (*l)->next = tmp;
        return 0;
    }
}

int push_front(list* l, int value) {
    if (*l == NULL) {
        list tmp = (list)malloc(sizeof(l));
        tmp->value = value;
        tmp->next = NULL;
        tmp->prev = NULL;
        *l = tmp;
        return 0;
    } else if ((*l)->prev == NULL) {
        list tmp = (list)malloc(sizeof(l));
        tmp->value = value;
        tmp->next = *l;
        tmp->prev = NULL;
        (*l)->prev = tmp;
        *l = (*l)->prev;
        return 0;
    } else {
        list tmp = (list)malloc(sizeof(l));
        tmp->value = value;
        tmp->next = *l;
        tmp->prev = (*l)->prev;
        (*l)->next->prev = tmp;
        (*l)->next = tmp;
        return 0;
    }
}

int insertAfter(list* l, int n, int value) {
    list tmp = (list)malloc(sizeof(l));
    tmp = *l;
    for(int i = 1; i < n; i++)
    {
        tmp = tmp->next;
    }
    push_back(&tmp, value);
    return 0;
}

int insertBefore(list* l, int n, int value) {
    list tmp = (list)malloc(sizeof(l));
    tmp = *l;
    while (tmp->next != NULL)
        tmp = tmp->next;
    for(int i = 1; i < n; i++)
    {
        tmp = tmp->prev;
    }
    push_back(&tmp, value);
    return 0;
}

int removeFirst(list* l, int value) {
    while ((*l)->value != value)
        (*l) = (*l)->next;
    if (*l != NULL) {
        list tmp = *l;
        if (((*l)->next != NULL) && ((*l)->prev != NULL)) {
            (*l)->prev->next = (*l)->next;
            (*l)->next->prev = (*l)->prev;
        }
        if (((*l)->next != NULL) && ((*l)->prev == NULL)) {
            (*l)->next->prev = NULL;
            (*l) = (*l)->next;
        }
        if (((*l)->next == NULL) && ((*l)->prev != NULL)) {
            (*l)->prev->next = NULL;
        }
        free(tmp);
    }
    return 0;
}

int removeLast(list* l, int value) {
    while ((*l)->next != NULL)
        *l = (*l)->next;
    while ((*l)->value != value)
        (*l) = (*l)->prev;
    if (*l != NULL) {
        list tmp = *l;
        if (((*l)->next != NULL) && ((*l)->prev != NULL)) {
            (*l)->prev->next = (*l)->next;
            (*l)->next->prev = (*l)->prev;
        }
        if (((*l)->next != NULL) && ((*l)->prev == NULL)) {
            (*l)->next->prev = NULL;
            (*l) = (*l)->next;
        }
        if (((*l)->next == NULL) && ((*l)->prev != NULL)) {
            (*l)->prev->next = NULL;
        }
        free(tmp);
    }
    return 0;
}

void print_invers(list* l){
    list tmp = (list)malloc(sizeof(l));
    tmp = *l;
    while (tmp->next != NULL)
        tmp = tmp->next;
    do{
        printf("%d ", tmp->value);
        tmp = tmp->prev;
    }
    while(tmp != NULL);
    printf("\n");
}

void print(list *l) {
    list tmp = (list)malloc(sizeof(l));
    tmp = *l;
    do{
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    while(tmp != NULL);

    printf("\n");

}

int main() {
int n, a;
    list lst, temp;
    scanf("%d", &n);
    init(&lst);
    scanf("%d", &a);
    push_back(&lst, a);
    temp = lst;
    for(int i = 1; i < n; i++) {
        scanf("%d", &a);
        push_back(&temp, a);
        temp = temp->next;
    }
    print(&lst);
    for(int i = 0; i < 3; i++) {
        scanf("%d", &a);
        if(find(&lst, a) != NULL)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
    scanf("%d", &a);
    temp = lst;
    while (temp->next != NULL)
        temp = temp->next;
    push_back(&temp, a);
    print_invers(&lst);
    scanf("%d", &a);
    temp = lst;
    push_front(&lst, a);
    print(&lst);
    scanf("%d%d", &n, &a);
    insertAfter(&lst, n, a);
    print_invers(&lst);
    scanf("%d%d", &n, &a);
    insertBefore(&lst, n, a);
    print(&lst);
    scanf("%d", &a);
    temp = lst;
    removeFirst(&temp, a);
    print_invers(&lst);
    temp = lst;
    scanf("%d", &a);
    removeLast(&temp, a);
    print(&lst);
    /*temp = lst;
    removeFirst(&temp, temp->value);
    print_invers(&lst);
    temp = lst;
    while (temp->next != NULL)
        temp = temp->next;
    removeLast(&temp, temp->value);
    print(&lst);*/
    clear(&lst);
    return 0;
}
