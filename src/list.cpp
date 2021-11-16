#include "list.h"

Node::Node(DataType d, Node *n) : data(d), next(n) {
}

Node::Node(const Node &node2) {
    data = node2.data;
    next = node2.next;
}

bool Node::operator==(const Node &node2) const {
    return (data == node2.data);
}

List::List() {
    head = nullptr;
    size = 0;
}

List::List(const List &list) {
    if (list.head == nullptr) {
        head = nullptr;
        size = 0;
    } else {
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
}

List::~List() {
    Node *tmp, *tmp1;
    tmp = head;
    tmp1 = tmp;
    while (tmp1 != nullptr) {
        tmp1 = tmp->next;
        delete tmp;
        tmp = tmp1;
    }
}

void List::InsertToHead(const DataType &d) {
    if (isEmpty()) {
        head = new Node(d, nullptr);
    } else {
        head = new Node(d, head);
    }
    ++size;
}

void List::InsertToTail(const DataType &d) {
    if (isEmpty()) {
        head = new Node(d, nullptr);
    } else {
        Node *tmp = head;
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = new Node(d, nullptr);
    }
    ++size;
}

void List::Clean() {
    if (!isEmpty()) {
        Node *tmp;
        while (head->next != nullptr) {
            tmp = head->next;
            head->next = tmp->next; // head->next->next;
            delete tmp;
        }
        delete head;
        head = nullptr;
        size = 0;
    }
}

void List::Delete(const DataType &d) {
    if (!isEmpty()) {
        Node *prev = head;
        Node *tmp;
        bool find = false;


        if (head->data == d) {
            head = head->next;
            delete prev;
            find = true;
        }

        while (!find && (prev->next != nullptr)) {
            if (prev->next->data == d) {

                tmp = prev->next;
                prev->next = prev->next->next; // tmp->next
                delete tmp;
                find = true;
            } else
                prev = prev->next;
        }
        --size;
    }
}

void List::DeleteAll(const DataType &d) {
    if (!isEmpty()) {
        Node *prev = head;
        Node *tmp1;
        int count = 0;

        if (head->data == d) {
            head = head->next;
            delete prev;
            prev = head;
            ++count;
        }
        if (prev) {
            while (prev->next != nullptr) {
                if (prev->next->data == d) {
                    tmp1 = prev->next;
                    prev->next = tmp1->next;
                    delete tmp1;
                    ++count;
                } else
                    prev = prev->next;
            }
            if (prev->data == d) {
                head = nullptr;

            }
        }
        /*while (prev != nullptr) {
            if (prev->data == d) {
                tmp1 = prev;
                prev = prev->next;
                delete tmp1;
                tmp1 = prev;
                ++count;
            } else
                prev = prev->next;
        }*/
        size -= count;
    }
}

#include <map>

void List::MakeUniq() {
    if (!isEmpty() && size != 1) {
        List l;

        auto *tmp = head;
        map<DataType, bool> m;

        m[tmp->data] = true;

        l.InsertToTail(tmp->data);
        while (tmp->next != nullptr) {
            if (!m[tmp->next->data]) {
                m[tmp->next->data] = true;
                l.InsertToTail(tmp->next->data);
            }
            tmp->next = tmp->next->next;
        }
        *this = l;
/*    DataType *arr = new DataType [size];
    Node *tmp = head;

    arr[0] = tmp->data;
    int count_uniq = 1;
    bool is_found;

    while (tmp->next){
        is_found = false;
        for (int i = 0; !is_found && i < count_uniq; ++i) {
            if (tmp->next->data != arr[i]){
                is_found = true;
                arr[i + 1] = tmp->next->data;
                ++count_uniq;
            }
        }
        tmp->next = tmp->next->next;
    }
    Clean();
    for (int i = 0; i < count_uniq; ++i) {
        InsertToTail(arr[i]);
    }*/
    }
}

