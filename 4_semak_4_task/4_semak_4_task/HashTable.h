


	int hashCode(const K& elem) {
		return (int)elem * 31 + elem;
	}

	template <typename K, typename V>
	class HashObject {
	public:
		Node<K, V>* beginObject;

		HashObject(Node* elem) {
			beginObject = elem;
		}

		void addObject(Node* elem) {
			Node<K, V>* tmp = beginObject;
			while (tmp->next != nullptr) {
				tmp = tmp->next;
			}
			tmp->next = elem;
		}
	};
public:
	HashTable() {
		table = new HashObject*[SIZE];
		current = nullptr;
		length = 0;
	}

	void push(const K& key, const V& value) {
		length++;
		Node<K, V>* tmp = new Node(key, value);
		end->nextBigList = tmp;
		end = tmp;
		int hash = hashCode(key);
		if (table[hash] == nullptr) {
			table[hash] = new HashObject(tmp);
		}
		else {
			table[hash]->addObject(tmp);
		}
	}
	void pop(const K& elem) {
		int hash = hashCode(elem);
		if (table[hash] != nullptr) {
			Node<K, V>* tmp = table[hash]->beginObject;
		}
	}
	V get(const K& elem) {

	}
	void doEmpty() {

	}
	bool isEmpty() {

	}
};