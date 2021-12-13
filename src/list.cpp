#include "list.h"

Node::Node(DataType d, Node* n) : data(d), next(n)
{
}

Node::Node(const Node& node2)
{
	data = node2.data;
}

bool Node::operator==(const Node& node2) const
{
	return (data == node2.data);
}

List::List()
{
	head = nullptr;
}

List& List::operator=(const List& list2)
{
	if (this != &list2)
	{
		Clean();
		if (list2.head == NULL)
		{
			head = NULL;
		}
		else
		{
			head = new Node(list2.head->data, list2.head->next);
			Node* tmp = head;
			Node* tmp2 = list2.head->next;
			while (tmp2 != NULL)
			{
				tmp->next = new Node(tmp2->data, tmp2->next);
				tmp = tmp->next;
				tmp2 = tmp2->next;
			}
		}
	}
	return *this;
}

List::~List()
{
	Node* tmp, *tmp1; // указатель-ходилка
	tmp = head;
	tmp1 = tmp;
	while (tmp1 != nullptr)
	{
		tmp1 = tmp->next;
		delete tmp;
		tmp = tmp1;
	}
}

void List::InsertToHead(const DataType& d)
{
	if (isEmpty())
	{
		head = new Node(d, nullptr); // это первый и единственный
	}
	else
	{
		head = new Node(d, head);
	}
}

void List::InsertToTail(const DataType& d)
{
	if (isEmpty())
	{
		head = new Node(d, nullptr); // это первый и единственный
	}
	else
	{
		Node* p = new Node(d, nullptr);
		Node* tmp; // указатель-ходилка
		tmp = head;
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		// в итоге - tmp - последний
		tmp->next = p;
	}
}

void List::Clean()
{
	Node* tmp;
	if (isEmpty())
		return;

	while (head->next != nullptr)
	{
		tmp = head->next;
		head->next = tmp->next; // head->next->next;
		delete tmp;
	}
	delete head;
	head = nullptr;
}

void List::Delete(const DataType& d)
{
	// найти значение
	// найти того, кто перед ним
	Node* prev = head;
	Node* tmp;
	bool find = false;

	// данные в голове
	if (head->data == d)
	{
		head = head->next;
		delete prev; // сейчас это голова
		find = true;
	}

	while (!find && (prev->next != nullptr))
	{
		if (prev->next->data == d)
		{
			// prev->next - это звено
			tmp = prev->next;
			prev->next = prev->next->next; // tmp->next
			delete tmp;
			find = true;
		}
		else
			prev = prev->next;
	}
}
// найти указатель на звено со значением data = d
myiterator List::Search(const DataType& d)
{
	Node* tmp = head;
	myiterator it = begin();
		while((tmp != NULL) && (tmp->data == d)) 
		{
			if (tmp == NULL)
			{
				return it;
			}
			else
			{
				tmp = tmp->next;
				++it;
			}
	}
		return it;
}

// инвертировать список, т.е. звенья должны идти в обратном порядке
void List::Inverse()
{
	Node* tmp1 = head;
	Node* tmp2;
	Node* tmp3;
	if (head != NULL)
	{
		tmp2 = head->next;
		head->next = NULL;
		if (tmp2 != NULL)
		{
			tmp3 = tmp2->next;
			while (tmp3 != NULL)
			{
				tmp2->next = tmp1;
				tmp1 = tmp2;
				tmp2 = tmp3;
				tmp3 = tmp3->next;
			}
			tmp2->next = tmp1;
			head = tmp2;
		}
	}
}

ostream& operator<<(ostream& os, const List& l)
{
	List list;
	Node* tmp = list.head;
	while (tmp != NULL)
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	return os;
}

bool List:: operator ==(const List& list2) const
{
	Node* tmp1 = head;
	Node* tmp2 = list2.head;
	while ((tmp1 != NULL) && (tmp2 != NULL) && (tmp1->data == tmp2->data))
	{
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
	if ((tmp1 == NULL) && (tmp2 == NULL)) 
		return true;
	else
		return false;
}