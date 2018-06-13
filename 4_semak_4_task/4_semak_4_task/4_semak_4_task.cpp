// 4_semak_4_task.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "stdlib.h"
#include <iostream>
#include <string>
#include "LinkedHashTable.h"

using namespace std;

int main(){
	cout << "Start" << endl;
	LinkedHashTable table;
	
	table.add("Petrov", "IMIT");
	table.add("Ivanov", "FCS");
	table.add("Kurochkin", "FCS");
	table.add("urochkinK", "IMIT");
	table.add("Kurochkni", "IMIT");
	table.add("Ivanova", "FCS");
	table.add("Danilov", "IMIT");
	table.add("anilovD", "IMIT");
	table.add("Semenov", "IMIT");
	table.add("Lapinina", "IMIT");
	
	cout << "Test 1 (enter) :" << endl;
	LinkedHashTable::Iterator it(&table);
	it.start();
	while (!it.isFinish()){
		Node node = it.get();
		cout << "key: " << (&node)->key << "   value: " << (&node)->value << endl;
		cout << endl;
		it.next();
	}

	cout << "Test 2 (table) :" << endl;
	table.write();

    table.remove("urochkinK");
	table.remove("Kurochkni");
	table.remove("Ivanova");
	table.remove("Danilov");
	table.remove("anilovD");
	table.remove("Semenov");

	cout << "Test 3 (remove) :" << endl;
	LinkedHashTable::Iterator iter(&table);
	iter.start();
	while (!iter.isFinish()){
		Node node = iter.get();
		cout << "key: " << (&node)->key << "   value: " << (&node)->value << endl;
		cout << endl;
		iter.next();
	}

	cout << "Test 4 (lookAtElem) :" << endl;
	cout << "with key 'Petrov' value: " << table.lookAtElem("Petrov") << endl;
	cout << endl;
	cout << "with key 'Lapinina' value: " << table.lookAtElem("Lapinina") << endl;
	cout << endl;

	cout << "Test 5 (doEmpty) :" << endl;
	table.doEmpty();
	cout << "table is empty: " << table.isEmpty() << endl;
	cout << endl;

	return 0;
}