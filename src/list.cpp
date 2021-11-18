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

List::List(const List& list2)
{
	if (!list2.isEmpty())
	{
		head = new Node(list2.head->data);
		Node* tmp1 = head;
		Node* tmp2 = list2.head->next;

		while (tmp2 != nullptr)
		{
			tmp1->next = new Node(tmp2->data);
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
	}
	else
		head = nullptr;
}

List& List::operator=(const List& list2)
{
	if (this != &list2)
	{
		Node* p = head, * q = head;
		while (q != nullptr)
		{
			q = p->next;
			delete p;
			p = q;
		}

		if (list2.isEmpty())
			head = nullptr;
		else
		{
			head = new Node(list2.head->data);
			p = head;
			q = list2.head->next;
			while (q != nullptr)
			{
				p->next = new Node(q->data);
				p = p->next;
				q = q->next;
			}
		}
	}

	return *this;
}

List::~List()
{
	Node* tmp, * tmp1; // указатель-ходилка
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

void List::Delete(const myiterator& it)
{
	Node* prev = head;
	bool find = false;

	if (head == it.p)
	{
		head = head->next;
		delete prev;
		find = true;
	}

	while (!find && prev->next != nullptr)
	{
		if (prev->next == it.p)
		{
			Node* tmp = prev->next;
			prev->next = prev->next->next;
			delete tmp;
			find = true;
		}
		else
		{
			prev = prev->next;
		}
	}
}

void List::InsertAfter(const myiterator& it, const DataType& d)
{
	if (!isEmpty())
	{
		Node* tmp = head;
		bool find = false;

		while (!find && tmp->next != nullptr)
		{
			if (tmp->next == it.p)
			{
				it.p->next = new Node(d, it.p->next);
				find = true;
			}
		}
	}
}

myiterator List::Search(const DataType& d)
{
	myiterator it = begin();
	for (it; it.p != nullptr; it++)
	{
		if (*it == d)
		{
			return it;
		}
	}
	return it;
}

void List::Inverse()
{
	Node* p = nullptr, * q = head;
	Node* tmp;

	while (q != nullptr)
	{
		tmp = q->next;
		q->next = p;
		p = q;
		q = tmp;
	}

	head = p;
}

List List::Merge(const myiterator& start, const List& list2)
{
	if (isEmpty())
		List res(list2);
	else
	{
		List res;
		myiterator it1 = begin();
		res.head = new Node(*it1);
		myiterator rit = res.begin();
		++it1;

		while (it1.p != start.p->next)
		{
			if (it1.p == nullptr)
				throw std::exception("Iterator not find!");
			rit.p->next = new Node(*it1);
			++it1;
			++rit;
		}

		myiterator it2 = list2.begin();
		while (it2.p != nullptr)
		{
			rit.p->next = new Node(*it2);
			++it2;
			++rit;
		}

		while (it1.p != nullptr)
		{
			rit.p->next = new Node(*it1);
			++it1;
			++rit;
		}

		return res;
	}
}

void List::MergeWith(const myiterator& start, const List& list2)
{
	myiterator it2 = list2.begin(), it1 = start;

	while (it2.p != nullptr)
	{
		it1.p->next = new Node(*it2);
		it1++;
		it2++;
	}

	it1.p->next = start.p->next;
}

void List::MadeUnique()
{
	if (!isEmpty())
	{
		List res;
		res.head = new Node(head->data);
		Node* p = res.head, * q = head->next;

		while (q != nullptr)
		{
			if (res.Search(q->data).p == nullptr)
			{
				p->next = new Node(q->data);
				p = p->next;
			}
			q = q->next;
		}

		*this = res;
	}
}

bool List::isCycle()
{
	if (!isEmpty())
	{
		Node* p = head, * q = head->next;

		while (q != nullptr)
		{
			if (p == q)
				return true;
			p = q;
			if (q->next != nullptr)
				q = q->next->next;
		}
	}
	return false;
}

//void List::Reordering()
//{
//	if (!isEmpty())
//	{
//		Node* odd1 = head;
//		Node* ev1 = head->next;
//		if (ev1 != nullptr)
//		{
//			head = head->next;
//			head->next = head->next->next;
//		}
//		Node* tmp;
//		while (ev1->next != nullptr)
//		{
//			tmp = ev1->next;
//			ev1->next = ev1->next->next;
//			ev1 = ev1->next;
//		}
//	}
//}

ostream& operator<<(ostream& os, const List& l)
{
	if (!l.isEmpty())
	{
		Node* p = l.head;
		while (p->next != nullptr)
		{
			os << p->data << ", ";
			p = p->next;
		}
		os << p->data;
	}
	return os;
}