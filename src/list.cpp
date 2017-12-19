#include "list.h"

List::List(const List& list2)
{
	if (list2.head)
	{
		Node* cur = new Node(list2.head->data);
		Node* temp = list2.head;
		head = cur;
		while (temp->next)
		{
			temp = temp->next;
			cur->next = new Node(temp->data);
			cur = cur->next;
		}
	}
	else
		head = NULL;
}

List& List::operator=(const List& list2)
{
	if (head != list2.head)
	{
		Clean();
		if (list2.head)
		{
			Node* cur = new Node(list2.head->data);
			Node* temp = list2.head;
			head = cur;
			while (temp->next)
			{
				temp = temp->next;
				cur->next = new Node(temp->data);
				cur = cur->next;
			}
		}
		else
			head = NULL;
	}
	return *this;
}

List::~List()
{
	Clean();
}

void List::Clean()
{
	Node* cur;
	Node* temp = head;
	if (head)
		while (temp)
		{
			cur = temp->next;
			delete temp;
			temp = cur;
		}
	head = NULL;
}

int List::GetSize()
{
	int res = 0;
	Node* cur = head;
	while (cur)
	{
		res++;
		cur = cur->next;
	}
	return res;
}

Node* List::GetHead()
{
	return head;
}

bool List::operator==(const List& list2) const
{
	Node* cur1 = head;
	Node* cur2 = list2.head;
	bool res = true;
	if (cur1 != NULL && cur2 != NULL && cur1 != cur2)
	{
		while (res && cur1->next && cur2->next)
			if (cur1->data == cur2->data)
			{
				cur1 = cur1->next;
				cur2 = cur2->next;
			}
			else
				res = false;
		if (cur1->next || cur2->next)
			res = false;
	}
	else
		if (cur1 != cur2)
			res = false;
	return res;
}

void List::InsertToHead(const DataType& d)
{
	Node*temp = new Node(d, head);
	head = temp;
}

void List::InsertToTail(const DataType& d)
{
	Node *cur = head;
	if (cur)
	{
		while (cur->next)
			cur = cur->next;
		cur->next = new Node(d);
	}
	else
		head = new Node(d);
}

void List::InsertAfter(Node* node, const DataType& d)
{
	if (node && head)
	{
		Node*temp = node->next;
		node->next = new Node(d, temp);
	}
	else
		if (head == NULL)
			throw "";
}

void List::Delete(const DataType& d)
{
	Node* cur = head;
	Node* temp;
	if (head)
	{
		if (head->data == d)
		{
			temp =head->next;
			delete head;
			head =temp;
		}
		else
		{
			while (cur->next)
			{
				if (cur->next->data != d)
					cur = cur->next;
				else
				{
					temp = cur->next;
					cur->next = temp->next;
					delete temp;
				}								
			}
		}
	}
}

void List::Inverse()
{
	if (head)
	{
		Node* temp = head->next;
		head->next = NULL;
		Node* cur = head;
		Node* p;
		while (temp)
		{
			p = temp->next;
			temp->next = cur;
			cur = temp;
			temp = p;
		}
		head = cur;
	}
}

Node* List::Search(const DataType& d)
{
	Node*cur=head;
	while (cur)
	{
		if (cur->data == d)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

List List::Merge(Node* node, const List& list2)
{
	List res;
	Node* cur1 = head;
	if (head)
	{
		res.head = new Node(head->data);
		Node* temp = res.head;
		while (cur1->next && cur1 != node)
		{
			temp->next = new Node(cur1->next->data);
			temp = temp->next;
			cur1 = cur1->next;
		}
		if (cur1 == node)
		{
			if (list2.head)
			{
				Node* cur2 = list2.head;
				while (cur2)
				{
					temp->next = new Node(cur2->data);
					cur2 = cur2->next;
					temp = temp->next;
				}
			}
			while (cur1->next)
			{
				temp->next = new Node(cur1->next->data);
				cur1 = cur1->next;
				temp = temp->next;
			}
		}
		temp->next = NULL;
	}
	return res;
}

List List::Merge(const List& list2)
{
	List res(*this);
	if (res.head && list2.head)
	{
		Node* cur = res.head;
		while (cur->next)
			cur = cur->next;


		Node* temp = list2.head;
		while (temp)
		{
			cur->next = new Node(temp->data);
			cur = cur->next;
			temp = temp->next;
		}
		cur->next = NULL;
	}
	else if (res.head == NULL) res = List(list2);
	return res;		
}

ostream& operator<<(ostream& os, const List& l)
{
	Node* cur = l.head;
	while (cur->next)
	{
		os << cur->data << " ";
		cur = cur->next;
	}
	return os;
}