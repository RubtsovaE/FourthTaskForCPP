#pragma once
#include <iostream>
#define CONST 256

using namespace std;

struct Node{
	string key;
	string value;
};

class LinkedHashTable
{
private:
	struct linkedNode{
		Node* it;
		linkedNode* next;
	};

	struct ListEnter{
		linkedNode* now;
		ListEnter* next;
	};

	linkedNode* hash[CONST];
	ListEnter* first;
	ListEnter* last;

	int hashFunc(string key){
		int h = 0;
		for (int i = 0; i<key.size(); i++){
			h += key[i];
		}
		return h % CONST;
	}
public:
	class Iterator{
	private:
		ListEnter* first;
		ListEnter* stay;
	public:
		Iterator(LinkedHashTable* f){
			first = f->first;
			stay = f->first;
		}

		void start(){
			stay = first;
		}

		Node get(){
			return *(stay->now->it);
		}

		void next(){
			stay = stay->next;
		}

		bool isFinish(){
			return stay == nullptr;
		}
	};

	LinkedHashTable(){
		for (int i = 0; i < CONST; i++){
			hash[i] = nullptr;
		}
		last = nullptr;
		first = nullptr;
	}

	void add(string key, string value){
		int pos = hashFunc(key);
		linkedNode* t = hash[pos];
		if (t == nullptr){
			hash[pos] = new linkedNode;
			hash[pos]->it = new Node;
			hash[pos]->it->key = key;
			hash[pos]->it->value = value;
			hash[pos]->next = nullptr;
			if (nullptr == last && nullptr == first){
				first = new ListEnter;
				last = first;
				first->now = hash[pos];
				first->next = nullptr;
			}
			else {
				last->next = new ListEnter;
				last->next->now = hash[pos];
				last->next->next = nullptr;
				last = last->next;
			}
			return;
		}
		while (t->next != nullptr){
			if (key == t->it->key){
				throw "Error";
			}
			t = t->next;
		}
		if (key == t->it->key){
			throw "Error";
		}
		t->next = new linkedNode;
		t->next->it = new Node();
		t->next->it->key = key;
		t->next->it->value = value;
		t->next->next = nullptr;
		
		last->next = new ListEnter;
		last->next->now = t->next;
		last->next->next = nullptr;
		last = last->next;
	}

	void remove(string key){
		ListEnter* t = first;
		while (t != nullptr){
			if (t->now->it->key == key){
				if (t->now->next != nullptr){
					linkedNode* temp = t->now;
					temp->it = temp->next->it;
					temp->next = temp->next->next;
				}
				if (t->next != nullptr){
					t->now = t->next->now;
					t->next = t->next->next;
				}
				else {
					ListEnter* p = first;
					while (p->next != t)p = p->next;
					p->next = nullptr;
					delete t;
				}
			}
			t = t->next;
		}
	}

	string lookAtElem(string key){
		int pos = hashFunc(key);
		linkedNode* temp = hash[pos];
		while (temp != nullptr){
			if (temp->it->key == key)return temp->it->value;
			temp = temp->next;
		}
		throw "Key doesn't exist.";
	}

	void doEmpty(){
		for (int i = 0; i < CONST; i++){
			delete[] hash[i];
			hash[i] = nullptr;
		}
		last = nullptr;
		first = nullptr;
	}

	bool isEmpty(){
		return first == nullptr && last == nullptr;
	}

	void write(){
		cout << "Position:   Value:" << endl;
		cout << endl;
		int c = 0;
		while (c != CONST){
			if (hash[c] != nullptr){
				cout << c << "         ";
				linkedNode* el = hash[c];
				while (el != nullptr){
					cout << "key: " << el->it->key << " value:" << el->it->value << "    ";
					el = el->next;
				}
				cout << endl;
				cout << endl;
			}
			c++;
		}
	}
};