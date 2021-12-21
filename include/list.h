#ifndef __AISD_LIST__
#define __AISD_LIST__

#include <iostream>
using namespace std;

typedef int DataType;

struct Node
{
	DataType data;
	Node* next;
	// здесь могут быть конструкторы, методы, деструктор Node

	Node(DataType d = 0, Node* n = NULL);
	Node(const Node& node2);
	bool operator==(const Node& node2) const;
};

class myiterator
{
	Node* p;
public:
	myiterator(Node* tmp) : p(tmp) {};

	DataType& operator*() { return p->data; };

	myiterator& operator++()
	{
		p = p->next;
		return *this;
	};

	myiterator& operator++(int)
	{
		myiterator it(p);
		p = p->next;
		return it;
	};

	friend class List;
};

class List
{
	Node* head;
public:
	List();
	List(const List& list2);
	List& operator=(const List& list2);
	~List();
	bool isEmpty() const { return (head == nullptr); }
	void InsertToHead(const DataType& d); // вставить элемент d первым
	DataType ViewHead() { return head->data; }
	void InsertToTail(const DataType& d); // вставить элемент d последним
	void Clean(); // удалить все звенья
	void Delete(const DataType& d); // удалить звено со значением data = d
	myiterator begin() const { return myiterator(head); };
	void Delete(const myiterator& it);
	void InsertAfter(const myiterator& it, const DataType& d); // вставить элемент d после звена node
	myiterator Search(const DataType& d); // найти указатель на звено со значением data = d
	void Inverse(); // инвертировать список, т.е. звенья должны идти в обратном порядке
	List Merge(const myiterator& start, const List& list2); // создать список3, добавив список2 в текущий список после указателя node
	void MergeWith(const myiterator& start, const List& list2);
	void MadeUnique();
	//void Reordering(); // пересортировка списка: создать новый список, в кот сначала четные, потом нечетные звенья
	bool isCycle();
	friend ostream& operator<<(ostream& os, const List& l);
	//bool operator==(const List& list2) const; // списки равны, если элементы в них идут в одинаковом порядке
};

#endif