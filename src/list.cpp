#include "list.h"


  

List::List(const List& list2)                 
{
	if (list2.head)
	{
		head = new Node(list2.head->data, list2.head);
		Node *u = head;
		Node *u2 = list2.head->next;
		while (u2 != NULL)
		{
			u->next = new Node(u2->data, u2->next);
			u = u->next;
			u2 = u2->next;
		}
	}
	else
		head =  list2.head;;
}


List& List:: operator=(const List& list2)            
{
	if (this != &list2)
	{
		Clean();
		if (list2.head)
		{
			head = new Node(list2.head->data, list2.head);
			Node *u = head;
			Node *u1 = list2.head->next;
			while (u1)
			{
				u->next = new Node(u1->data);
				u = u->next;
				u1 = u1->next;
			}
		}
		else
		{
			Clean();
			head = list2.head;
		}
	}
	return *this;
}

void List:: InsertToHead(const DataType& d)    
{
	if (head != NULL)
	{
		Node* u = new Node(d, head);
		head = u;
	}
	else 
		head = new Node(d, NULL);
}


void List:: InsertToTail(const DataType& d)     
{
	Node*u = head;
	if (u)
	{
		while (u->next)
			u = u->next;
		u->next = new Node(d);
	}
	else
		head = new Node(d, NULL);
}


void List:: InsertAfter(Node* node, const DataType& d)    
{
	if (node && head)
	{
		Node* u = node->next;
		node->next = new Node(d, u);
	}
	else
		if (head == NULL)
			throw 1;
}


void List:: Delete(const DataType& d)         
{
	Node* u = head;
	Node* u2 = u;
	if (u)
	{
		while ((u->next) && (u->data != d))
		{
			u2 = u;
			u = u->next;
		}

		if (u->data == d)
		{
			u2->next = u->next;
			if (u == head)
				head = head->next;
			delete u;
		}
	}
}


Node* List:: Search(const DataType& d)            
{
	Node* u = head;
	while (u)
	{
		if (u->data == d)
			return u;
		u = u->next;
	}
	return NULL;
}


void List:: Clean()                
{
	Node* u = head;
	Node* u2;
	if (u != NULL)
	{
		while (u->next != NULL)
		{
			u2 = u->next;
			delete u;
			u = u2;
		}
		delete u;
		head = NULL;
	}
}


int List:: GetSize()              
{
	int res = 0;
	Node* u = head;
	while (u)
	{
		res++;
		u = u->next;
	}
	return res;
}


void List:: Inverse()                
{
	if (head)
	{
		Node* u = head->next;
		head->next = NULL;
		Node* u2 = head;
		Node* u3;
		while (u)
		{
			u3 = u->next;
			u->next = u2;
			u2 = u;
			u = u3;
		}
		head = u2;
	}
	else 
		head = NULL;
}


List List:: Merge(Node* node, const List& list2)
{
	List res;
	Node* u = head;
	if (head)
	{
		res.head = new Node(head->data);
		Node* u1 = res.head;
		while (u->next && u != node)
		{
			u1->next = new Node(u->next->data);
			u = u->next;
			u1 = u1->next;
		}
		if (u == node)
		{
			if (list2.head)
			{
				Node* u2 = list2.head;
				while (u2)
				{
					u1->next = new Node(u2->data);
					u2 = u2->next;
					u1 = u1->next;
				}
			}
			while (u->next)
			{
				u1->next = new Node(u->next->data);
				u = u->next;
				u1 = u1->next;
			}
		}
		u1->next = NULL;
	}
	return res;
}


List List:: Merge(const List& list2)
{
	List res(*this);

	if (res.head && list2.head)
	{
		Node* u = res.head;
		while (u->next)
			u = u->next;
		Node* u1 = list2.head;
		while (u1)
		{
			u->next = new Node(u1->data);
			u = u->next;
			u1 = u1->next;
		}
		u->next = NULL;
	}
	else 
		if (!(res.head))
			res = List(list2);
	return res;
}


ostream& operator<<(ostream& os, const List& l) 
{
	Node * u=l.head;
	while (u)
	{
		os << u->data << " ";
		u=u->next;
	}
	return os;
}


bool List:: operator==(const List& list2) const        
{   
	Node* u = head;
	Node* u1 = list2.head;
	bool res = true;

	if ((u && !u1) || (!u && u1))
		res = false;
	if (res)
	{
		while (u && u1 )
		{
			if (u->data != u1->data)
			{
				res = false;
				u = u->next;
				u1 = u1->next;
			}
			else
			{
				u = u->next;
				u1 = u1->next;
			}
		}
	}	
	return res;
}
