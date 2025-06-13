#include "PriorityQueue.h"
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::chrono;

int main() {
    const string example = "SomeString";
    const int priority = 1;

    cout << "SIZE" << "\t" << "avg_enqueue_times" << "\t" << "avg_dequeue_times" << "\t" << "avg_peak_times" << "\t" << "decrease_priority_times" << endl;

    for (int size = 1000; size <= 20000; size += 1000) {
        vector<double> enqueueTimes, dequeueTimes, peekTimes, descreasePriorityTimes;

        for (int trial = 0; trial < 5; ++trial) {
            PriorityQueue pq;

            auto start = high_resolution_clock::now();
            for (int i = 0; i < size; ++i) {
                pq.Enqueue(priority, example);
            }
            auto end = high_resolution_clock::now();
            enqueueTimes.push_back(duration<double, milli>(end - start).count());

            start = high_resolution_clock::now();
            for (int i = 0; i < size; ++i) {
                pq.Peek();
            }
            end = high_resolution_clock::now();
            peekTimes.push_back(duration<double, milli>(end - start).count());

            start = high_resolution_clock::now();
            while (!pq.isEmpty()) {
                pq.Dequeue();
            }
            end = high_resolution_clock::now();
            dequeueTimes.push_back(duration<double, milli>(end - start).count());

            start = high_resolution_clock::now();
            for (int i = 0; i < size; ++i) {
                pq.DecreasePriority(example, i);
            }
            end = high_resolution_clock::now();
            descreasePriorityTimes.push_back(duration<double, milli>(end - start).count());
        }

        auto avg = [](vector<double>& times) {
            times.erase(max_element(times.begin(), times.end()));
            double sum = 0;
            for (double t : times) sum += t;
            return sum / times.size();
        };
        cout << size << "\t" << avg(enqueueTimes) << "\t" << avg(dequeueTimes) << "\t" << avg(peekTimes) << "\t" << avg(descreasePriorityTimes) << endl;
    }

    return 0;
}