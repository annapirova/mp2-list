# mp2-list

  1) void InsertAfter(const myiterator& it, const DataType& d); // вставить элемент d после звена node
  2) myiterator Search(const DataType& d); // найти указатель на звено со значением data = d
  3) void Delete(const myiterator& it); // удалить звено со значением data = d	
							
  4) void Delete(const myiterator& start, const myiterator& finish);

  5) void DeleteAll(const DataType& d);

  6) void Inverse(); // инвертировать список, т.е. звенья должны идти в обратном порядке

  7) List Merge(const myiterator& start, const List& list2); // создать список3, добавив список2 в текущий список после итератора 

  8) void MergeWith(const myiterator& start, const List& list2); // в *this добавить список2 после итератора

  9) friend ostream& operator<<(ostream& os, const List& l);	
  
  10) void MadeUnique(); // исключить повторяющиеся звенья

 11) void Reordering(); // пересортировка списка: создать новый список, в кот сначала четные, потом нечетные звенья
  
 12) bool Cycle(); // определить, есть ли цикл в списке
