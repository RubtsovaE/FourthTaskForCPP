#pragma once
#include "HashTable.h"

// ���������������� ��������� ������
struct Node {
	int hashCode;
	Hash *hash;
	Node *next, *prev;

	Node() {
		next = prev = this;
	}
};

// ��������
class Iterator {
	Node *beginNode;
	Node *currNode;

public:
	Iterator(Node *bufferNode) : beginNode(bufferNode) {
		start();
	}

	// ������ ������
	void start() {
		currNode = beginNode->next;
	}

	// �������� ������� �������
	Node *current() {
		return currNode;
	}

	// �������� �������� �� ��������� �������
	void next() {
		if (currNode != beginNode) currNode = currNode->next;
	}

	// �������� ��� �� ��������������
	bool finish() {
		return currNode == beginNode;
	}
};