#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//주석이요 추가
struct Node {
	int e;
	Node* next;
};

Node* head;
Node* tail;

int empty() {
	if (head == NULL || tail == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

void Print() {
	if (empty()) {
		cout << "empty" << endl;
		return;
	}
	Node* it = head;
	while (it != NULL) {
		cout << it->e << " ";
		it = it->next;
	}
	cout << endl;

}

void AddFront(int idx) {
	Node* v = new Node;
	if (empty()) {
		tail = v;
	}
	v->e = idx;
	v->next = head;
	head = v;
}

void AddBack(int idx) {
	
	Node* v = new Node;
	v->e = idx;
	v->next = NULL;
	if (empty()) {
		head = tail = v;
	}
	else {
		tail->next = v;
		tail = v;
	}
}

void RemoveFront() {
	if (empty()) {
		cout << "empty" << endl;
		return;
	}
	Node* it = head;
	head = it->next;
	cout << it->e << endl;
	delete it;
	if (empty()) {
		tail = NULL;
	}

}

void RemoveBack() {
	if (empty()) {
		cout << "empty" << endl;
		return;
	}
	Node* current = head;
	if (current == tail) {
		head = tail = NULL;
		cout << current->e << endl;
		delete current;
		return;

	}
	else {
		while (current->next != tail) {
			current = current->next;
		}
		cout << tail->e << endl;
		tail = current;

		delete tail->next;
		tail->next = NULL;
	}
}

void Update(int idx, int val) {
	if (empty()) {
		cout << "empty" << endl;
		return;
	}
	Node* it = head;
	while (idx > 0) {
		it = it->next;
		if (it == NULL) {
			cout << "error" << endl;
			return;
		}
		idx--;


	}
	it->e = val;
}

void Min() {
	if (empty()) {
		cout << "empty" << endl;
		return;
	}
	Node* it = head;
	int min_val = it->e;
	int idx = 0;
	int i = 0;
	while (it != NULL) {
		
		if (it->e < min_val) {
			min_val = it->e;
			i = idx;
		}
		idx++;
		it = it->next;

	}
	cout << i << " " << min_val << endl;

}

void Max() {
	if (empty()) {
		cout << "empty" << endl;
		return;
	}
	Node* v = head;
	int idx = 0;
	int max_val = head->e;
	int i = 0;
	while (v != NULL) {
		if (max_val < v->e) {
			max_val = v->e;
			i = idx;
		}
		idx++;

		v = v->next;

	}
	cout << i << " " << max_val << endl;
}

int main() {
	int m, x, i;
	string str;

	freopen("cin_2.txt", "r", stdin);

	cin >> m;

	for (int test = 0; test < m; test++) {
		cin >> str;
		
		if (str == "Print") {
			Print();
		}
		else if (str == "AddFront") {
			cin >> x;
			AddFront(x);
		}
		else if (str == "AddBack") {
			cin >> x;
			AddBack(x);
		}
		else if (str == "RemoveFront") {
			RemoveFront();
		}
		else if (str == "RemoveBack") {
			RemoveBack();
		}
		else if (str == "Update"){
			cin >> i >> x;
			Update(i, x);
		}
		else if (str == "Min") {
			Min();
		}
		else if (str == "Max") {
			Max();
		}
	}
}
