/*

A Heap is a: Complete Binary Tree + Heap Property.

There are two main types:
	1. Min-Heap
	2. Max-Heap


1. Min-Heap

	-> Parent ≤ Children
	-> Smallest element at root.
	
	    10
       /  \
      20   30
     /  \
    40  50

----------------------------------------------

2. Max-Heap

	-> Parent ≥ Children
	-> Largest element at root.
	
	    50
       /  \
      40   30
     /  \
    20  10

----------------------------------------------

Heap Insertion Logic

Step 1: Insert at last available position

(This maintains the complete tree property.)

Step 2: Fix property using “Heapify Up”

For Min-Heap:
	If child < parent → swap

For Max-Heap:
	If child > parent → swap

Repeat until valid.

Time Complexity: O(log n)

------------------------------------------------

Heap Implementation in C++:
	
	A Heap is implemented using array.
	If node index = i, then
		Left child  = 2*i + 1
		Right child = 2*i + 2
		Parent      = (i-1)/2
	
	
	Max-Heap (default):
		priority_queue<int> pq;

	Min-Heap:
		priority_queue<int, vector<int>, greater<int>> pq;

--------------------------------------------------

Heap uses:

	i)	Priority Queue
	ii)	Dijkstra’s algorithm
	iii)Top K elements
	iv)	Heap Sort
	v)	Scheduling problems
	
