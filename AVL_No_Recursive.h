
#define LH 1
#define EH 0
#define RH -1

struct AVL_Node
{
    AVL_Node* left;
    AVL_Node* right;
    AVL_Node* parent;
    int key;
    int bf;
};

AVL_Node* CreateNode()
{
    AVL_Node* node = (AVL_Node*)malloc(sizeof(AVL_Node));
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->key = 0;
    node->bf = EH;
    return node;
}

void AVL_LeftRotate(AVL_Node* x, AVL_Node*& root)
{
    AVL_Node* y = x->right;
    x->right = y->left;
    if (y->left)
        y->left->parent = x;
    y->parent = x->parent;
    if (x == root)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void AVL_RightRotate(AVL_Node* x, AVL_Node*& root)
{
    AVL_Node* y = x->left;
    x->left = y->right;
    if (y->right)
        y->right->parent = x;
    y->parent = x->parent;
    if (x == root)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else 
        x->parent->right = y;
    y->right = x;
    x->parent = y;
}

void AVL_Rebalance_Insert(AVL_Node* x, AVL_Node*& root)
{
    AVL_Node* y = x->parent;
    bool taller = true;
    while (taller && y)
    {
        if (x == y->left)
        {
            if (y->bf == EH)
            {
                y->bf = LH;
                taller = true;
                x = y;
                y = y->parent;
            }
            else if (y->bf == RH)
            {
                y->bf = EH;
                taller = false;
            }
            else if (y->bf == LH)
            {
                if (x->bf == LH)
                {
                    y->bf = EH;
                    x->bf = EH;
                    AVL_RightRotate(y, root);
                    taller = false;
                }
                else
                {
                    AVL_Node* z = x->right;
                    if (z->bf == EH)
                    {
                        x->bf = EH;
                        y->bf = EH;
                    }
                    else if (z->bf == LH)
                    {
                        x->bf = EH;
                        y->bf = RH;
                    }
                    else
                    {
                        x->bf = LH;
                        y->bf = EH;
                    }
                    z->bf = EH;
                    AVL_LeftRotate(x, root);
                    AVL_RightRotate(y, root);
                    taller = false;
                }   
            }
        }
        else
        {
            if (y->bf == LH)
            {
                y->bf = EH;
                taller = false;
            }
            else if (y->bf == EH)
            {
                y->bf = RH;
                taller = true;
                x = y;
                y = y->parent;
            }
            else if (y->bf == RH)
            {
                if (x->bf == RH)
                {
                    x->bf = EH;
                    y->bf = EH;
                    AVL_LeftRotate(y, root);
                    taller = false;
                }
                else
                {
                    AVL_Node* z = x->left;
                    if (z->bf == EH)
                    {
                        x->bf = EH;
                        y->bf = EH;
                    }
                    else if (z->bf == LH)
                    {
                        x->bf = RH;
                        y->bf = EH;
                    }
                    else 
                    {
                        x->bf = EH;
                        y->bf = LH;
                    }
                    z->bf = EH;
                    AVL_RightRotate(x, root);
                    AVL_LeftRotate(y, root);
                    taller = false;
                }
            }
        }
    }
}

void AVL_Rebalance_Delete(AVL_Node*& root, AVL_Node* x, bool del_left)
{
    AVL_Node* shorter_child = NULL;
    if (x->left == NULL && x->right == NULL)
    {
        x->bf = EH;
        shorter_child = x;
        x = x->parent;
    }
    else
    {
        shorter_child = del_left? x->left : x->right;
    }

    bool shorter = true;
    while (shorter && x)
    {
        if (shorter_child == x->left)
        {
            if (x->bf == LH)
            {
                x->bf = EH;
                shorter_child = x;
                x = x->parent;
            }
            else if (x->bf == EH)
            {
                x->bf = RH;
                shorter = false;
            }
            else // x->bf == RH
            {
                AVL_Node* y = x->right;
                if (y->bf == LH)
                {
                    AVL_Node* z = y->left;
                    if (z->bf == EH)
                    {
                        x->bf = EH;
                        y->bf = EH;
                    }
                    else if (z->bf == LH)
                    {
                        x->bf = EH;
                        y->bf = RH;
                    }
                    else // z->bf == RH
                    {
                        x->bf = LH;
                        y->bf = EH;
                    }
                    z->bf = EH;
                    AVL_RightRotate(y, root);
                    AVL_LeftRotate(x, root);
                    shorter = false;
                }
                else if (y->bf == EH)
                {
                    x->bf = RH;
                    y->bf = LH;
                    AVL_LeftRotate(x, root);
                    shorter = false;
                }
                else
                {
                    x->bf = EH;
                    y->bf = EH;
                    AVL_LeftRotate(x, root);
                    shorter_child = y;
                    x = y->parent;
                }
            }
        }
        else // shorter_child == x->right
        {
            if (x->bf == LH)
            {
                AVL_Node* y = x->left;
                if (y->bf == LH)
                {
                    x->bf = EH;
                    y->bf = EH;
                    AVL_RightRotate(x, root);
                    shorter_child = y;
                    x = shorter_child->parent;
                }
                else if (y->bf == EH)
                {
                    x->bf = LH;
                    y->bf = RH;
                    AVL_RightRotate(x, root);
                    shorter = false;
                }
                else
                {
                    AVL_Node* z = y->right;
                    if (z->bf == LH)
                    {
                        x->bf = RH;
                        y->bf = EH;
                    }
                    else if (z->bf == EH)
                    {
                        x->bf = EH;
                        y->bf = EH;
                    }
                    else
                    {
                        x->bf = EH;
                        y->bf = LH;
                    }
                    z->bf = EH;
                    AVL_LeftRotate(y, root);
                    AVL_RightRotate(x, root);
                    shorter = false;
                }
            }
            else if (x->bf == EH)
            {
                x->bf = RH;
                shorter = false;
            }
            else
            {
                x->bf = EH;
                shorter_child = x;
                x = x->parent;
            }
        }
    }
}

void AVL_Insert(AVL_Node*& root, int key)
{
    AVL_Node* new_node = CreateNode();
    new_node->key = key;

    AVL_Node* y = NULL;
    AVL_Node* x = root;
    while (x != NULL)
    {
        y = x;
        if (key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    if (y == NULL)
        root = new_node;
    else if (key < y->key)
        y->left = new_node;
    else 
        y->right = new_node;
    new_node->parent = y;
    AVL_Rebalance_Insert(new_node, root);
}

void AVL_Delete(AVL_Node*& root, int key)
{
    AVL_Node* x = root;
    while (x)
    {
        if (key < x->key)
            x = x->left;
        else if (key > x->key)
            x = x->right;
        else
            break;
    }
    if (x == NULL)
        return;
    AVL_Node* del = x;
    if (del->left != NULL && del->right != NULL)
    {
        del = del->right;
        while (del->left)
            del = del->left;
    }
    AVL_Node* y;
    if (del->left)
        y = del->left;
    else
        y = del->right;
    if (y)
        y->parent = del->parent;
    if (del->parent == NULL)
        root = y;    

    AVL_Node* p = del->parent;
    bool del_left = true;
    if (del == p->left)
    {
        p->left = y;
        del_left = true;
    }
    else
    {
        del->parent->right = y;
        del_left = false;
    }
    if (x != del)
        x->key = del->key;
    delete del;
    AVL_Rebalance_Delete(root, p, del_left);
}