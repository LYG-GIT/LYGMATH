#pragma once

namespace LygLib
{
	//Node
	template<class T>
	class DListNode
	{
		template <class T> friend class DLinkedLists;
	public:
		DListNode()
		{
			data = 0;
			previous = nullptr;
			next = nullptr;
		}

	protected:
		T data;
		DListNode<T>* previous;
		DListNode<T>* next;
	};

	//DLists
	template<class T>
	class DLinkedLists
	{
	public:
		//DLists iterator
		class iterator
		{
		public:
			iterator();
			iterator(DLinkedLists<T>* container, DListNode<T>* node);
			~iterator();

			iterator& operator = (const iterator& iter);
			void operator ++ (int);
			void operator -- (int);
			bool operator !=(const iterator& iter);
			T operator * ();

			void start();
			T& item();
			bool valid();

		public:
			DListNode<T>* node;
			DLinkedLists<T>* container;
		};

	public:
		DLinkedLists();
		template<class T>
		DLinkedLists(DLinkedLists<T> lists);
		DLinkedLists(int n);
		DLinkedLists(int n, T elem);
		DLinkedLists(iterator begin, iterator end);
		~DLinkedLists();

		int size();
		bool empty();


		DLinkedLists<T>& operator = (DLinkedLists<T> lists);
		T front();
		T back();

		iterator insert(iterator iter, T item);

		void push_back(T data);
		void push_front(T data);
		void pop_front();
		void pop_back();
		void remove(T value);
		iterator erase(iterator pos);
		void clear();
		void sort();
		void reverse();

		iterator begin();
		iterator end();
		iterator last();

	public:
		DListNode<T>* head;
		DListNode<T>* tail;
		int length;
	};

	//iterator Achievements
	template <class T>
	DLinkedLists<T>::iterator::iterator()
	{
		this->container = nullptr;
		this->node = nullptr;
	}

	template <class T>
	DLinkedLists<T>::iterator::iterator(DLinkedLists<T>* container, DListNode<T>* node)
	{
		this->container = container;
		this->node = node;
	}

	template <class T>
	DLinkedLists<T>::iterator::~iterator()
	{
		this->container = nullptr;
		this->node = nullptr;
	}

	template <class T>
	typename DLinkedLists<T>::iterator& DLinkedLists<T>::iterator::operator = (const iterator& iter)
	{
		this->container = iter.container;
		this->node = iter.node;
		return *this;
	}

	template <class T>
	void DLinkedLists<T>::iterator::operator ++ (int)
	{
		if (node != nullptr)
		{
			node = node->next;
		}
	}

	template <class T>
	void DLinkedLists<T>::iterator::operator -- (int)
	{
		if (node != nullptr)
		{
			node = node->previous;
		}
	}

	template <class T>
	bool DLinkedLists<T>::iterator::operator !=(const iterator& iter)
	{
		return (this->node != iter.node);
	}

	template <class T>
	T DLinkedLists<T>::iterator::operator * ()
	{
		return node->data;
	}

	template <class T>
	void DLinkedLists<T>::iterator::start()
	{
		if (container != nullptr)
		{
			node = container->head;
		}
	}

	template <class T>
	T& DLinkedLists<T>::iterator::item()
	{
		return node->data;
	}

	template <class T>
	bool DLinkedLists<T>::iterator::valid()
	{
		return (node != nullptr);
	}

	//SLindedLists Achievements

	template <class T>
	DLinkedLists<T>::DLinkedLists()
	{
		head = nullptr;
		tail = nullptr;
		length = 0;
	}

	template <class T>
	DLinkedLists<T>::~DLinkedLists()
	{
		DListNode<T>* iter = head;
		DListNode<T>* next;
		while (iter != nullptr)
		{
			next = iter->next;
			delete iter;
			iter = next;
		}
	}
	template<class T>
	T DLinkedLists<T>::front()
	{
		return head->data;
	}

	template<class T>
	T DLinkedLists<T>::back()
	{
		return tail->data;
	}

	template<class T>
	typename DLinkedLists<T>::iterator DLinkedLists<T>::begin()
	{
		return iterator(this, head);
	}

	template<class T>
	typename DLinkedLists<T>::iterator DLinkedLists<T>::end()
	{
		return iterator(this, tail->next);
	}

	template<class T>
	typename DLinkedLists<T>::iterator DLinkedLists<T>::last()
	{
		return iterator(this, tail);
	}

	template <class T>
	void DLinkedLists<T>::push_back(T data)
	{
		if (head == 0)
		{
			head = tail = new DListNode<T>;
			head->data = data;
		}
		else
		{
			DListNode<T>* node = new DListNode<T>;
			node->data = data;
			node->next = tail->next;
			node->previous = tail;
			tail->next = node;
			tail = node;
		}
		length++;
	}

	template <class T>
	void DLinkedLists<T>::push_front(T data)
	{
		DListNode<T>* node = new DListNode<T>;
		node->data = data;
		node->next = head;
		if (head == nullptr)
			head->previous = nullptr;
		else
			head->previous = node;

		head = node;

		if (tail == nullptr)
		{
			tail = head;
		}

		length++;
	}

	template <class T>
	void DLinkedLists<T>::pop_front()
	{
		DListNode<T>* node = nullptr;
		if (head != nullptr)
		{
			node = head->next;
			node->previous = nullptr;
			delete head;
			head = node;

			if (head == nullptr)
			{
				tail = nullptr;
			}

			length--;
		}
	}

	template <class T>
	void DLinkedLists<T>::pop_back()
	{
		DListNode<T>* node = head;
		if (head != nullptr)
		{
			if (head == tail)
			{
				delete head;
				head = tail = nullptr;
			}
			else
			{
				node = tail->previous;				
				tail = node;
				delete node->next;
				tail->next = nullptr;
			}
			length--;
		}
	}

	template<class T>
	typename DLinkedLists<T>::iterator DLinkedLists<T>::insert(iterator iter, T item)
	{
		if (iter.container != this)
		{
			return iterator();
		}

		if (iter.node != nullptr)
		{
			DListNode<T>* tnode = new DListNode<T>;
			tnode->data = item;
			tnode->next = iter.node->next;
			iter.node->next->previous = tnode;
			tnode->previous = iter.node;
			iter.node->next = tnode;

			if (iter.node == tail)
			{
				tail = iter.node->next;
			}
			iter.node = tnode;
			length++;
			return iter;
		}
		else
		{
			push_back(item);
			iter++;
			length++;
			return iter;
		}
	}

	template<class T>
	void DLinkedLists<T>::remove(T value)
	{

	}

	template<class T>
	typename DLinkedLists<T>::iterator DLinkedLists<T>::erase(iterator pos)
	{
		/*DListNode<T>* curNode = head;
		if (pos.container != this)
		{
			return iterator();
		}

		if (pos.node == nullptr)
		{
			return pos;
		}

		if (pos.node == head)
		{
			pos++;
			pop_front();
			return pos;
		}
		else
		{
			while (curNode->next != pos.node)
			{
				curNode = curNode->next;
			}
			pos++;
			if (curNode->next == tail)
			{
				tail = curNode;
			}
			delete curNode->next;
			curNode->next = pos.node;
			length--;
			return pos;
		}*/
	}
}

