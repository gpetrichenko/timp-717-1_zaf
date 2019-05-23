#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;

    struct node *next;
} node;

typedef node* list;

void init(list *l) {
    *l = NULL;
}

void clear(list *l) {
    list tmp = (list)malloc(sizeof(l));
    while(*l != NULL) {
        tmp = *l;
        *l = (*l)->next;
        free(tmp);
    }
}

int isEmply(list *l){
    if(*l != NULL)
        return 0;
    else
        return 1;
}

node* find(list *l, int value) {
    list tmp = (list)malloc(sizeof(l));
    tmp = *l;
    while(tmp->value != value) {
        if(tmp->next == NULL) {
            return NULL;}
        tmp = tmp->next;
    }
    return tmp;
}

int push_back(list *l, int value) {
    if ((*l) == NULL) {
        list tmp = (list)malloc(sizeof(l));
        tmp->next = NULL;
        tmp->value = value;
        *l = tmp;
        return 0;
    } if ((*l)->next == NULL) {
        list tmp = (list)malloc(sizeof(l));
        tmp->value = value;
        tmp->next = NULL;
        (*l)->next = tmp;
        return 0;

    } else {
        list tmp = (list)malloc(sizeof(l));
        tmp->value = value;
        tmp->next = (*l)->next;
        (*l)->next = tmp;
        return 0;
    }
}

int push_front(list *l, int value) {
    list tmp = (list)malloc(sizeof(l));
    tmp->value = value;
    tmp->next = (*l);
    (*l) = tmp;
    return 0;
}

void print(list *l) {
    list tmp = (list)malloc(sizeof(l));
    tmp = *l;
    while (tmp != NULL) {
        printf("%d ", (tmp)->value);
        tmp = tmp->next;
    }
    printf("\n");
}

int insertAfter(list *l, int n, int value) {
    list tmp = (list)malloc(sizeof(l));
    tmp = *l;
    for(int i = 1; i < n; i++)
    {
        tmp = tmp->next;
    }
    push_back(&tmp, value);
    return 0;
}

int remov(list *l, int value) {
    list tmp = (list)malloc(sizeof(l));
    while ((*l)->next->value != value)
        (*l) = (*l)->next;
    tmp = (*l)->next;
    (*l)->next = tmp->next;
    free(tmp);
    return 0;
}

int main () {
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
    push_back(&temp, a);
    print(&lst);
    scanf("%d", &a);
    push_front(&lst, a);
    print(&lst);
    scanf("%d%d", &n, &a);
    temp = lst;
    insertAfter(&temp, n, a);
    print(&lst);
    temp = lst;
    scanf("%d", &a);
    remov(&temp, a);
    print(&lst);
    clear(&lst);
    return 0;
}
