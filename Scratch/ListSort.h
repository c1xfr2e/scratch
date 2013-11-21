
struct node
{
	node* prev;
	node* next;
	int data;
};

node* create_node()
{
	node* p = (node*)malloc(sizeof(node));
	p->prev = NULL;
	p->next = NULL;
	p->data = 0;
	return p;
}

node* create_list(int* a, int n)
{
	node* head = create_node();
	head->prev = NULL;
	head->prev = NULL;
	head->data = -1;
	node* cur = head;
	for (int i = 0; i < n; ++i)
	{
		node* p = create_node();
		p->data = a[i];
		p->next = NULL;
		p->prev = cur;
		cur->next = p;
		cur = p;
	}
	return head;
}

void swap_node(node* a, node* b)
{
	if (a == b)
	{
		return;
	}

	if (a->next == b)
	{
		if (a->prev)
		{
			a->prev->next = b;
		}
		b->prev = a->prev;
		a->prev = b;
		if (b->next)
		{
			b->next->prev = a;
		}
		a->next = b->next;
		b->next = a;
		return;
	}

	if (b->next == a)
	{
		swap_node(b, a);
		return;
	}

	node* tmp = b->next;
	b->next = a->next;
	a->next = tmp;
	tmp = b->prev;
	b->prev = a->prev;
	a->prev = tmp;
	if (a->prev)
	{
		a->prev->next = a;
	}
	if (a->next)
	{
		a->next->prev = a;
	}
	if (b->prev)
	{
		b->prev->next = b;
	}
	if (b->next)
	{
		b->next->prev = b;
	}
}

node* find(node* list, int i)
{
	while (list)
	{
		if (list->data == i)
		{
			break;
		}
		list = list->next;
	}
	return list;
}

void list_insert_sort(node* list)
{
	node* first = list->next;
	if (!first)
	{
		return;
	}
	node* p = first->next;
	while (p)
	{
		node* p2 = p->prev;
		while (p2 != list && p2->data > p->data)
		{
			p2 = p2->prev;
		}
		node* next = p->next;
		if (p2->next != p)
		{
			p->prev->next = next;
			if (next)
			{
				next->prev = p->prev;
			}
			p->next = p2->next;
			p->prev = p2;
			p2->next->prev = p;
			p2->next = p;
		}
		p = next;
	}
}

void list_selection_sort(node* list)
{
	node* first = list->next;
	if (!first)
	{
		return;
	}

	while (first)
	{
		node* min = first;
		for (node* p = first->next; p; p = p->next)
		{
			if (p->data < min->data)
			{
				min = p;
			}
		}
		node* next = first->next;
		swap_node(min, first);
		first = next;
	}
}

void list_bubble_sort(node* list)
{	
	node* first = list->next;
	if (!first)
	{
		return;
	}

	node* last = 0;
	while (last != list->next)
	{
		node* p = list->next;
		while (p->next != last)
		{
			node* next = p->next;
			if (next && p->data > next->data)
			{
				swap_node(p, next);
			}
			p = next;
		}
		last = p;
	}
}