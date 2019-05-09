
// int max(int a, int b)
// {
// 	return a > b? a : b;
// }

struct avl_node
{
	avl_node* l_child;
	avl_node* r_child;
	int val;
	int height;
};

avl_node* create_node()
{
	avl_node* p = (avl_node*)malloc(sizeof(avl_node));
	p->l_child = p->r_child = NULL;
	p->val = 0;
	p->height = 1;
	return p;
}

int height(avl_node* p)
{
	return p == NULL? 0 : p->height;
}

void avl_right_rotate(avl_node*& k)
{
	avl_node* kl = k->l_child;
	k->l_child = kl->r_child;
	kl->r_child = k;
	k->height = max(height(k->l_child), height(k->r_child)) + 1;;
	kl->height = max(height(kl->l_child), k->height) + 1;
	k = kl;
}

void avl_left_rotate(avl_node*& k)
{	
	avl_node* kr = k->r_child;
	k->r_child = kr->l_child;
	kr->l_child = k;
	k->height = max(height(k->l_child), height(k->r_child)) + 1;;
	kr->height = max(k->height, height(k->r_child)) + 1;
	k = kr;
}

void avl_insert(avl_node*& p, int n)
{
	if (!p)
	{
		p = create_node();
		p->val = n;
		return;
	}
	else if (n < p->val)
	{
		avl_insert(p->l_child, n);
		if (height(p->l_child) - height(p->r_child) == 2)
		{
			if (n < p->l_child->val)
			{
				avl_right_rotate(p);
			}
			else
			{
				avl_left_rotate(p->l_child);
				avl_right_rotate(p);
			}
		}
	}
	else if (n > p->val)
	{
		avl_insert(p->r_child, n);
		if (height(p->r_child) - height(p->l_child) == 2)
		{
			if (n > p->r_child->val)
			{
				avl_left_rotate(p);
			}
			else
			{
				avl_right_rotate(p->r_child);
				avl_left_rotate(p);
			}
		}
	}
	else
	{}

	p->height = max(height(p->l_child), height(p->r_child)) + 1;
}

// 使用平衡因子
enum BalanceFactor
{
    LH, // Left Higher
    EH,
    RH
};

struct AVLNode
{
    AVLNode* left;
    AVLNode* right;
    int key;
    BalanceFactor bf;
};

AVLNode* CreateAVLNode()
{
    AVLNode* p = (AVLNode*)malloc(sizeof(AVLNode));
    p->left = p->right = NULL;
    p->key = 0;
    p->bf = EH;
    return p;
}

void LeftRotate(AVLNode*& k0)
{
    AVLNode* k1 = k0->right;
    k0->right = k1->left;
    k1->left = k0;
    k0 = k1;
}

void RightRotate(AVLNode*& k0)
{
    AVLNode* k1 = k0->left;
    k0->left = k1->right;
    k1->right = k0;
    k0 = k1;
}

void LeftBalance(AVLNode*& k0)
{
    AVLNode*& k1 = k0->left;
    AVLNode*& k2 = k1->right;
    switch (k1->bf)
    {
    case LH:
        k0->bf = k1->bf = EH;
        RightRotate(k0);
        break;
    case RH:
        switch (k2->bf)
        {
        case LH:
            k1->bf = EH;
            k0->bf = RH;
            break;
        case EH:
            k1->bf = k0->bf = EH;
            break;
        case RH:
            k1->bf = LH;
            k0->bf = EH;
            break;
        }
        k2->bf = EH;
        LeftRotate(k1);
        RightRotate(k0);
        break;
    }
}

void RightBalance(AVLNode*& k0)
{
    AVLNode*& k1 = k0->right;
    AVLNode*& k2 = k1->left;
    switch (k1->bf)
    {
    case RH:
        k0->bf = k1->bf = EH;
        LeftRotate(k0);
        break;
    case LH:
        switch (k2->bf)
        {
        case LH:
            k1->bf = RH;
            k0->bf = EH;
            break;
        case EH:
            k1->bf = k0->bf = EH;
            break;
        case RH:
            k1->bf = EH;
            k0->bf = LH;
            break;
        }
        k2->bf = EH;
        RightRotate(k1);
        LeftRotate(k0);
        break;
    }
}

bool AVLInsert(AVLNode*& r, int key, bool& taller)
{
    if (r == NULL)
    {
        r = CreateAVLNode();
        r->key = key;
        taller = true;
    }
    else if (key < r->key)
    {
        if (!AVLInsert(r->left, key, taller))
            return false;
        if (taller)
        {
            switch(r->bf)
            {
            case LH:
                LeftBalance(r);
                taller = false;
                break;
            case EH:
                r->bf = LH;
                taller = true;
                break;
            case RH:
                r->bf = EH;
                taller = false;
                break;
            }
        }    
    }
    else if (key > r->key)
    {
        if (!AVLInsert(r->right, key, taller))
            return false;
        if (taller)
        {
            switch(r->bf)
            {
            case LH:
                r->bf = EH;
                taller = false;
                break;
            case EH:
                r->bf = RH;
                taller = true;
                break;
            case RH:
                RightBalance(r);
                taller = false;
                break;
            }
        }    
    }
    else
    {
        taller = false;
        return false;
    }

    return true;
}







