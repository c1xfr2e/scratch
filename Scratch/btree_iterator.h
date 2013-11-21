
struct btnode
{
    btnode* left;
    btnode* right;
    btnode* parent;
    int val;
};

class Tree
{
public:
    Tree() : m_root(NULL) {}
    

private:
    btnode* m_root;
};