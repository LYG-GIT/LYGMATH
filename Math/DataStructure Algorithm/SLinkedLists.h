#pragma once

namespace LygLib
{
	//Node
	template<class T>
	class SListNode
	{
		template <class T> friend class SLinkedLists;
	public:
		SListNode()
		{
			data = 0;
			next = nullptr;
		}

	protected:
		T data;
		SListNode<T>* next;
	};

	//SLists
	template<class T>
	class SLinkedLists
	{
	public:
		//SLists iterator
		class iterator
		{
		public:
			iterator();
			iterator(SLinkedLists<T>* container, SListNode<T>* node);
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
			SListNode<T>* node;
			SLinkedLists<T>* container;
		};

	public:
		SLinkedLists();
		template<class T>
		SLinkedLists(SLinkedLists<T> lists);
		SLinkedLists(int n);
		SLinkedLists(int n, T elem);
		SLinkedLists(iterator begin, iterator end);
		~SLinkedLists();

		int size();
		bool empty();
		

		SLinkedLists<T>& operator = (SLinkedLists<T> lists);
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
		SListNode<T>* head;
		SListNode<T>* tail;
		int length;
	};

	//iterator Achievements
	template <class T>
	SLinkedLists<T>::iterator::iterator()
	{
		this->container = nullptr;
		this->node = nullptr;
	}

	template <class T>
	SLinkedLists<T>::iterator::iterator(SLinkedLists<T>* container, SListNode<T>* node)
	{
		this->container = container;
		this->node = node;
	}

	template <class T>
	SLinkedLists<T>::iterator::~iterator()
	{
		this->container = nullptr;
		this->node = nullptr;
	}

	template <class T>
	typename SLinkedLists<T>::iterator& SLinkedLists<T>::iterator::operator = (const iterator& iter)
	{
		this->container = iter.container;
		this->node = iter.node;
		return *this;
	}

	template <class T>
	void SLinkedLists<T>::iterator::operator ++ (int)
	{
		if (node != nullptr)
		{
			node = node->next;
		}
	}

	template <class T>
	void SLinkedLists<T>::iterator::operator -- (int)
	{
		iterator curIter = container->begin();
		iterator preIter = iterator();

		if (*this != container->begin())
		{
			while (curIter != *this)
			{
				preIter = curIter;
				curIter++;
			}
			*this = preIter;
		}
		else
		{
			*this = iterator();
		}
	}

	template <class T>
	bool SLinkedLists<T>::iterator::operator !=(const iterator& iter)
	{
		return (this->node != iter.node);
	}

	template <class T>
	T SLinkedLists<T>::iterator::operator * ()
	{
			return node->data;	
	}

	template <class T>
	void SLinkedLists<T>::iterator::start()
	{
		if (container != nullptr)
		{
			node = container->head;
		}
	}

	template <class T>
	T& SLinkedLists<T>::iterator::item()
	{
		return node->data;
	}
	
	template <class T>
	bool SLinkedLists<T>::iterator::valid()
	{
		return (node != nullptr);
	}

	//SLindedLists Achievements

	template <class T>
	SLinkedLists<T>::SLinkedLists()
	{
		head = nullptr;
		tail = nullptr;
		length = 0;
	}

	template <class T>
	SLinkedLists<T>::~SLinkedLists()
	{
		SListNode<T>* iter = head;
		SListNode<T>* next;
		while (iter != nullptr)
		{
			next = iter->next;
			delete iter;
			iter = next;
		}
	}
	template<class T>
	T SLinkedLists<T>::front()
	{
		return head->data;
	}

	template<class T>
	T SLinkedLists<T>::back()
	{
		return tail->data;
	}

	template<class T>
	typename SLinkedLists<T>::iterator SLinkedLists<T>::begin()
	{
		return iterator(this, head);
	}

	template<class T>
	typename SLinkedLists<T>::iterator SLinkedLists<T>::end()
	{
		return iterator(this, tail->next);
	}

	template<class T>
	typename SLinkedLists<T>::iterator SLinkedLists<T>::last()
	{
		return iterator(this, tail);
	}

	template <class T>
	void SLinkedLists<T>::push_back(T data)
	{
		if (head == 0)
		{
			head = tail = new SListNode<T>;
			head->data = data;
		}
		else
		{
			SListNode<T>* node = new SListNode<T>;
			node->data = data;
			node->next = tail->next;
			tail->next = node;
			tail = node;
		}
		length++;
	}

	template <class T>
	void SLinkedLists<T>::push_front(T data)
	{
		SListNode<T>* node = new SListNode<T>;
		node->data = data;
		node->next = head;
		head = node;

		if (tail == nullptr)
		{
			tail = head;
		}

		length++;
	}

	template <class T>
	void SLinkedLists<T>::pop_front()
	{
		SListNode<T>* node = nullptr;
		if (head != nullptr)
		{
			node = head->next;
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
	void SLinkedLists<T>::pop_back()
	{
		SListNode<T>* node = head;
		if(head != nullptr)
		{
			if (head == tail)
			{
				delete head;
				head = tail = nullptr;
			}
			else
			{
				while (node->next != tail)
				{
					node = node->next;
				}
				tail = node;
				delete node->next;
				tail->next = nullptr;
			}
			length--;
		}
	}
	
	template<class T>
	typename SLinkedLists<T>::iterator SLinkedLists<T>::insert(iterator iter, T item)
	{
		if (iter.container != this)
		{
			return iterator();
		}

		if (iter.node != nullptr)
		{
			SListNode<T>* tnode = new SListNode<T>;
			tnode->data = item;
			tnode->next = iter.node->next;
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
	void SLinkedLists<T>::remove(T value)
	{
		
	}

	template<class T>
	typename SLinkedLists<T>::iterator SLinkedLists<T>::erase(iterator pos)
	{
		SListNode<T>* curNode = head;
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
		}
	}
}

