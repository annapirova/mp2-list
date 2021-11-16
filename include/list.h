#ifndef __AISD_LIST__
#define __AISD_LIST__

#include <iostream>

using namespace std;

typedef int DataType;

struct Node {
    DataType data;
    Node *next{};
    // здесь могут быть конструкторы, методы, деструктор Node

    explicit Node(DataType d = 0, Node *n = nullptr);

    Node(const Node &node2);

    bool operator==(const Node &node2) const;
/*    Node& operator=(const Node& node){
      if (this != &node){
          delete next;
          data = node.data;
          next = new Node(node.data, node.next);
      }
      return *this;
  };*/
};

class myiterator {
    Node *p;
public:
    explicit myiterator(Node *tmp) : p(tmp) {};

/*    ~myiterator(){
        delete p;
    }*/

    DataType &operator*() { return p->data; };

    myiterator &operator++() {
        p = p->next;
        return *this;
    };

    bool operator==(const myiterator &it) {
        return p->data == it.p->data && p->next == it.p->next;
    }

    bool operator!=(const myiterator &it) {
        return !myiterator::operator==(it);//p->data == it.p->data && p->next == it.p->next;
    }

    friend class List;
};

class List {
    Node *head;
    int size;
public:
    List();

    List(const List &list);

    ~List();

    bool isEmpty() { return head == nullptr; }

    void InsertToHead(const DataType &d); // вставить элемент d первым
    DataType ViewHead() { return head->data; }

    DataType ViewTail() { return *end(); }

    void InsertToTail(const DataType &d); // вставить элемент d последним
    void Clean(); // удалить все звенья
    void Delete(const DataType &d); // удалить звено со значением data = d
    myiterator begin() { return myiterator(head); }

    myiterator end() {
        auto tmp = head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        return myiterator(tmp);
    }

    void DeleteAll(const DataType &d);

    void MakeUniq();

    myiterator Search(const DataType &d) {
        Node *tmp = head;
        bool f = true;
        myiterator it = begin();
        while (f && tmp != nullptr) {
            if (tmp->data == d) {
                f = false;
            } else {
                tmp = tmp->next;
                ++it;
            }
        }
        return it;
    }

    List &operator=(const List &list) {
        if (this != &list) {
            delete head;
            head = new Node(list.head->data, nullptr);

            Node *list_currentNode = list.head;
            Node *this_currentNode = head;
            while (list_currentNode->next != nullptr) {
                this_currentNode->next = new Node(list_currentNode->next->data, nullptr);
                this_currentNode = this_currentNode->next;
                list_currentNode = list_currentNode->next;
            }
            size = list.size;
        }
        return *this;
    };

    friend ostream &operator<<(ostream &out, const List &l) {
        List l1 = l;
        while (l1.head != nullptr) {
            cout << l1.head->data << " ";
            l1.head = l1.head->next;
        }
        return out;
    }


    //void InsertAfter(Node* node, const DataType& d); // вставить элемент d после звена node
    //Node* Search(const DataType& d); // найти указатель на звено со значением data = d
    //int GetSize(); // узнать число звеньев в списке
    //Node* GetHead(); // получить указатель на первое звено списка

    //void Inverse(); // инвертировать список, т.е. звенья должны идти в обратном порядке
    //List Merge(Node* node, const List& list2); // создать список3, добавив список2 в текущий список после указателя node
    //List Merge(const List& list2); // создать список3, добавив в конец текущего списка список2


    //bool operator==(const List& list2) const; // списки равны, если элементы в них идут в одинаковом порядке
};

#endif
