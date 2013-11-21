
typedef struct hash
{
    unsigned int bits;
} hash;

void hash_init(hash* h)
{
    h->bits = 0;
}

void hash_insert(hash* h, int key)
{
    h->bits |= ((unsigned int)1 << key);
}

void hash_delete(hash* h, int key)
{
    h->bits &= ~((unsigned int)1 << key);
}

bool hash_search(hash* h, int key)
{
    return ((h->bits & ((unsigned int)1 << key)) != 0);
}