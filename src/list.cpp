#include "list.h"

List::List(const List & list2)
{
	if (list2.head)
	{
		head = new Node(list2.head->data, list2.head);
		Node* temp = head;
		Node* temp1 = list2.head->next;
		while (temp1)
		{
			temp->next = new Node(temp1->data);
			temp = temp->next;
			temp1 = temp1->next;
		}
	}
	else
		head = NULL;
}

List & List::operator=(const List & list2)
{
	if (list2.head)
	{
		head = new Node(list2.head->data, list2.head);
		Node *temp = head;
		Node *temp1 = list2.head->next;
		while (temp1)
		{
			temp->next = new Node(temp1->data);
			temp = temp->next;
			temp1 = temp1->next;
		}
	}
	else
		head = NULL;
	return *this;
}

List::~List()
{
	Clean();
}

void List::InsertToHead(const DataType & d)
{
	Node* temp = new Node(d, head);
	head = temp;
}

void List::InsertToTail(const DataType & d)
{
	Node* temp = head;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new Node(d);
	}
	else
		head = new Node(d);
}

void List::InsertAfter(Node * node, const DataType & d)
{
	if (node && head)
	{
		Node* temp = node->next;
		node->next = new Node(d, temp);
	}
	else 
		if (head == NULL)
			throw "Error";
}

void List::Delete(const DataType & d)
{
	Node* temp = head;
	Node* del;
	if (head)
	{
		if (head->data == d)
		{
			del = temp->next;
			delete head;
			head = del;
		}
		else
		{
			while (temp->next)
			{
				if (temp->next->data == d)
				{
					del = temp->next;
					break;
				}
				temp = temp->next;
			}
			if (temp->next)
			{
				temp->next = del->next;
				delete del;
			}
		}
	}
}

Node * List::Search(const DataType & d)
{
	Node* temp = head;
	while (temp)
	{
		if (temp->data == d)
			return temp;
		temp = temp->next;
	}
	return NULL;
}

void List::Clean()
{
	Node* prev = head;
	Node* temp;
	if (head)
	{
		while (prev)
		{
			temp = prev->next;
			delete prev;
			prev = temp;
		}
		head = NULL;
	}
}

int List::GetSize()
{
	Node* temp = head;
	int res = 0;
	while (temp)
	{
		res++;
		temp = temp->next;
	}
	return res;
}

Node * List::GetHead()
{
	return head;
}

void List::Inverse()
{
	if (head)
	{
		Node* temp = head->next;
		head->next = NULL;
		Node* temp1 = head;
		Node* rt;
		while (temp)
		{
			rt = temp->next;
			temp->next = temp1;
			temp1 = temp;
			temp = rt;
		}
		head = temp1;
	}
}

List List::Merge(Node * node, const List & list2)
{
	List res;
	Node* temp = head;
	if (head)
	{
		res.head = new Node(head->data);
		Node* temp1 = res.head;
		while (temp->next && temp != node)
		{
			temp1->next = new Node(temp->next->data);
			temp = temp->next;
			temp1 = temp1->next;
		}
		if (temp == node)
		{
			if (list2.head)
			{
				Node* temp2 = list2.head;
				while (temp2)
				{
					temp1->next = new Node(temp2->data);
					temp2 = temp2->next;
					temp1 = temp1->next;
				}
			}
			while (temp->next)
			{
				temp1->next = new Node(temp->next->data);
				temp = temp->next;
				temp1 = temp1->next;
			}
		}
		temp1->next = NULL;
	}

	return res;
}


List List::Merge(const List & list2)
{
	List res(*this);
	if (res.head && list2.head)
	{
		Node* temp = res.head;
		while (temp->next)
			temp = temp->next;


		Node* temp1 = list2.head;
		while (temp1)
		{
			temp->next = new Node(temp1->data, temp1->next);
			temp = temp->next;
			temp1 = temp1->next;
		}
		temp->next = NULL;
	}
	else
		if (res.head == NULL)
			res = List(list2);
	return res;
}

bool List::operator==(const List & list2) const
{
	bool res = true;
	Node* temp = head;
	Node* temp1 = list2.head;
	while (temp && temp1 && res)
	{
		if (temp->data != temp1->data)
			res = false;
		else 
		{
			temp = temp->next;
			temp1 = temp1->next;
		}
		
	}
		if (temp || temp1)
			res = false;
	return res;
}

ostream & operator<<(ostream & os, const List & l)
{
	Node* temp = l.head;
	while (temp)
	{
		os << temp->data << " ";
		temp = temp->next;
	}
	return os;
}
