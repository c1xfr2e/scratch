
struct BTNode
{
	BTNode()
	{
		data = 0;
		left = 0;
		right = 0;
	}

	int data;
	BTNode* left;
	BTNode* right;
};

void BST_Insert(BTNode* p, int n)
{
	BTNode* node = new BTNode;
	node->data = n;
	
	BTNode* last;
	while (p)
	{
		last = p;
		if (n < p->data)
			p = p->left;
		else
			p = p->right;
	}	
	if (n < last->data)
		last->left = node;
	else
		last->right = node;
}	

void Preorder_T(BTNode* t)
{
	if (!t)
		return;
	printf("%d ", t->data);
	Preorder_T(t->left);
	Preorder_T(t->right);
}

void Inorder_T(BTNode* t)
{
	if (!t)
		return;
	Inorder_T(t->left);
	printf("%d ", t->data);
	Inorder_T(t->right);
}

void pre_t(BTNode* t)
{
	BTNode* s[128];
	int top = -1;
	while (t || top != -1)
	{
		if (t)
		{
			printf("%d ", t->data);
			s[++top] = t;
			t = t->left;
		}
		else
		{
			t = s[top--];
			t = t->right;
		}
	}
}

void in_t(BTNode* t)
{
	BTNode* s[128];
	int top = -1;
	while (t || top != -1)
	{
		if (t)
		{
			s[++top] = t;
			t = t->left;
		}
		else
		{
			t = s[top--];
			printf("%d ", t->data);
			t = t->right;
		}
	}
}

void post_t(BTNode* t)
{
	struct t_info
	{
		BTNode* p;
		int flag;
	};

	t_info s[128];
	int top = -1;
	t_info ti;
	ti.p = t;
	ti.flag = 0;
	while (ti.p || top != -1)
	{
		if (ti.p && ti.flag == 0)
		{
			t_info tmp;
			tmp.flag = 1;
			tmp.p = ti.p;
			s[++top] = tmp;
			ti.p = ti.p->left;
		}
		else
		{
			if (top == -1)
				break;

			if (s[top].flag == 1)
			{
				ti.p = s[top].p->right;
				ti.flag = 0;
				s[top].flag = 2;
			}
			else if (s[top].flag == 2)
			{
				printf("%d ", s[top].p->data);
				ti = s[--top];
			}
		}
	}
}

BTNode* travel_2(BTNode* p)
{
    BTNode* node = new BTNode;
    node->data = p->data;
    node->left = node->right = NULL;

    //printf("%d ", p->data);

    if (p->right)
    {
        node->right = travel_2(p->right);
    }

    BTNode* x = node;
    p = p->left;
    while (p)
    {
        BTNode* node1 = new BTNode;
        node1->data = p->data;
        node1->left = node1->right = NULL;
    
        x->left = node1;

        //printf("%d ", p->data);
        if (p->right)
        {
            node1->right = travel_2(p->right);
        }
        x = node1;
        p = p->left;
    }

    return node;
}