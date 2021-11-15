#ifndef __AISD_LIST__
#define __AISD_LIST__

#include <iostream>
using namespace std;

typedef int DataType; // переменование типа данных

struct Node // звено
{ DataType data; // элемент
  Node* next;    // указатель на следующий
  // конструкторы
  Node(DataType d = 0, Node* n = NULL);
  Node(const Node& node2); // конструктор копирования
  bool operator==(const Node& node2) const; // сравнение двух зеньев
};

class myiterator // итератор
{ Node* p;
  public:
  myiterator(Node* tmp) : p(tmp) {};
  DataType& operator*() { return p->data; };
  myiterator& operator++() 
  { p = p->next;
	return *this;
  };
  friend class List;
  bool operator==(const myiterator& it) const // сравнение
  { if (p == it.p) { return 1; }
      else { return 0; }
  }
  bool operator!=(const myiterator& it) const
  { if (*this == it) { return 0; }
    else { return 1; }
  }
};

class List
{ Node* head; // указатель на первый элемент списка
  public:
  // Конструктор, деструктор
  List(); //List(const List& list2);
  ~List();
  // Методы
  bool isEmpty() { return (head == nullptr); }
  void InsertToHead(const DataType& d); // вставить элемент d первым
  DataType ViewHead() { return head->data; }
  void InsertToTail(const DataType& d); // вставить элемент d последним
  void Clean(); // удалить все звенья  
  void Delete(const DataType& d); // удалить звено со значением data = d				
  myiterator begin() { return myiterator(head); };

  void Delete(const myiterator& start, const myiterator& finish);
  friend ostream& operator<<(ostream& os, const List& l);
  //  List& operator=(const List& list2);
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