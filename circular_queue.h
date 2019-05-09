
#include "LinkList.h"

class CircularLinkQueue
{
public:
	CircularLinkQueue() : m_last(NULL) {}

	bool empty() { return m_last == NULL; }

	void enqueue(T key)
	{
		if (m_last == NULL)
		{
			m_last = new Node;
			m_last->data = key;
			m_last->next = m_last;
		}
		else
		{
			Node* p = new Node;
			p->data = key;
			p->next = m_last->next;
			m_last->next = p;
			m_last = p;
		}
	}

	T dequeue()
	{
		if (m_last->next == m_last)
		{
			T ret = m_last->data;
			delete m_last;
			m_last = NULL;
			return ret;
		}
		Node* p = m_last->next;
		m_last->next = m_last->next->next;
		return p->data;
	}

private:
	Node* m_last;
};

template<class T>
class Queue
{
public:
    Queue(int size)
    {
        m_buf = new T[size];
        m_size = size;
		m_head = 0;
		m_tail = 0;
    }

	bool empty()
	{
		return m_head = m_tail;
	}
		
	void enqueue(const T& val)
	{
		m_buf[m_tail] = val;
		m_tail = (m_tail + 1) % m_size;
	}

	void dequeue()
	{
		m_head = (m_head + 1) % m_size;
	}

	T& get_head()
	{
		return m_buf[m_head];
	}

private:
    T* m_buf;
    int m_size;
	int m_head;
	int m_tail;
};