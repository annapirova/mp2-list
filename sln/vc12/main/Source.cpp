#include <iostream>
#include "list.h"

void main()
{
	List l;
	l.InsertToTail(0);
	l.InsertToTail(1);
	l.InsertToTail(2);
	l.InsertToTail(3);
	List l2(l);
	myiterator it = l.begin();
	++it; ++it;

	List res = l.Merge(it, l2);

	std::cout << l << endl;
	std::cout << l2 << endl;
	std::cout << res << endl;

	res.MadeUnique();
	std::cout << res << endl;
}