#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class AdaptablePriorityQueue {
private:
    class Entry {
    public:
        int bid;
        string name;
        Entry(int b, const string& n) {
            bid = b;
            name = n;
        }
    };

    vector<Entry> heap;

    int left_child(int i) {
        return 2 * i + 1; // GET LEFT CHILD - 0(1)
    }

    int right_child(int i) {
        return 2 * i + 2; // GET RIGHT CHILD - 0(1)
    }

    int parent(int i) { 
        return (i - 1) / 2; // GET PARENT - 0(1)
    }

    void swapEntries(int i, int j) { // swap funciton - 0(1)
        Entry tmp = heap[i];
        heap[i] = heap[j];
        heap[j] = tmp;
    }

    void heapify_up(int i) { // 0(log n)
        int p = parent(i);
        while (i > 0 && heap[i].bid > heap[p].bid) {
            swapEntries(i, p);
            i = p;
            p = parent(i);
        }
    }

    void heapify_down(int i) { // 0(log n)
        int leftChild = left_child(i);
        int rightChild = right_child(i);
        int maxIndex = i;

        if (leftChild < heap.size() && heap[leftChild].bid > heap[maxIndex].bid) {
            maxIndex = leftChild;
        }
        if (rightChild < heap.size() && heap[rightChild].bid > heap[maxIndex].bid) {
            maxIndex = rightChild;
        }
        if (maxIndex != i) {
            swapEntries(i, maxIndex);
            heapify_down(maxIndex);
        }
    }

    int findIndex(const string& name) { // 0(n)
        for (int i = 0; i < heap.size(); i++) {
            if (heap[i].name == name) {
                return i;
            }
        }
        return -1;
    }

public: // main can access

    void enqueue(int bid, const string& name) { // 0(log n) - heapify_up
        Entry new_entry(bid, name);
        heap.push_back(new_entry);
        heapify_up(heap.size() - 1);
    }

    string peek() { // 0(1)
        if (heap.empty()) {
            return "The queue is empty.";
        }
        return heap[0].name;
    }

    string dequeue() { // 0(log n) - heapify_down
        if (heap.empty()) {
            return "The queue is empty.";
        }
        string name = heap[0].name;
        swapEntries(0, heap.size() - 1);
        heap.pop_back();
        heapify_down(0);
        return name;
    }

    bool removeAny(const string& name) { // 0(log n) - heapify_down/up
        int idx = findIndex(name);
        if (idx == -1) {
            return false;
        }
        swapEntries(idx, heap.size() - 1);
        heap.pop_back();
        if (idx < heap.size() && idx > 0) {
            int parentIdx = (idx - 1) / 2;
            if (heap[idx].bid > heap[parentIdx].bid) {
                heapify_up(idx);
            }
            else {
                heapify_down(idx);
            }
        }
        else if (idx == 0) {
            heapify_down(idx);
        }

        return true;
    }

    void print() { // 0(n)
        for (int i = 0; i < heap.size(); i++) {
            cout << "[" << heap[i].bid << ", " << heap[i].name << "] ";
        }
        cout << endl;
    }

    bool isEmpty() { // 0(1)
        return heap.size() == 0;
    }
};