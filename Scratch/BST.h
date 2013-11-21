
#pragma once

template <class Key, class Value>
struct Node
{
	Key key;
	Value value;
	Node* left;
	Node* right;
	int N;
	Node(const Key& k, const Value& v, int n)
		: key(k), value(v), N(n), left(0), right(0)
	{}
};

template <class Key, class Value>
class BST
{
private:
	typedef Node<Key,Value> _Node;
	_Node* m_root;

public:
	int size() { return size(m_root); }
	int size(_Node* x) { return x? x->N : 0; }
	
	Value* get(const Key& key) { return get(m_root, key); }
	Value* get(_Node* x, const Key& key)
	{
		if (x == 0)
			return 0;
		if (key < x->key)
			return  get(x->left, key);
		else if (key > x->key)
			return get(x->right, key);
		else
			return &x->value;
	}

	void put(const Key& key, const Value& value)
	{
		m_root = put(m_root, key, value);
	}
	_Node* put(_Node* x, const Key& key, const Value& value)
	{
		if (x == 0)
			return new _Node(key, value, 1);
		if (key < x->key)
			return put(x->left, key, value);
		else if (key > x->key)
			return put(x->right, key, value);
		else
			x->value = value;
		x->N = size(x->left) + size(x->right) + 1;
		return x;
	}
};










