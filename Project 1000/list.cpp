// James Le
// Project 1000
// CS 271: Data Structure
// Dr. Jessen Havill

template <class T>
Node<T>::Node()
{
   item = NULL;
   next = NULL;
}

template <class T>
Node<T>::Node(T *initItem)
{
   item = initItem;
   next = NULL;
}

template <class T>
Node<T>::Node(T *initItem, Node<T> *initNext)
{
   item = initItem;
   next = initNext;
}

template <class T>
List<T>::List()
{
	head = NULL;
	count = 0;
}

template <class T>
List<T>::List(const List<T>& src)
{
	deepCopy(src);
}

template <class T>
List<T>::~List()
{
	deallocate();
}

template <class T>
List<T>& List<T>::operator=(const List<T>& src)
{
	deallocate();
	deepCopy(src);

	return *this;
}

template <class T>
int List<T>::length() const
{
	return count;
}

template <class T>
int List<T>::index(const T& item) const
{
	int index = 0;
	Node<T> *node = head;
	while ((node != NULL) && (!(*(node->item) == item)))
	{
		node = node->next;
		index++;
	}

	if (node == NULL)
		return -1;
	else
		return index;
}

template <class T>
void List<T>::append(T *item)
{
	Node<T> *node,
	        *newNode;

	newNode = new Node<T>(item);

	if (head != NULL)
	{
		node = _find(count - 1);
		node->next = newNode;
	}
	else
		head = newNode;

	count++;
}

template <class T>
void List<T>::insert(int index, T *item)
{
	if ((index < 0) || (index > count))
		throw IndexError();

	Node<T> *node;

	if (index == 0)
		head = new Node<T>(item, head);
	else
	{
		node = _find(index - 1);
		node->next = new Node<T>(item, node->next);
	}
	count++;
}

template <class T>
T *List<T>::pop(int index)
{
	if ((index < -1) || (index >= count))
		throw IndexError();

	if (index == -1)
		index = count - 1;

	Node<T> *node, *dnode;
	T *item;

	if (index == 0)
	{
		dnode = head;
		head = head->next;
		item = dnode->item;
		delete dnode;
	}
	else
	{
		node = _find(index - 1);
		if (node != NULL)
		{
			dnode = node->next;
			node->next = node->next->next;
			item = dnode->item;
			delete dnode;
		}
	}
	count --;
	return item;
}

template <class T>
T* List<T>::operator[](int index)
{
	if ((index < 0) || (index >= count))
		throw IndexError();

	Node<T> *node = _find(index);
	return node->item;
}

template <class T>
void List<T>::deepCopy(const List<T>& src)
{
	Node<T> *snode, *node;

	snode = src.head;
	if (snode != NULL)
	{
		node = head = new Node<T>(snode->item);
		snode = snode->next;
	}
	while (snode != NULL)
	{
		node->next = new Node<T>(snode->item);
		node = node->next;
		snode = snode->next;
	}

	count = src.count;
}

template <class T>
void List<T>::deallocate()
{
	Node<T> *node, *dnode;

	node = head;
	while (node != NULL)
	{
		dnode = node;
		node = node->next;
		delete dnode;
	}
}

template <class T>
void List<T>::remove(const T& item)
{
	if (head == NULL)
		return;

	Node<T> *toDelete;

	if (*(head->item) == item)
	{
		toDelete = head;
		head = head->next;
		delete toDelete;
		count--;
	}
	else
	{
	  Node<T> *node = head;
	  while ((node->next != NULL) && (!(*(node->next->item) == item)))
		  node = node->next;

	  if (node->next != NULL)
	  {
		  toDelete = node->next;
		  node->next = node->next->next;
		  delete toDelete;
		  count--;
	  }
	}
}

template <class T>
Node<T>* List<T>::_find(int index)  // used by append, insert, [], pop
{
	if ((index < 0) || (index >= count))
		throw IndexError();

	Node<T> *node = head;
	for (int i = 0; i < index; i++)
		node = node->next;

	return node;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const List<T>& list)
{
	Node<T> *node = list.head;

	while (node != NULL)
	{
		os << *(node->item) << " ";
		node = node->next;
	}
	os << std::endl;

	return os;
}
