#include "list.h"
List::List(const List& list2)
{
	head = new Node(list2->head);
}

void List::InserToHead(const DataType& d)
{
	
}

void List::InserToTail(const DataType& d)
{
	Node* tmp;
	tmp = head;
	if (tmp == NULL)
		head = new Node(data, NULL);
	else 
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
	}
	tmp->next = new Node(data, NULL);
}

void List::InsertAfter(Node* node, const DataType& d)
{
	Node* n = new Node(data, node->next);
	node->next = n;
}

Node* List::Search(const DataType& d)
{
	Node* tmp = head;
	while (tmp != NULL)
	{
		if (tmp->data == data)
			return tmp;
		else 
			tmp = tmp->next;
	}
	return tmp;
}

void List::Delete(const DataType& d)
{
	Node* prev, *tmp;
	tmp = head; prev = NULL;
	while ((tmp != NULL) && (tmp->data != d))
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = tmp->next;
	delete tmp;
}

void List::Inverse()
{
	Node* tmp = head;
}