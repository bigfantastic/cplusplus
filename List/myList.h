#pragma once

#include <iostream>

using namespace std;



template <typename T>

struct Node

{

	T data;

	Node* prev;

	Node* next;

	Node(const T& d = T(), Node* p = NULL, Node* n = NULL):data(d),prev(p),next(n){}

};



template<typename T, typename Ref, typename Ptr>

struct Iterator

{

	typedef Iterator<T, T&, T*> iterator;

	typedef Iterator<T, Ref, Ptr> self;



	Node<T>* node;



	//constructor

	Iterator(Node<T>* itr) :node(itr){}

	Iterator() : {}

	Iterator(const self& itr):node(itr.node){}



	bool operator==(const self& itr) const { return node == itr.node; }

	bool operator!=(const self& itr) const { return node != itr.node; }



	//dereference * - get the data of node

	Ref operator*() const { return node->data;}

	//member access -> - get the member of node

	Ptr operator->() const { return &(operator*()); }



	//++itr

	self& operator++()

	{

		node = node->next;

		return *this;

	}

	//itr++

	self operator++(int)

	{

		Iterator temp = *this;

		++(*this);

		return temp;

	}

	//--itr

	self& operator--()

	{

		node = node->prev;

		return *this;

	}

	//itr--

	self operator--(int)

	{

		Iterator temp = *this;

		--(*this);

		return temp;

	}

};



template<typename T>

class List

{

private:

	Node<T>* head;

	Node<T>* tail;

	int size;



public:

	//Iterator

	typedef Iterator<T, T&, T*> iterator;

	typedef Iterator<T, const T&, const T*> const_iterator;



	//Basic operations:Initialize, Insert, Erase

	//Constructor

	List() 

	{

		size = 0;

		head = new Node<T>();

		tail = new Node<T>();

		head->next = tail;

		tail->prev = head;

	}

	List(const List<T>& L)

	{

		size = L.size;

		head = new Node<T>();

		tail = new Node<T>();

		head->next = tail;

		tail->prev = head;



		const_iterator first = L.Begin();

		while (first != L.End())

		{

			Insert(End(), *first);

			++first;

		}

	}

	~List()

	{

		//cout << "Now destructed!" << endl;

		Clear();

		delete head;

        delete tail;

		//system("pause");

	}

	//Get the pointer of the first element

	iterator Begin();

	const_iterator Begin() const;

	//Get the pointer after the last element

	iterator End();

	const_iterator End() const;

	//Insert an item at current node

	iterator Insert(iterator itr, T item);

	//Erase the current node

	iterator Erase(iterator itr);

  //Insert an item in the end
  void Push_back(const T& item){Insert(End(),item);}

  //Insert an item at the beginning
  void Push_front(const T& item){Insert(Begin(),item);}

 

	//Clear the list

	void Clear();

};

//Get the pointer of the first element

template<typename T>

typename List<T>::iterator List<T>::Begin() 

{

	return head->next;

}



template<typename T>

typename List<T>::const_iterator List<T>::Begin() const

{

		return head->next;

}



//Get the pointer after the last element

template<typename T>

typename List<T>::iterator List<T>::End()  

{

	return tail;

}



template<typename T>

typename List<T>::const_iterator List<T>::End() const

{

	return tail;

}



//Insert an item at current node

template<typename T>

typename List<T>::iterator List<T>::Insert(iterator itr, T item)

{

	Node<T>* p = itr.node;

	Node<T>* newNode = new Node<T>(item,p->prev,p);

	p->prev->next = newNode;

	p->prev = newNode;



	size++;

	return newNode;

}

//Erase the current node

template<typename T>

typename List<T>::iterator List<T>::Erase(iterator itr)

{

	Node<T>* p = itr.node;

	p->prev->next = p->next;

	p->next->prev = p->prev;



	Node<T>* temp = p ->next;



	delete p;

	size--;

	return temp;

}



//clear the list

template<typename T>

void List<T>::Clear()

{

	iterator first = Begin();

	while (first != End())

		first = Erase(first);

}
