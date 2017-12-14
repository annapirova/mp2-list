#ifndef __AISD_LIST__
#define __AISD_LIST__

#include <iostream>
using namespace std;

typedef int DataType;

struct Node
{
  DataType data;
  Node* next;
  Node(DataType _data, Node* _next) {
	  data = _data;
	  next = _next;
  }
  // здесь могут быть конструкторы, методы, деструктор Node
};

class List
{
	Node* head;
  // любые поля
public:
  List() {};
  List(const List& list2);
  List& operator=(const List& list2);
  ~List() {
	  Node* tmp = head;
	  while (tmp!= NULL)
	  {
		  delete tmp;
		  tmp = tmp->next;
	  }
  };

  void InserToHead(const DataType& d); // вставить элемент d первым
  void InserToTail(const DataType& d); // вставить элемент d последним
  void InsertAfter(Node* node, const DataType& d); // вставить элемент d после звена node
  void Delete(const DataType& d); // удалить звено со значением data = d
  Node* Search(const DataType& d); // найти указатель на звено со значением data = d
  void Clean(); // удалить все звенья
  int GetSize() { int k = 0; Node* tmp = head;  while (tmp->next != NULL) k++; return k; }; // узнать число звеньев в списке
  Node* GetHead() { return head; } // получить указатель на первое звено списка

  void Inverse(); // инвертировать список, т.е. звенья должны идти в обратном порядке
  List Merge(Node* node, const List& list2); // создать список3, добавив список2 в текущий список после указателя node  
  List Merge(const List& list2); // создать список3, добавив в конец текущего списка список2

  friend ostream& operator<<(ostream& os, const List& l);
};

#endif