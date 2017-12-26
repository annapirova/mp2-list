#include "list.h"

Node::Node()
{
	data=0; 
	next=NULL;
}

Node::Node(DataType d, Node* n )
{
	data=d;
	next=n;
}

bool Node::operator==(const Node& node2) const
{
	if ((data==node2.data) && (next==node2.next))
		return true;
	else
		return false;
}

List::List()
{
	head=NULL;
}

List::~List()
{
	Node *t1=head;
	Node *t2;
	if (head!=NULL)
	{
		while (t1!=NULL)
		{
			t2=t1->next;
			delete t1;
			t1=t2;
		}
	head=NULL;
	}	
}

List::List(const List& list2)
{
	if (list2.head==NULL)
		head=NULL;
	else
	{
		head = new Node(list2.head->data, list2.head);
		Node *n1 = head;
		Node *node2 = list2.head->next;
		while (node2 != NULL)
		{
			n1->next = new Node(node2->data, node2->next);
			n1 = n1->next;
			node2 = node2->next;
		}
	}
}

List &List::operator=(const List& list2)
{
	if (this != &list2)
	{
		Clean();
		if (list2.head==NULL)
			head=list2.head;

		else
		{
			head = new Node(list2.head->data, list2.head);
			Node *n1 = head;
			Node *node2 = list2.head->next;
			while (node2 != NULL)
			{
				n1->next = new Node(node2->data, node2->next);
				n1 = n1->next;
				node2 = node2->next;
			}
		}
		
	}
	return *this;
}

int List::GetSize() 
{
	int k=0;
	Node *t=head;
	while (t!=NULL)
	{
		t=t->next;
		k++;
	}
	return k;
}

Node *List::GetHead()
{
	return head;
}

bool List::operator==(const List& list2) const
{
	Node *t1=head;
	Node *t2=list2.head;
	while ((t1!=NULL) && (t2!=NULL))
	{
		if (t1->data != t2->data)
			return false;
		else
		{
			t1=t1->next;
			t2=t2->next;
		}
	}

	if ((t1==NULL) && (t2==NULL))
		return true;
	else
		return false;
}

void List::InsertToHead(const DataType& d)
{
	Node *t=new Node(d, head);
	head=t;
}

void List::InsertToTail(const DataType& d)
{
	Node *t=head;
	if (t!=NULL)
	{
		while (t->next!=NULL)
			t=t->next;
		t->next=new Node(d, NULL);
	}
	else
		head=new Node(d, NULL);
}

void List::InsertAfter(Node* node, const DataType& d)
{
	if (node && head)
	{
		Node *t= node->next;
		node->next = new Node(d, t);
	}
	else if (head == NULL)
		throw "Error!";
}

void List::Delete(const DataType& d)
{
	Node *t=head;
	Node *cur;
	if (head!=NULL)
	{
		if (head->data==d)
		{
			cur = t->next;
			delete head;
			head = cur;
		}
		else
		{
			while (t->next)
			{
				if (t->next->data == d)
				{
					 cur = t->next;
					break;
				}
				t = t->next;
			}
			if (t->next)
			{
				t->next = cur->next;
				delete cur;
			}
		}
	}
}

Node *List::Search(const DataType& d)
{
	Node *cur=head;
	
	while (cur!=NULL)
	{
		if (cur->data==d)
			return cur;
		cur=cur->next;
	}
	return NULL;
}

void List::Inverse()
{
	if (head)
	{
		Node *t= head->next;
		head->next = NULL;
		Node *cur=head;
		Node *p;
		while (t)
		{
			p=t->next;
			t->next=cur;
			cur=t;
			t=p;
		}
		head=cur;
	}
}

void List::Clean()
{
	Node *t1=head;
	Node *t2;
	if (head!=NULL)
	{
		while (t1!=NULL)
		{
			t2=t1->next;
			delete t1;
			t1=t2;
		}
	head=NULL;
	}
}

ostream &operator<<(ostream& os, const List& l)
{
	Node* temp = l.head;
	while (temp)
	{
		os << temp->data << " ";
		temp = temp->next;
	}
	return os;
}

List List::Merge(Node* node, const List& list2)
{
	List res;
	Node *t = head;
	if (head!=NULL)
	{
		 res.head = new Node(head->data, NULL);
		 Node *t1 = res.head;
		 while (t->next && t!=node)
		 {
			 t1->next=new Node(t->next->data, NULL);
			 t=t->next;
			 t1 = t1->next;
		 }
		 if (t==node)
		 {
			 if (list2.head)
			 {
				 Node *t2=list2.head;
				 while (t2)
				 {
					 t1->next =new Node(t2->data,NULL);
					 t2=t2->next;
					 t1=t1->next;
				 }
			 }
			 while (t->next)
			 {
				 t1->next=new Node(t->next->data,NULL);
				 t=t->next;
				 t1=t1->next;
			 }
		 }
		 t1->next=NULL;

	}
	else
		res=list2;

	return res;
}

List List::Merge(const List& list2)
{
	List l1=*this;
	List l2=list2;
	if (head!=NULL)
	{
		if (l2.head == NULL)
			return *this;

		Node *t1 = l1.head;
		Node *t2 = l2.head;
		while (t1->next != NULL)
		{
			t1 = t1->next;
		}
		t1->next = new Node(l2.head->data,NULL);
		t1 = t1->next;
		t2 = t2->next;
		while (t2!=NULL)
		{
			t1->next = new Node(t2->data, NULL);
			t1 = t1->next;
			t2 = t2->next;
		}
	}
	else
		l1=list2;
	return l1;
}









