#include "PriorityQueue.h"
#include <algorithm>

using namespace std;

void PriorityQueue::moveUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index].first < heap[parent].first) {
            swap(heap[index], heap[parent]);
            index = parent;
        }
        else {
            break;
        }
    }
}

void PriorityQueue::moveDown(int index) {
    int size = heap.size();
    while (true) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left].first < heap[smallest].first) {
            smallest = left;
        }
        if (right < size && heap[right].first < heap[smallest].first) {
            smallest = right;
        }
        if (smallest == index) break;
        swap(heap[index], heap[smallest]);
        index = smallest;
    }
}

void PriorityQueue::Enqueue(int priority, const string& data) {
    heap.emplace_back(priority, data);
    moveUp(heap.size() - 1);
}

pair<int, string> PriorityQueue::Dequeue() {
    auto result = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    if (!heap.empty()) moveDown(0);

    return result;
}

int PriorityQueue::findIndex(const string& data) const {
    for (int i = 0; i < heap.size(); ++i) {
        if (heap[i].second == data) {
            return i;
        }
    }
    return -1;
}

void PriorityQueue::DecreasePriority(const string& data, int newPriority) {
    int index = findIndex(data);

    heap[index].first = newPriority;
    moveUp(index);
}

pair<int, string> PriorityQueue::Peek() const {
    return heap[0];
}

bool PriorityQueue::isEmpty() const {
    return heap.empty();
}