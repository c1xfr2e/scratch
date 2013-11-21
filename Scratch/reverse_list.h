
#include "LinkList.h"

Node* reverse_list(Node* list)
{
	Node* new_list = NULL;
	Node* next;
	while (list)
	{
		next = list->next;
		list->next = new_list;
		list->prev = next;
		new_list = list;
		list = next;
	}
	return new_list;
}

Node* reverse_list_re(Node* list)
{
	if (list == NULL)
		return NULL;
	if (list->next == NULL)
		return list;
	Node* next = list->next;
	Node* p = reverse_list_re(next);
	next->next = list;
	list->next = NULL;
	return p;
}

void do_reverse_list()
{
	Node* p1 = new Node(1);
	Node* p2 = new Node(2);
	Node* p3 = new Node(3);
	Node* p4 = new Node(4);
	Node* p5 = new Node(5);
	List_AppendNode(p1, p2);
	List_AppendNode(p2, p3);
	List_AppendNode(p3, p4);
	List_AppendNode(p4, p5);

	for (Node* cur = p1; cur; cur = cur->next)
	{
		printf("%d ", cur->data);
	}
	printf("\n");

	Node* pnew = reverse_list_re(p1);
	for (Node* cur = pnew; cur; cur = cur->next)
	{
		printf("%d ", cur->data);
	}
	printf("\n");
}
