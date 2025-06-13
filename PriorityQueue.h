#pragma once
#include <vector>
#include <string>
#include <utility>

using namespace std;

class PriorityQueue {
private:
    vector<pair<int, string>> heap;
    void moveUp(int index);
    void moveDown(int index);
    int findIndex(const std::string& data) const;

public:
    void Enqueue(int priority, const string& data);
    pair<int, string> Dequeue();
    pair<int, string> Peek() const;
    bool isEmpty() const;
    void DecreasePriority(const string& data, int newPriority);
};