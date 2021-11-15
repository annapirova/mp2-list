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

	friend class List;
};

class List
{
  // любые поля
  Node* head;
public:
  List();

  bool isEmpty() { return (head == nullptr); }
//  List(const List& list2);
//  List& operator=(const List& list2);
  ~List();

  void InsertToHead(const DataType& d); // вставить элемент d первым
  DataType ViewHead() { return head->data;  }
  void InsertToTail(const DataType& d); // вставить элемент d последним
  void Clean(); // удалить все звенья  
  void Delete(const DataType& d);// удалить звено со значением data = d
  int Find(const DataType& d);				
  myiterator begin() { return myiterator(head); };
  myiterator Search(const DataType& d);
  friend ostream& operator<<(ostream& os, const List& l);

  void Delete(const myiterator& start, const myiterator& finish) 
  {
	  Node* that = head;
	  Node* prev;
	  Node* tmp;
	  myiterator i=head->next;
	  while (i.p != start.p)
	  {
		  i = that->next->next;
		  that = that->next;
	  }

	  prev = that;
	  that = that->next;
	  while (i.p != finish.p)
	  {
		  tmp = that;
		  that = that->next; 
		  delete tmp;
		  i= that->next;
	  };
	  tmp = that;
	  that = that->next; 
	  delete tmp;
	  i = that->next;
	  tmp = that;
	  that = that->next;
	  delete tmp;
	  i = that->next;

	  prev->next = that;


  };


  

  void MadeUnique() 
  {

	  Node* tmp;
	  Node* prev=head;
	  myiterator i=nullptr;
	  myiterator j=nullptr;
	  if (head == nullptr)
		  return;

	  i = head->next;
	  j = head;
	  while (i.p != nullptr)
	  {
		  j = head;
		  
		  while ((i.p != j.p) && (j.p->data != i.p->data))
		  {
			  j.p = j.p->next;
		  }
		  if (i.p != j.p)
		  {
			  prev->next = i.p->next;
			  tmp = i.p;
			  i.p = i.p->next; 
			  delete tmp;

			  
		  }
		  else
		  {
			  prev = prev->next;
			  i = i.p->next;
		  }
	  }
  }; // исключить повторяющиеся звенья




  //void InsertAfter(Node* node, const DataType& d); // вставить элемент d после звена node
  //Node* Search(const DataType& d); // найти указатель на звено со значением data = d
  //int GetSize(); // узнать число звеньев в списке
  //Node* GetHead(); // получить указатель на первое звено списка

  //void Inverse(); // инвертировать список, т.е. звенья должны идти в обратном порядке
  //List Merge(Node* node, const List& list2); // создать список3, добавив список2 в текущий список после указателя node  
  //List Merge(const List& list2); // создать список3, добавив в конец текущего списка список2

  //friend ostream& operator<<(ostream& os, const List& l);
  //bool operator==(const List& list2) const; // списки равны, если элементы в них идут в одинаковом порядке
};

#endif
