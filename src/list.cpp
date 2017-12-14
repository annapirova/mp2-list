#include "list.h"
  List::List(const List& list2)
 {
	 
 }
   Node& Node::operator=(const Node& node2)
   {
	   data = node2.data;
	   next = node2.next;
   }
   List& List::operator=(const List& list2)
   {
	  
   }
 void List::InserToHead(const DataType& d)
 {
	 Node* tmp = head;
	 head = new Node (d,tmp);
 }
  void List::InserToTail(const DataType& d)
  {
	  Node*tmp = head;
	  if (head==NULL)
		  head = new Node(d,NULL);
	  else
		  {
			  while (tmp->next!=NULL)
			  {
				  tmp=tmp->next;
			  }
			  tmp->next = new Node(d,NULL);
	      }
	  
  }
  void List::InsertAfter(Node* node, const DataType& d)
  {
	  Node*tmp = head, *n;
	  while (tmp!=node)
	  {
		  tmp=tmp->next;
	  }
	  n = tmp->next;
	  tmp->next = new Node(d,n);

  } 
  void List::Delete(const DataType& d)
  {
	  Node* tmp = head, *prev=NULL;
	  if (tmp == NULL)
		  return;
	  while ((tmp != NULL)&&(tmp->data!=d))
	  {
		  prev = tmp;
		  tmp = tmp->next;
	  }
		  if(prev!=NULL)
			  prev->next = tmp->next; 
		  else 
			  head = tmp->next; 
		  delete tmp;
	  
  }
  Node* List::Search(const DataType& d)
  {
	  Node* tmp = head;
	  while (tmp!=NULL)
	  {
		  if(tmp->data==d)
			  return tmp;
		  else
		  {
			  tmp = tmp->next;
		  }
	  }
	  return tmp;
  }
  void List::Clean()
  {
	  Node *tmp, *n;
	  while (tmp->next != NULL)
	  {
		  n = tmp->next->next;
		  delete tmp->next;
		  tmp->next = n;
	  }
	  delete tmp;
  }
  int List::GetSize()
  {
	  int size=0;
	  Node* tmp = head;
	  while (tmp!=NULL)
	  {
		   size+=1;
		  tmp=tmp->next; 
	  }
	  return size;
  }
  Node* List::GetHead() { return head;}
  void List::Inverse()
  {
  }
  List List::Merge(Node* node, const List& list2)
  {
  }  
  List List::Merge(const List& list2)
  {
  }
  ostream& operator<<(ostream& os, const List& l)
  {
	  List list;
	  Node*tmp = list.head;
	  while (tmp != NULL)
	  {
		  cout << tmp->data << " ";
		  tmp = tmp->next;
	  }

  }
