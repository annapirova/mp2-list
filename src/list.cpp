#include "list.h"

Node::Node()
{
	data = NULL;
	next = NULL;
}

Node::Node(DataType d, Node* n)
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
	data = node2.data;
	next = node2.next;
	return *this;
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
	if (list2.head == NULL)
	{
		head = list2.head;
		tail = head;
	}
	else
	{
		head = new Node(list2.head->data, list2.head);
		Node *tmp = head;
		Node *tmp2 = list2.head->next;
		while (tmp2 != NULL)
		{
			tmp->next = new Node(tmp2->data, tmp2->next);
			tmp = tmp->next;
			tmp2 = tmp2->next;
		}
		tail = tmp;
	}
}

List& List::operator=(const List& list2)
{
	if (this != &list2)
	{
		Clean();
		if (list2.head == NULL)
		{
			head = list2.head;
			return *this;
		}
		else
		{
			head = new Node(list2.head->data, list2.head);
			Node *tmp = head;
			Node *tmp2 = list2.head->next;
			while (tmp2 != NULL)
			{
				tmp->next = new Node(tmp2->data, tmp2->next);
				tmp = tmp->next;
				tmp2 = tmp2->next;
			}
		}
		return *this;
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
		this->head = tmp;
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
	if (head == NULL)
		throw "Error";

	if (node == NULL)
	{
		Node* tmp = head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = new Node(d, NULL);
	}
	else
	{
		Node * tmp = new Node(d, node->next);
		node->next = tmp;
	}
}

void List::Delete(const DataType& d)
{
	Node* tmp = head, *tmp2 = head;

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
		while ((tmp->next != NULL) && (tmp->data != d))
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
	if (head == NULL)
	{
		head = NULL;
	}
	else
	{
		Node* tmp = head;
		Node* tmp2 = NULL;
		Node* tmp3 = head->next;
		if ((tmp != NULL) && (tmp->next != NULL))
		{
			do
			{
				tmp3 = tmp->next;
				tmp->next = tmp2;
				tmp2 = tmp;
				tmp = tmp3;
			} while (tmp != NULL);
			head = tmp2;
		}
	}
}

List List::Merge(Node* node, const List& list2)
{
	if ((head == NULL) || (head == node))
	{
		List A;
		Node* tmp = list2.head;

		while (tmp != NULL)
		{
			A.InsertToTail(tmp->data);
			tmp = tmp->next;
		}
		return A;
	}
	else
	{
		List A;
		Node* tmp = head;

		while (tmp != node)
		{
			A.InsertToTail(tmp->data);
			tmp = tmp->next;
		}

		if (tmp != NULL)
		{
			A.InsertToTail(tmp->data);
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
		else
		{
			Node* tmp2 = tmp;
			tmp = list2.head;

			while (tmp != NULL)
			{
				A.InsertToTail(tmp->data);
				tmp = tmp->next;
			}
			return A;
		}	
	}
}

List List::Merge(const List& list2)
{
	if (head != NULL)
	{
		List A(*this);

		if (list2.head != NULL)
		{
			Node* tmp2 = A.tail;
			tmp2->next = new Node(list2.head->data, list2.head->next);
			tmp2 = tmp2->next;
			Node* tmp = list2.head->next;

			while (tmp != NULL)
			{
				tmp2->next = new Node(tmp->data, tmp->next);
				tmp2 = tmp2->next;
				tmp = tmp->next;
			}
			return A;
		}
		else
		{
			return A;
		}
	}
	else
	{
		List A(list2);
		return A;
	}
}

bool List::operator==(const List& list2) const
{
	int k = 0;
	Node* tmp = head;
	Node* tmp2 = list2.head;
	
	if ((tmp != NULL) && (tmp2 == NULL))
	{
		k++;
	}

	if ((tmp == NULL) && (tmp2 != NULL))
	{
		k++;
	}
	
	if (k == 0)
	{
		while ((tmp != NULL) && (tmp2 != NULL))
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
	}

	if (k == 0)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& os, const List& l)
{
	Node* tmp = l.head;
	while (tmp != NULL)
	{
		os << tmp->data << " ";
		tmp = tmp->next;
	}
	return os;
}

Node* List::GetTail()
{
	Node* tmp = head;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tail = tmp;
	return tail;
}