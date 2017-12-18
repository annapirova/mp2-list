#ifndef __AISD_LIST__
#define __AISD_LIST__

#include <iostream>
using namespace std;

typedef int DataType;

struct Node
{
	DataType data;
	Node* next;

	Node(DataType _data = 0, Node* _next = NULL) {
		data = _data;
		next = _next;
	}
	~Node() {};
	Node(const Node &node2);
	Node& operator =(const Node& next);
	bool operator==(const Node& node2) const;
	// здесь могут быть конструкторы, методы, деструктор Node
};

class List
{
	Node* head;
	// любые поля
public:
	List() { head = NULL; }
	List(const Node &temp);
	List(const List& list2);
	List& operator=(const List& list2);
	~List() {
		Node *temp = head;
		Node *temp2 = head;
		if (temp != NULL)
		{
			while (temp->next != NULL)
			{
				temp2 = temp->next;
				delete temp;
				temp = temp2;
			}
			delete temp;
		}
	};

	void InsertToHead(const DataType& d); // вставить элемент d первым
	void InsertToTail(const DataType& d); // вставить элемент d последним
	void InsertAfter(Node* node, const DataType& d); // вставить элемент d после звена node
	void Delete(const DataType& d); // удалить звено со значением data = d
	Node* Search(const DataType& d); // найти указатель на звено со значением data = d
	void Clean(); // удалить все звенья
	int GetSize(); // узнать число звеньев в списке
	Node* GetHead() { return head; } // получить указатель на первое звено списка

	void Inverse(); // инвертировать список, т.е. звенья должны идти в обратном порядке
	List Merge(Node* node, const List& list2); // создать список3, добавив список2 в текущий список после указателя node  
	List Merge(const List& list2); // создать список3, добавив в конец текущего списка список2

	friend ostream& operator<<(ostream& os, const List& l);
	bool operator==(const List& list2) const;
};

#endif