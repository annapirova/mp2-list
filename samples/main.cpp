#include <iostream>
#include "list.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
	List list;
    list.InsertToTail(2);
    list.InsertToTail(4);
    list.InsertToTail(9);
    list.InsertToTail(5);
    list.InsertToTail(3);
    list.Inverse();
/*    int a_i;
    while (1) {
        cin >> a_i;
        if (a_i) {
            list.InsertToTail(a_i);
        }
        else break;
    }*/
//	list.(a);
	cout << *list.Search(2);
    return 0;
}