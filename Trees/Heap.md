# Heap
Heap is a nearly complete binary tree.
Max-Heap is a heap where each node's value is greater than or equal to the value of its children.
Min-heap is where each node's value is less than or equal to the value of child nodes.
From now Heap means max-heap.

## Heapify
Assuming a single violation in a heap, how to convert it to a heap.
### Implementation:

O(logN)

### Two uses:
1. Adjusting a single violating node given the rest of the heap is max heap (including the left and right subtrees of the violating nodes.)
2. Converting an unsorted array to a heap. This is just step 1 applied repeatedly.

## Heap Operations
Using heapify algorithm.
1. Find the max element. 

O(1) because it's the root node or the 0th element.

2. Insert a new element. 

O(logN) because in worst case, we need to reverse the node values from bottom to root.

3. Remove the max element. 

O(logN) because in worst case, we need to reverse the node values from top to bottom.

4. Convert an unsorted array to a heap:
- Elements from n/2 through n will act as leaves and are satisfy heap property. (not really, what if the last level of corresponding heap contains less than n/2 elements say n=10, last level will only contain three elements. Somehow, as the algo is applied on subsequent elements, every node will settle to the position it's suppossed to be at.)
- Take element from n/2-1 to 1 and apply heapify algo on each element one by one.
Are we just placing the elements directly in the heap array as they were in the original array and then heapifying them if they are violating anything? 
Assuming N as power of 2:
O(NlogN) because we traverse all the elements and apply heapify (O(logN)) on them. Hence, N*logN. BUT
In general cases, the last level is O(1) operations, second last(that contains n/4 elements) is O(1.c) because in worst case you have to substitue the element with its child, third last level (that contains n/8 elements) is O(2.C) because in worst case you'll have to replact the element all the way down to last level ie. 2 levels down.... and so on, at the root node which is logN levels high, in the worst case, we'll need to replace all the way down to last levels which costs O(logN.C) time.
Mathematics says that all these operations sum to give an order of N. Calculation:

Hence the average case complexity is O(N) and in worst case i.e. when N is really large and the input scenario is really against us, the complexity becomes o(NlogN).

## Memory Implementation of Heap
- An array where each element corresponds to a node. This also ensures we have a complete binary tree because a new element is inserted at the back of array(meaning last node of already complete binary tree.) and old is removed from the back too.
- ith element's children would be 2i and 2i+1.
- ith element's parent would be i/2.
- A new element would be inserted at the back of the array(last node of heap) in O(1) and then heapify would be applied from bottom up of that node.
- To remove the max element, we first replace it with the last element of array and then decrement the size of the array and apply heapify on the root. 

## Common Doubts:
1. In case of removing the topmost element, why can't we replace it with the greater of two child nodes? Because then the new heap can't be guaranteed to be a complete binary tree which is fundamental to other heap operations.

## Beauty:
All the elements in one line from a leaf to the root are independent of other such lines and substitution/heapify/any other operation doesn't affect other lines.