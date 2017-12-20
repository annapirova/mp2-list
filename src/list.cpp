#include "list.h"


Node::Node()
{
	next = NULL;
}

Node::Node(const DataType d)
{
	data = d;
	next = NULL;
}

Node::Node(const DataType &d, Node* n)
{
	data = d;
	next = n;
}

Node::Node(const Node& node2)
{
	data = node2.data;
	next = node2.next;
}

bool Node::operator==(const Node& node2) const
{
	if ((data == node2.data) && (next == node2.next))
		return true;
	else
		return false;
}

Node& Node::operator=(const Node& node2)
{
	if (this != &node2)
	{
		data = node2.data;
		next = node2.next;
	}
	return *this;
}

List::List() 
{
	head = NULL;
}

List::List(const Node &n)
{
	head = new Node(n);
}

List::List(const List & list2)
{
	if (list2.head != NULL)
	{
		head = new Node(list2.head->data);
		Node *h1 = head;
		Node *h2 = list2.head->next;
		while (h2 != NULL)
		{
			h1->next = new Node(h2->data);
			h1 = h1->next;
			h2 = h2->next;
		}
	}
	else
		head = NULL;
}

List& List::operator=(const List& list2)
{
	if (this != &list2)
	{
		Clean();
		if ((list2.head != NULL))
		{
			head = new Node(list2.head->data);
			Node *h1 = head;
			Node *h2 = list2.head->next;
			while (h2 != NULL)
			{
				h1->next = new Node(h2->data);
				h1 = h1->next;
				h2 = h2->next;
			}
		}
	}
	return *this;
}

List::~List()
{
	Node *h1 = head;
	Node *h2 = head;
	if (h1 != NULL)
	{
		while (h1->next != NULL)
		{
			h2 = h1->next;
			delete h1;
			h1 = h2;
		}
		delete h1;
	}
}

void List::InsertToHead(const DataType& d)
{
	Node *h = new Node(d);
	h->next = head;
	head = h;
}

void List::InsertToTail(const DataType &d)
{
	Node *h = head;
	if (h != NULL)
	{
		while (h->next!=NULL)
			h = h->next;
		h->next = new Node(d);
	}
	else
		head = new Node(d);
}

void List::InsertAfter(Node* node, const DataType& d)
{
	if (head == NULL)
		throw "head null";
	else
		if (node != NULL)
		{
			Node *h = new Node(d, node->next);
			node->next = h;
		}
}

void List::Delete(const DataType& d)
{
	Node *h1 = head;
	Node *h2 = head;
	if (h1 != NULL)
	{
		while ((h1->next != NULL) && (h1->data != d))
		{
			h2 = h1;
			h1 = h1->next;
		}
		if (h1->data == d)
		{
			h2->next = h1->next;
			if (h1 == head)
				head = head->next;
			delete h1;
		}
	}
}

Node* List::Search(const DataType &d)
{
	Node *h = head;
	if (h != NULL)
	{
		while ((h->next != NULL) && (h->data != d))
			h = h->next;
		if (h->data == d)
			return h;
		else return NULL;
	}
	else return NULL;
}

void List::Clean()
{
	Node *h1 = head;
	Node *h2 = head;
	if (h1 != NULL)
	{
		while ((h1->next != NULL))
		{
			h2 = h1->next;
			delete h1;
			h1 = h2;
		}
		delete h1;
		head = NULL;
	}
}


int List::GetSize()
{
	int i = 0;
	Node *h = head;
	while (h != NULL)
	{
		i++;
		h = h->next;
	}
	return i;
}

Node* List::GetHead()
{
	return head;
}

void List::Inverse()
{
	if (head != NULL)
	{
		Node *h1 = head;
		Node *h2 = NULL;
		Node *h3 = head->next;
		do
		{
			h3 = h1->next;
			h1->next = h2;
			h2 = h1;
			h1 = h3;
		} while (h1 != NULL);
		head = h2;
	}
}


List List::Merge(Node* node, const List& list2)
{
	if (head != NULL)
	{
		List list3(head->data);
		Node *h1 = list3.head;
		Node *h2 = head;
		while ((h2->next != NULL) && (h2 != node))
		{
			h1->next = new Node(h2->next->data);
			h1 = h1->next;
			h2 = h2->next;
		}
		if (node != NULL)
		{
			Node *h3 = list2.head;
			while (h3 != NULL)
			{
				h1->next = new Node(h3->data);
				h1 = h1->next;
				h3 = h3->next;
			}
			while (h2->next != NULL)
			{
				h1->next = new Node(h2->next->data);
				h1 = h1->next;
				h2 = h2->next;
			}
		}
		return list3;
	}
	else
	{
		List list3;
		return list3;
	}
}


List List::Merge(const List& list2)
{
	if (head != NULL)
	{
		List list3(head->data);
		Node *h1 = head->next;
		Node *h2 = list3.head;
		while (h1 != NULL)
		{
			h2->next = new Node(h1->data);
			h1 = h1->next;
			h2 = h2->next;
		}
		h1 = list2.head;
		while (h1 != NULL)
		{
			h2->next = new Node(h1->data);
			h1 = h1->next;
			h2 = h2->next;
		}
		return list3;
	}
	else
	{
		List list3(list2);
		return list3;
	}
}

bool List::operator==(const List& list2) const
{
	Node *h1 = head;
	Node *h2 = list2.head;
	bool flag = true;
	while ((h1 != NULL) && (h2 != NULL) && (flag))
	{
		if (h1->data != h2->data)
			flag = false;
		h1 = h1->next;
		h2 = h2->next;
	}
	if ((h1 != NULL) || (h2 != NULL))
		flag = false;
	return flag;
}

bool List::operator!=(const List& list2) const
{
	return !(*this == list2);
}
