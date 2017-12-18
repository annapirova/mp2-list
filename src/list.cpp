#include "list.h"
List::List(const List& list2)
{
	if (list2.head != NULL)
	{
		head = new Node(list2.head->data);
		Node *temp = head;
		Node *temp2 = list2.head->next;
		while (temp2 != NULL)
		{
			temp->next = new Node(temp2->data);
			temp = temp->next;
			temp2 = temp2->next;
		}
	}
	else
		head = NULL;
}
List::List(const Node& list2)
{
	head = new Node(list2);
}

List & List::operator=(const List & list2)
{
	if (this != &list2)
	{
		Clean();
		if (list2.head != NULL)
		{
			head = new Node(list2.head->data);
			Node *temp = head;
			Node*temp2 = list2.head->next;
			while (temp2 != NULL)
			{
				temp->next = new Node(temp2->data);
				temp = temp->next;
				temp2 = temp2->next;
			}
		}
	}
	return *this;
}

void List::InsertToHead(const DataType& d)
{
	Node *temp = new Node(d);
	temp->next = head;
	head = temp;
}

void List::InsertToTail(const DataType& d)
{
	Node* tmp = head;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new Node(d);
	}
	else
		head = new Node(d);
}

void List::InsertAfter(Node* node, const DataType& d)
{

	if (head == NULL)
		throw "Head null";
	if (node != NULL)
	{
		Node* tmp = new Node(d, node->next);
		node->next = tmp;
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
		return NULL;
}

void List::Clean()
{
	Node *temp = head;
	Node *temp2 = head;
	if (temp != NULL)
	{
		while (temp->next != NULL)
		{
			temp2 = temp->next;
			delete temp;
			temp = temp2;
		}
		delete temp;
		head = NULL;
	}
}

int List::GetSize()
{
	int size = 0;
	Node *temp = head;
	while (temp != NULL)
	{
		size++;
		temp = temp->next;
	}
	return size;
}

void List::Delete(const DataType& d)
{
	Node* tmp = head, *tmp2 = head;
	if (tmp != NULL) {
		while ((tmp->next != NULL) && (tmp->data != d))
		{
			tmp2 = tmp;
			tmp = tmp->next;
		}
		if (tmp->data == d)
		{
			tmp2->next = tmp->next;
			if (tmp == head)
				head = head->next;
			delete tmp;
		}
	}
}

void List::Inverse()
{
	if (head != NULL)
	{
		Node *tmp = head;
		Node *tmp2 = NULL;
		Node *tmp3 = head->next;
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

List List::Merge(Node * node, const List & list2)
{
	if (head != NULL)
	{
		List l(head->data);
		Node* tmp = l.head;
		Node* tmp2 = head;
		while ((tmp2->next != NULL) && (tmp2 != node))
		{
			tmp->next = new Node(tmp2->next->data);
			tmp = tmp->next;
			tmp2 = tmp2->next;
		}
		if (node != NULL)
		{
			Node* tmp3 = list2.head;
			while (tmp3 != NULL)
			{
				tmp->next = new Node(tmp3->data);
				tmp = tmp->next;
				tmp3 = tmp3->next;
			}
			while (tmp2->next != NULL)
			{
				tmp->next = new Node(tmp2->next->data);
				tmp = tmp->next;
				tmp2 = tmp2->next;
			}
		}
		return l;
	}
	else
	{
		return List();
	}
}

List List::Merge(const List & list2)
{
	if (head != NULL)
	{
		List l(head->data);
		Node *temp = head->next;
		Node *temp2 = l.head;
		while (temp != NULL)
		{
			temp2->next = new Node(temp->data);
			temp = temp->next;
			temp2 = temp2->next;
		}
		temp = list2.head;
		while (temp != NULL)
		{
			temp2->next = new Node(temp->data);
			temp = temp->next;
			temp2 = temp2->next;
		}
		return l;
	}
	else
	{
		List l(list2);
		return l;
	}
}

bool List::operator==(const List & list2) const
{
	Node *temp = head;
	Node *temp2 = list2.head;
	bool f = true;
	while ((temp != NULL) && (temp2 != NULL) && (f))
	{
		if (temp->data != temp2->data)
			f = false;
		temp = temp->next;
		temp2 = temp2->next;
	}
	if ((temp != NULL) || (temp2 != NULL))
		f = false;
	return f;
}

ostream & operator<<(ostream & os, const List & l)
{
	Node *temp = l.head;
	while (temp != NULL)
	{
		os << temp->data << " ";
		temp = temp->next;
	}
	os << endl;
	return os;
}

Node::Node(const Node & node2)
{
	data = node2.data;
	next = node2.next;
}

Node & Node::operator=(const Node & next2)
{
	data = next2.data;
	next = next2.next;
	return *this;
}

bool Node::operator==(const Node & node2) const
{
	return false;
}
