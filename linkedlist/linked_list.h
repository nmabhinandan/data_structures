#include <stdlib.h>

typedef struct _node_
{
	int data;
	struct _node_* ptr;
} Node;

typedef struct _linked_list_
{
	Node *head, *tail;
	int count;
} LinkedList;

void initialize_list();
void insert_at_end(LinkedList*, int32_t);
void insert_after_pos(LinkedList *list, int32_t data, int32_t pos);
void delete_at_beg(LinkedList* list);
void delete_at_end(LinkedList* list);
Node* get_new_node(int data);