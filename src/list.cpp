#include "list.h"


bool Node::operator==(const Node& node2) const
{
	bool flag = false;
	if ((data == node2.data) && (next == node2.next))
		flag = true;
	return flag;
}

List::List(const List& list2)
{
	if (list2.head == NULL)
	{
		head = list2.head;
	}
	else
	{
		head = new Node(list2.head->data, list2.head);
		Node *unit1 = head;
		Node *unit2 = list2.head->next;
		while (unit2 != NULL)
		{
			unit1->next = new Node(unit2->data, unit2->next);
			unit1 = unit1->next;
			unit2 = unit2->next;
		}
	}


}
void List::Clean()
{
	Node* unit1 = head;
	Node* unit2;
	if (unit1 != NULL)
	{
		while (unit1->next != NULL)
		{
			unit2 = unit1->next;
			delete unit1;
			unit1 = unit2;
		}
		delete unit1;
		head = NULL;
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
			Node *unit1 = head;
			Node *unit2 = list2.head->next;
			while (unit2 != NULL)
			{
				unit1->next = new Node(unit2->data, unit2->next);
				unit1 = unit1->next;
				unit2 = unit2->next;
			}
			return *this;
		}
	}

}

void List::InsertToHead(const DataType& d)
{
	Node* node = new Node(d);
	node->next = head;
	head = node;
}

void List::InsertToTail(const DataType& d)
{
	Node* unit = head;
	if (unit)
	{
		while (unit->next)
			unit = unit->next;
		unit->next = new Node(d);
	}
	else
		head = new Node(d);
}/*--------------------------------------------------------------*/

void List::InsertAfter(Node* node, const DataType& d)
{
	if (node && head)
	{
		Node* unit = node->next;
		node->next = new Node(d, unit);
	}
	else

		if (head == NULL)
			throw 0;
}

void List::Delete(const DataType& d)
{
	Node* unit = head;
	Node* unit1=unit;
	if (head)
	{
		if (head->data == d)
		{
			unit1 = unit->next;
			delete head;
			head = unit1;
		}
		else
		{
			while (unit->next)
			{
				if (unit->next->data == d)
				{
					unit1 = unit->next;
					break;
				}
				unit = unit->next;
			}
			if (unit->next)
			{
				unit->next = unit1->next;
				delete unit1;
			}
		}
	}

}

Node* List::Search(const DataType& d)
{
	Node* unit = head;
	while (unit)
	{
		if (unit->data == d)
			return unit;
		unit = unit->next;
	}
	return NULL;
}

int List::GetSize()
{
	int s = 0;
	Node* unit = head;

	while (unit != NULL)
	{
		s++;
		unit = unit->next;
	}

	return s;
}


void List::Inverse()
{
	if (head)
	{
		Node* unit1 = head->next;
		head->next = NULL;
		Node* unit2 = head;
		Node* loc;
		while (unit1)
		{
			loc = unit1->next;
			unit1->next = unit2;
			unit2 = unit1;
			unit1 = loc;
		}
		head = unit2;
	}

}

List List::Merge(Node* node, const List& list2)
{
	List res;
	Node* unit1 = head;
	if (head)
	{
		res.head = new Node(head->data);
		Node* unit2 = res.head;
		while (unit1->next && unit1 != node)
		{
			unit2->next = new Node(unit1->next->data);
			unit1 = unit1->next;
			unit2 = unit2->next;
		}
		if (unit1 == node)
		{
			if (list2.head)
			{
				Node* unit3 = list2.head;
				while (unit3)
				{
					unit2->next = new Node(unit3->data);
					unit3 = unit3->next;
					unit2 = unit2->next;
				}
			}
			while (unit1->next)
			{
				unit2->next = new Node(unit1->next->data);
				unit1 = unit1->next;
				unit2 = unit2->next;
			}
		}
		unit2->next = NULL;
	}

	return res;
}

List List::Merge(const List& list2)
{
	List res(*this);
	if (res.head && list2.head)
	{
		Node* unit1 = res.head;
		while (unit1->next)
			unit1 = unit1->next;


		Node* unit2 = list2.head;
		while (unit2)
		{
			unit1->next = new Node(unit2->data, unit2->next);
			unit1 = unit1->next;
			unit2 = unit2->next;
		}
		unit1->next = NULL;
	}
	else
		if (res.head == NULL)
			res = List(list2);
	return res;

}

bool List::operator==(const List& list2) const
{
	bool flag = true;
	Node* unit1 = head;
	Node* unit2 = list2.head;
	while (unit1 && unit2 && flag)
	{
		if (unit1->data != unit2->data)
			flag = false;
		else
		{
			unit1 = unit1->next;
			unit2 = unit2->next;
		}

	}
	if (unit1 || unit2)
		flag = false;
	return flag;
}/*--------------------------------------------------------------*/

ostream & operator<<(ostream & os, const List & l)
{
	Node* unit = l.head;
	while (unit)
	{
		os << unit->data << " ";
		unit = unit->next;
	}
	return os;
}