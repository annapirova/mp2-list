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
  bool operator==(const Node& list2) const;
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

	friend class List;
};

class List
{
  // любые поля
  Node* head;
public:
  List();

  bool isEmpty() 
  { 
	  return (head == nullptr); 
  }
//  List(const List& list2);
  List& operator=(const List& list2);
  ~List();

  void InsertToHead(const DataType& d); // вставить элемент d первым
  DataType ViewHead() 
  { 
	  return head->data;  
  }
  myiterator end() {
	  auto tmp = head;
	  while (tmp->next != nullptr) {
		  tmp = tmp->next;
	  }
	  return myiterator(tmp);
  }

  DataType ViewTail() { 
	  return *end(); 
  }

  void InsertToTail(const DataType& d); // вставить элемент d последним
  void Clean(); // удалить все звенья  
  void Delete(const DataType& d); // удалить звено со значением data = d				
  myiterator begin() 
  { 
	  return myiterator(head); 
  };

  //void InsertAfter(Node* node, const DataType& d); // вставить элемент d после звена node


  myiterator Search(const DataType& d); // найти указатель на звено со значением data = d


  //int GetSize(); // узнать число звеньев в списке
  //Node* GetHead(); // получить указатель на первое звено списка


  void Inverse(); // инвертировать список, т.е. звенья должны идти в обратном порядке


  //List Merge(Node* node, const List& list2); // создать список3, добавив список2 в текущий список после указателя node  
  //List Merge(const List& list2); // создать список3, добавив в конец текущего списка список2

  friend ostream& operator<<(ostream& os, const List& l);
  bool operator==(const List& list2) const; // списки равны, если элементы в них идут в одинаковом порядке
};

#endif