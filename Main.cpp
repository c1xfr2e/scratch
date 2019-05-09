
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "common.h"
#include "insert_sort.h"
#include "bubble.h"
#include "selection.h"
#include "shell.h"
#include "heapsort.h"
#include "memcpy.h"
#include "merge.h"
#include "quick.h"
#include "reverse_list.h"
#include "SortLinkList.h"
#include "unique.h"
#include "expr_calc.h"
#include "StrIndex.h"
#include "Sort.h"
#include "btree_travel.h"
#include "AVL.h"
#include "AVL_No_Recursive.h"
#include "BinaryTreeTravel.h"
#include "hash.h"
#include "rotate.h"
#include "kselect.h"
#include "circular_queue.h"
#include "factorial.h"
#include "tree_travel.h"

#include <vector>
typedef std::vector<int> SearchResult;

void SearchTree(AVL_Node* p, int key1, bool& b_key1, int key2, bool& b_key2, SearchResult& res1, SearchResult& res2)
{
    if (p == NULL)
        return;

    if (p->key == key1)
        b_key1 = true;
    if (p->key == key2)
        b_key2 = true;

    bool b1 = false;
    bool b2 = false;
    SearchTree(p->left, key1, b1, key2, b2, res1, res2);
    if (b1)
    {
        res1.insert(res1.begin(), 1);
        b_key1 = true;
    }
    if (b2)
    {
        res2.insert(res2.begin(), 1);
        b_key2 = true;
    }

    if (b1 && b2)
        return;

    b1 = false;
    b2 = false;
    SearchTree(p->right, key1, b1, key2, b2, res1, res2);
    if (b1)
    {
        res1.insert(res1.begin(), 0);
        b_key1 = true;
    }
    if (b2)
    {
        res2.insert(res2.begin(), 0);
        b_key2 = true;
    }
}

int main()
{
  DoTreeTravel();

	int i = 0;
	int f = factorial(i);

	unsigned long size = 1024*1024*1024;
	char* mem = new char[size];
	DWORD time = timeGetTime();
	memset(mem, 'A', size);
	DWORD duration = timeGetTime() - time;
	printf("%d ", duration);

	do_reverse_list();


	CircularLinkQueue qu;
	int queuedata[] = {10,9,8,7,6,5,4,3,2,1,0};
	for (int i = 0; i < _countof(queuedata); ++i)
		qu.enqueue(queuedata[i]);
	while (!qu.empty())
	{
		printf("%d ", qu.dequeue());
	}

	memset(queuedata, 0, sizeof(queuedata));

	int nodedata[] = {2000,9,8,7,2,2,6,2,5,4,3,2,1,0,2,2, 1000};
	Node* cur = NULL;
	for (int i = 0; i < _countof(nodedata); ++i)
	{
		Node* newnode =  new Node(nodedata[i]);
		newnode->next = cur;
		cur = newnode;
	}

	Node* new_Node = new Node(222);
	new_Node->next = (Node*)0x12345678;
	List_InsertAfter(cur->next->next->next->next, new_Node);
	List_Print(cur);

	printf("\n");

	List_RemoveKey(cur, 2);
	List_Print(cur);

	printf("\n%d %d\n", List_GetMax(cur)->data, List_GetMaxRecursively(cur)->data);

    int test[] = {5,2,1,7,8,3,6,4,0};
    int k = select(test, _countof(test), 4);
    
    
    
    int pivot = ITA_partition(test, 0, 7);

    int seq[] = {1,2,3,4,5,6,7,8};
    rotate_recursive(seq, 0, 6, _countof(seq));

    hash h;
    hash_init(&h);
    for (int i = 0; i < 32; ++i)
    {
        hash_insert(&h, i);
        if (hash_search(&h, i))
        {
            printf("%d ", i);
        }
    }
    
    printf("\n");
    hash_delete(&h, 1);
    hash_delete(&h, 13);
    hash_delete(&h, 10);
    hash_delete(&h, 15);
    hash_delete(&h, 25);
    for (int i = 0; i < 32; ++i)
    {
        if (hash_search(&h, i))
        {
            printf("%d ", i);
        }
    }

    Travel(0);

    AVL_Node* avl_root_1 = NULL;
    int x[] = {100, 50, 150, 30, 80, 120, 200, 40, 60, 90, 110, 130, 180, 250,
        95, 140, 190, 220, 300, 350};
	for (int i = 0; i < _countof(x); ++i)
	{
        AVL_Insert(avl_root_1, x[i]);
	}

    AVL_Delete(avl_root_1, 40);
    
    bool b_key1 = false, b_key2 = false;
    SearchResult res1, res2;
    SearchTree(avl_root_1, 30, b_key1, 95, b_key2, res1, res2);


    int y[10] = {3, 2, 1, 4, 5, 6, 7, 10, 9, 8};
    bool taller = false;
    AVLNode* avl_root = NULL;
    for (int i = 0; i < _countof(y); ++i)
    {
        AVLInsert(avl_root, y[i], taller);
    }

	BTNode* root = new BTNode;
	root->data = 50;
	BST_Insert(root, 40);
	BST_Insert(root, 30);
	BST_Insert(root, 45);
	BST_Insert(root, 80);
	BST_Insert(root, 70);
	BST_Insert(root, 90);
	post_t(root);  

    printf("\n\n");

    BTNode* root_copy = travel_2(root);
    post_t(root_copy);  

    int heap[] = {1, 50, 30, 40, 10, 5, 8, 20, 2, 2, 23, 4555, 6, 7};
    insert_sort_2(heap, heap+_countof(heap));

    int p[] = {1, 1, 1, 1, 22, 22, 22, 22, 3, 3, 4, 4};
    int new_len = unique(p, _countof(p));

	do_reverse_list();
	do_sort_list();

    int a[] = {1, 34, 6, 323, 2, 3, 67, 13, 98, 32, 55};
    quick_sort_1(a, 0, _countof(a) - 1);

    int b[100];
    for (int i = 0; i < _countof(b); ++i)
    {
        b[i] = 100 - i;
    }
    quick_sort_1(b, 0, _countof(b) - 1);

	int m2[] = {51, 1, 3, 3, 3, 5, 77, 300, 2, 51, 4, 53, 6, 8, 10, 100, 50};
	//quick_sort_2(m2, _countof(m2));

    char rpn[30];
    To_ReversePolishNotation("9+(3-1)*3+2/2", rpn);
    int n = ToValue(rpn); 

	int ttt[] = {100, 77, 300, 50};
	int* mm = part(ttt, ttt + 4, ttt);


    int result = index_kmp("xxx_ababaaab_yyy_ababaaaba_zzz", "ababaaaba");

	int k_result = getk(m2, m2 + _countof(m2), 16, m2);

	for (int i = 0; i < _countof(m2); ++i)
	{
		printf("%d ", getk(m2, m2 + _countof(m2), i, m2));
	}
	printf("\n");


    return 0;
}
