//
// Created by Pedro's Jet on 1/3/2026.
//

#ifndef TUTORIAL_HEAP_H
#define TUTORIAL_HEAP_H

#include <vector>
using namespace std;

namespace letscode {

class Heap {

    int *array;
    unsigned long size;

    // A bottom up sift down heapify
    void heapify(const int i, const int n) const {
        int largest = i;
        const int l = i * 2 + 1;
        const int r = i * 2 + 2;

        if (l < n && array[l] > array[largest]) {
            largest = l;
        }

        if (r < n && array[r] > array[largest]) {
            largest = r;
        }

        if (i != largest) {
            std::swap(array[largest],array[i]);
            heapify(largest, n);
        }
    }

public:
    explicit Heap(vector<int>& a)  {array=&a[0]; size = a.size();}
    ~Heap() = default;

    // sort with range [n - k , n)
    void RangeSort(const int k) const {
        const int limit = static_cast<int>(size) - k;

        // build max heap
        for (int j = static_cast<int>(size) / 2; j>=0; j--) {
            heapify(j, static_cast<int>(size));
        }

        // Now, every subtree is itself a heap.
        for (int i = static_cast<int>(size)-1; i>=limit; i--) {
            std::swap(array[0], array[i]);
            heapify(0, i);
        }
    }

    int Get(const int k) const {
        return array[size - k];
    }
};

class Solution {
public:
    static int findKthLargest(vector<int>& nums, const int k) {
        const auto heap = Heap(nums);
        puts("find K th largest");
        heap.RangeSort(k);
        return heap.Get(k);
    }
};
} // letscode

#endif //TUTORIAL_HEAP_H