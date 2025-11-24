
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class BinaryHeap {
public:
	vector <int> heap;
	int size;
	int median;

	BinaryHeap() {
		size = 0;
		median = 0;
		heap.push_back(0);
	}
	int parent(int index) {
		return index / 2;
	}
	int left(int index) {
		return index * 2;
	}
	int right(int index) {
		return index * 2 + 1;
	}
	int max() {
		if (size == 0) {
			return;
		}
		return heap[1];
	}
	void sink(int index) {
		while (true) {
			int left = left(index);
			int right = right(index);
			int bigger = left;
			if (left >= this->size) {
				break;
			}
			if (right <= this->size && heap[right] > heap[left]) {
				bigger = right;
			}if (bigger <= this->size && heap[index] < heap[bigger]) {
				swap(heap[index], heap[bigger]);
				index = bigger;
			}
			else {
				break;
			}
		}
	}//O(Log n)

	void bubbleup(int index) {
		while (index > 1) {
			int father = parent(index);
			if (heap[father] < heap[index]) {
				swap(heap[father], heap[index]);
				index = father;
			}
			else {
				break;
			}
		}
	}

	void insert(int data) {
		heap.push_back(data);
		size++;
		bubbleup(size);
	}//O(logN)

	void removeMax() {
		swap(heap[1], heap[size]);
		heap.pop_back();
		size--;
		sink(1);
	}//O(logN)

	void updateMedian() {
		if (size % 2 == 1) {
			this->median = heap[size / 2 + 1];
		}
		else {
			this->median = (heap[size / 2] + heap[size / 2 + 1]) / 2;
		}
	}
	void printMedian() {
		cout << fixed << setprecision(2) << median;
	}

};

class PriorityQueue {
	BinaryHeap heap = new BinaryHeap();
	void insert(int value) {
		heap.insert(value);
	}

	int delMax() {
		int result = heap.max();
		heap.removeMax();
		return result;
	}

	bool isEmpty() {
		return heap.size == 0;
	}
	int size() {
		return heap.size;
	}
};




int main() {
	return 0;
}
