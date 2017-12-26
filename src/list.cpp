#include "list.h"

List::List(const List& list2)
{
	if (list2.head)
	{
		head = new Node(list2.head->data);
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

List& List::operator=(const List& list2)
{
	if (this != &list2)
	{
		Clean();
		/*List temp(list2);
		head = temp.head;
		return *this;*/
		if (list2.head)
		{
			head = new Node(list2.head->data);
			Node* temp = head;
			Node* temp1 = list2.head->next;
			while (temp1)
			{
				temp->next = new Node(temp1->data);
				temp = temp->next;
				temp1 = temp1->next;
			}
		}
	}
	return *this;
}

List::~List()
{
	Clean();
}

void List::InsertToHead(const DataType& d)
{
	Node* temp = new Node(d, head);
	head = temp;
}

void List::InsertToTail(const DataType& d)
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

void List::InsertAfter(Node* node, const DataType& d)
{ 
		if (head)
		{
			if (node)
			{
				Node* temp = node->next;
				node->next = new Node(d, temp);
			}
		}
	else
		throw "Error";
}

void List::Delete(const DataType& d)
{
	Node* del;
	Node* temp = head;
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

Node* List::Search(const DataType& d)
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
	Node* temp = head;
	Node* temp1;
		while (temp)
		{
			temp1 = temp->next;
			delete temp;
			temp = temp1;
		}
	head = NULL;
}

int List::GetSize()
{
	int k = 0;
	Node* temp = head;
	while (temp)
	{
		k++;
		temp = temp->next;
	}
	return k;
}

Node* List::GetHead()
{
	return head;
}

void List::Inverse()
{
	if (head)
	{
		Node* temp2 = head->next;
		head->next = NULL;
		Node* temp3 = head;
		Node* temp1;
		while (temp2)
		{
			temp1 = temp2->next;
			temp2->next = temp3;
			temp3 = temp2;
			temp2 = temp1;
		}
		head = temp3;
	}
}

List List::Merge(Node* node, const List& list2)
{	
	List temp;
	Node* temp1 = head;
	if (head)
	{
		temp.head = new Node(head->data);
		Node* temp2 = temp.head;
		while (temp1->next && temp1 != node)
		{
			temp2->next = new Node(temp1->next->data);
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		if (temp1 == node)
		{
			if (list2.head)
			{
				Node* temp3 = list2.head;
				while (temp3)
				{
					temp2->next = new Node(temp3->data);
					temp3 = temp3->next;
					temp2 = temp2->next;
				}
			}
			while (temp1->next)
			{
				temp2->next = new Node(temp1->next->data);
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
			temp2->next = NULL;
		}
	}
	return temp;
}

List List::Merge(const List& list2)
{
	List temp(*this);
	if (head)
	{	
		Node* temp1 = temp.head;
		while (temp1->next)
			temp1 = temp1->next;
		Node* temp2 = list2.head;
		while (temp2)
		{
			temp1->next = new Node(temp2->data);
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		temp1->next = NULL;
	}
	else temp = List(list2);
	return temp;
}

ostream& operator<<(ostream& os, const List& l)
{
	Node* temp = l.head;
	while (temp)
	{
		cout << temp->data << ' ';
		temp = temp->next;
	}
	return os;
}

bool List::operator==(const List& list2) const
{
	bool res = true;
	Node* temp = head;
	Node* temp1 = list2.head;
	while (temp && temp1)
	{
		if (temp->data != temp1->data)
		{
			res = false;
			break;
		}
		temp = temp->next;
		temp1 = temp1->next;
	}
	if (temp != temp1)
		res = false;
	return res;
}

