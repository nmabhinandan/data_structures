#include <stdlib.h>
#include "linked_list.h"

LinkedList* initalize_list() {
  LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
  list->head = NULL;
  list->tail = NULL;
  list->count = 0;

  return list;
}

Node* get_new_node(int32_t data) {
  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->ptr = NULL;
  new_node->data = data;

  return new_node;
}

void insert_at_beg(LinkedList* list, int32_t data) {
  if (NULL == list) {
    return;
  }

  Node* new_node = get_new_node(data);
  if (NULL == list->head) {
    list->tail = new_node;
  }
  new_node->ptr = list->head;
  list->head = new_node;
}

void insert_at_end(LinkedList* list, int32_t data) {
  if (NULL == list) {
    return;
  } 

  Node* new_node = get_new_node(data);
  if (NULL == list->head) {
    list->head = new_node;
  } else {
    list->tail->ptr = new_node;
  }
  list->tail = new_node;
  list->count++;
}

void insert_after_pos(LinkedList* list, int32_t data, int32_t pos) {
  
  if (NULL == list || NULL == list->head) {
    return;
  }
  Node* new_node = get_new_node(data);

  if (1 == pos) {
    new_node->ptr = list->head->ptr;
    list->head->ptr = new_node;
    list->count++;
    return;
  }
  if (pos == list->count) {
    list->tail->ptr = new_node;
    list->tail = new_node;
    list->count++;
    return;
  }

  Node* temp = list->head;
  for (int32_t i = 1; i <= pos; i++) {
    temp = temp->ptr;
  }

  new_node->ptr = temp->ptr;
  temp->ptr = new_node;
  list->count++;
}

void delete_at_beg(LinkedList* list) {
  if (NULL == list || NULL == list->count) {
    return;
  }

  Node* temp = list->head;
  list->head = list->head->ptr;
  free(temp);

  if (list->count == 1) {
    list->tail = NULL;
  }
  list->count--;
}

void delete_at_end(LinkedList* list) {
  if (NULL == list || list->count < 1) {
    return;
  }

  if (list->count == 1) {
    delete_at_beg(list);
    return;
  }

  Node* temp = list->head;
  while (temp->ptr != list->tail) {
    temp = temp->ptr;
  }

  free(list->tail);
  list->tail = temp;
  list->tail->ptr = NULL;
  list->count--;
}

void delete_at_pos(LinkedList* list, int32_t pos) {
  
  if (NULL == list || 0 == list->count || 1 > pos || pos > list->count) {
    return;
  }
  if (pos == 1) {
    delete_at_beg();
  }
  
  Node cursor = list->head;
  for (int i = 1; i < pos - 1; i++) {
    cursor = cursor->ptr;
  }

  Node* temp = cursor->ptr;
  cursor->ptr = temp->ptr;
  free(temp);
  list->count--;
}

int32_t sum_of_all_nodes(LinkedList* list) {
  if (NULL == list->head) {
    return 0;
  }
  Node* cursor = list->head;
  int32_t total = 0;
  while (NULL != cursor) {
    total += cursor->data;
    cursor = cursor->ptr;
  }
  return total;
}
