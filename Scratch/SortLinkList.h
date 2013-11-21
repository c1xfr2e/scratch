
void InsertSort_List(Node* list)
{
	for (Node* p = list->next; p; p = p->next)
	{
		T temp = p->data;
		Node* pos = p;
		Node* p2 = p->prev;
		while (p2 && p2->data > temp)
		{
			p2->next->data = p2->data;
			pos = p2;
			p2 = p2->prev;
		}
		pos->data = temp;
	}
}

void partition_list(Node* beforeFirst, Node* first, Node* last, Node* afterLast)
{
	
}

void quick_sort_list(Node* list)
{
	
}

void unique_list(Node* list)
{
    Node* first = list;
    Node* next = first->next;
    while (next)
    {
        if (first->data == next->data)
        {
            Node* to_delete = next; 
            first->next = to_delete->next;
            if (to_delete->next)
            {
                to_delete->next->prev = first;
            }
            next = to_delete->next;
            delete to_delete;
        }
        else
        {
            first = next;
            next = first->next;
        }
    }
}

void list_remove(Node* list, T val)
{
    Node* cur = list;
    while (cur)
    {
        if (cur->data == val)
        {
            Node* to_del = cur;
            cur = cur->next;
            if (to_del->prev)
            {
                to_del->prev->next = to_del->next;
            }
            if (to_del->next)
            {
                to_del->next->prev = to_del->prev;
            }
            delete to_del;
        }
        else
        {
            cur = cur->next;
        }
    }
}

void do_sort_list()
{
	Node* p1 = new Node(100);
	Node* p2 = new Node(22);
	Node* p3 = new Node(22);
	Node* p4 = new Node(22);
	Node* p5 = new Node(100);
	Node* p6 = new Node(61);
	Node* p7 = new Node(61);
	Node* p8 = new Node(61);
	Node* p9 = new Node(33);
	Node* p10 = new Node(11);

	List_AppendNode(p1, p2);
	List_AppendNode(p2, p3);
	List_AppendNode(p3, p4);
	List_AppendNode(p4, p5);
	List_AppendNode(p5, p6);
	List_AppendNode(p6, p7);
	List_AppendNode(p7, p8);
	List_AppendNode(p8, p9);
	List_AppendNode(p9, p10);

	InsertSort_List(p1);


	for (Node* cur = p1; cur; cur = cur->next)
	{
		printf("%d ", cur->data);
	}
	printf("\n");

//     unique_list(p1);
//     for (Node* cur = p1; cur; cur = cur->next)
//     {
//         printf("%d ", cur->data);
//     }
//     printf("\n");

    list_remove(p1, 22);
    for (Node* cur = p1; cur; cur = cur->next)
    {
        printf("%d ", cur->data);
    }
    printf("\n");
}
