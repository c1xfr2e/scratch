#pragma once

struct Node
{
	Node(T val = 0)
	{
		prev = 0;
		next = 0;
		data = val;
	}

	Node* prev;
	Node* next;
	T data;
};

void List_Print(Node* cur)
{
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

void List_AppendNode(Node* cur, Node* next)
{
	cur->next = next;
	next->prev = cur;
}

void List_Erase(Node* node)
{
    
}

void List_DeleteLast(Node*& first)
{
	if (first == NULL)
		return;
	Node* prev = NULL;
	Node* last = first;
	while (last->next != NULL)
	{
		prev = last ;
		last = last->next;
	}
	delete last;
	if (prev != NULL)	
		prev->next = NULL;
	else
		first = NULL;
}

void List_DeleteKth(Node*& first, int k)
{
	if (first == NULL || k < 1)
		return;
	Node* prev = NULL;
	Node* kth = first;
	while (k > 1 && kth->next != NULL)
	{
		k--;
		prev = kth;
		kth = kth->next;
	}
	if (k != 1)
		return;
	if (prev != NULL)
		prev->next = kth->next;
	else
		first = NULL;
	delete kth;
}

void List_RemoveAfter(Node* p)
{
	if (p == NULL || p->next == NULL)
		return;
	Node* r = p->next;
	p->next = r->next;
	delete r;
}

void List_InsertAfter(Node* oldone, Node* newone)
{
	if (oldone == NULL || newone == NULL)
		return;
	newone->next = oldone->next;
	oldone->next = newone;
}

void List_RemoveKey(Node*& first, T val)
{
	Node* prev = NULL;
	Node* p = first;
	while (p != NULL)
	{
		if (p->data == val)
		{
			Node* next = p->next;
			delete p;
			p = next;
			if (prev != NULL)
				prev->next = p;
			else
				first = p;
		}
		else
		{
			prev = p;
			p = p->next;
		}
	}
}

Node* List_GetMax(Node* first)
{
	if (!first)
		return NULL;
	Node* max = first;
	for (Node* p = first->next; p; p = p->next)
		if (max->data < p->data)
			max = p;
	return max;
}

Node* List_GetMaxRecursively(Node* first)
{
	if (!first)
		return NULL;
	Node* p = List_GetMaxRecursively(first->next);
	if (p && first->data < p->data)
		return p;
	else
		return first;
}





