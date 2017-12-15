#include "list.h"

Node::Node(DataType d = 0, Node* n = NULL)
{
	data = d;
	next = n;
}

Node::Node(const Node& node2)
{
	data = node2.data;
	next = node2.next;
}

Node Node::operator=(const Node& node2)
{
	Node res(node2);
	return res;
}

bool Node::operator==(const Node& node2) const
{
	int k = 0;

	if (data != node2.data)
		k++;

	if (next != node2.next)
		k++;

	if (k == 0)
		return true;
	else
		return false;
}

List::List(const List& list2)
{
	head = list2.head;
}

List& List::operator=(const List& list2)
{
	if (this != &list2)
	{
		head = list2.head;
	}
	return *this;
}

List::~List()
{
	Node*tmp1 = head, *tmp2;
	if (head != NULL)
	{
		while (tmp1 != NULL)
		{
			tmp2 = tmp1->next;
			delete tmp1;
			tmp1 = tmp2;
		}
	}
}

void List::InsertToHead(const DataType& d)
{
	if (head == NULL)
	{
		head = new Node(d, NULL);
	}
	else
	{
		Node* tmp = new Node(d, head);
	}
}

void List::InsertToTail(const DataType& d)
{
	if (head == NULL)
	{
		head = new Node(d, NULL);
	}
	else
	{
		Node* tmp = head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = new Node(d, NULL);
	}
}

void List::InsertAfter(Node* node, const DataType& d)
{
	Node * tmp = new Node(d, node->next);
	node->next = tmp;
}

void List::Delete(const DataType& d)
{
	Node* tmp = head, *tmp2 = NULL;

	if (tmp != NULL)
	{
		while ((tmp->next != NULL) && (tmp->data != d))
		{
			tmp2 = tmp;
			tmp = tmp->next;
		}

		if (tmp->data == d)
		{
			tmp2->next = tmp->next;
			if (tmp == head)
			{
				head = head->next;
			}
			delete tmp;
		}
	}
}

Node* List::Search(const DataType& d)
{
	Node* tmp = head;
	if (tmp != NULL)
	{
		while (tmp != NULL)
		{
			tmp = tmp->next;
		}
		if (tmp->data == d)
			return tmp;
		else
			return NULL;
	}
	else
	{
		return NULL;
	}
}

void List::Clean()
{
	Node* tmp = head;
	Node* tmp2;

	if (tmp != NULL)
	{
		while (tmp->next != NULL)
		{
			tmp2 = tmp->next;
			delete tmp;
			tmp = tmp2;
		}
		delete tmp;
		head = NULL;
	}
}

int List::GetSize()
{
	int n = 0;
	Node* tmp = head;

	while (tmp != NULL)
	{
		n++;
		tmp = tmp->next;
	}

	return n;
}

Node* List::GetHead()
{
	return head;
}

void List::Inverse()
{
	Node* tmp = head;
	Node* tmp2 = head->next;
	Node* tmp3;
	while (tmp2 != NULL)
	{
		tmp3 = tmp2->next;
		tmp2->next = tmp;
		tmp = tmp2;
		tmp2 = tmp3;
	}
	head = tmp;
}

List List::Merge(Node* node, const List& list2)
{
	List A;
	Node* tmp = head;

	while (tmp != node)
	{
		A.InsertToTail(tmp->data);
		tmp = tmp->next;
	}

	Node* tmp2 = tmp->next;
	tmp = list2.head;

	while (tmp != NULL)
	{
		A.InsertToTail(tmp->data);
		tmp = tmp->next;
	}

	tmp = tmp2;
	while (tmp != NULL)
	{
		A.InsertToTail(tmp->data);
		tmp = tmp->next;
	}
	return A;
}

List List::Merge(const List& list2)
{
	List A;
	Node* tmp = head;
	while (tmp != NULL)
	{
		A.InsertToTail(tmp->data);
		tmp = tmp->next;
	}
	tmp = list2.head;
	while (tmp != NULL)
	{
		A.InsertToTail(tmp->data);
		tmp = tmp->next;
	}
	return A;
}

bool List::operator==(const List& list2) const
{
	int k = 0;
	Node* tmp = head;
	Node* tmp2 = list2.head;
	while (tmp != 0)
	{
		if (tmp->data != tmp2->data)
		{
			k++;
			tmp = tmp->next;
			tmp2 = tmp2->next;
		}
		else
		{
			tmp = tmp->next;
			tmp2 = tmp2->next;
		}
	}

	if (k == 0)
		return true;
	else
		return false;
}