vector<int> minHeap;

void minHeap_insert (int val) {
    minHeap.push_back(val);        // 1. Insert at last position
    int i = minHeap.size() - 1;

    // 2. Heapify-up
    while (i > 0) {
        int parent = (i - 1) / 2;

        if (minHeap[parent] > minHeap[i]) {
            swap (minHeap[parent], minHeap[i]);
            i = parent;
        } else {
            break;
        }
    }
}

/*

Time Complexity: O(log n)

*/