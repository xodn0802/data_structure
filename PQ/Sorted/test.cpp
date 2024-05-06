#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

struct compare {
	bool operator()(const int& e1, const int& e2) const {
		return e1 < e2;
	}
};

class sortedSeqPQ {
public:
	int size();
	bool empty();
	void insert(int e);
	int min();
	void removeMin();

	vector<int> seq;
};

int sortedSeqPQ::size() {
	return seq.size();
}

bool sortedSeqPQ::empty() {
	return (seq.size() == 0);
}

void sortedSeqPQ::insert(int e) {
	compare C;
	int idx = 0;
	for (idx = 0; idx < seq.size(); idx++) {
		if (C(seq[idx], e))break;
	}
	seq.insert(seq.begin() + idx, e);
}

int sortedSeqPQ::min() {
	if (empty()) return -1;

	return seq.back();

}

void sortedSeqPQ::removeMin() {
	if (empty()) return;

	seq.pop_back();
}

