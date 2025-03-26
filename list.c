#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List *L = (List*)malloc(sizeof(List));
    L->head = NULL;
    L->tail = NULL;
    L->current = NULL;
    return L;
}

//La primera retorna el dato del primer nodo de la lista (head) y actualiza el current para que apunte a ese nodo.

void * firstList(List * list){
    if(list->head != NULL){
        list->current = list->head;
        return list->head->data;
    }
    return NULL;
}

//La segunda función retorna el dato del nodo a continuación del current y actualiza el current para que apunte a ese nodo.

void * nextList(List * list) {
    if(list->current != NULL){
        list->current = list->current->next;
        if(list->current != NULL){
            return list->current->data;
        }
    }            
    return NULL;
}

//La primera retorna el dato del último elemento en la lista y actualiza el current al nodo correspondiente.

void * lastList(List * list) {
    if(list->tail != NULL){
        list->current = list->tail;
        return list->current->data;
    }
    return NULL;
}

//La segunda función retorna el dato del nodo anterior a current y actualiza el current para que apunte a ese nodo.

void * prevList(List * list) {
    if(list->current != NULL){
        list->current = list->current->prev;
        if(list->current != NULL){
            return list->current->data;
        }
    }
    return NULL;
}

void pushFront(List * list, void * data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    newNode->prev = NULL;
    if (list->head != NULL) {
        list->head->prev = newNode;
    } else {
        list->tail = newNode;
    }
    list->head = newNode;
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

//la cual agrega un dato a continuación del nodo apuntado por list->current.

void pushCurrent(List * list, void * data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->current;
    newNode->prev = NULL;
    if(list->current != NULL){
        list->current->next = newNode;
    }
    list->head = newNode;
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}