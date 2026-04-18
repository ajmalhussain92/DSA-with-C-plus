vector<int> maxHeap;

void maxHeap_insert (int val) {
    maxHeap.push_back (val);        // 1. Insert at last position
    int i = maxHeap.size() - 1;

    // 2. Heapify-up
    while (i > 0) {
        int parent = (i - 1) / 2;

        if (maxHeap[parent] < maxHeap[i]) {
            swap (maxHeap[parent], maxHeap[i]);
            i = parent;
        } else {
            break;
        }
    }
}

/*

Time Complexity: O(log n)

*/