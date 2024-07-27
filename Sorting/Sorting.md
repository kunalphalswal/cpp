## Quick Sort
### Partition Function
relatively sorts the array around pos position. meaning:
- The element (say x) that would have been present at position pos if the array was sorted, will be present at that pos when this func ends.
- while the rest of the array might not be completely sorted, it would be relatively sorted around x, i.e those smaller than x would be present before x and those larger than x would be present after x. (sorted or unsorted)
- the partition algo is hard to come up by yourself, so remember it.
### Quick Sort Function
- calls partition on the given array.
- through partition function, one position i.e. pivot is sorted. So the quick Sort function is called again on left and right side of pivot.
## Quick Select
- We need to find which element would occur at position k, if the array was sorted.
- To determine this, we need not sort the whole array. (usually)
- We play our luck with the partition algorithm of quick sort which places any given element (called pivot) at its sorted position and we see if that sorted position is equal to our desired position. 
- If yes, then we return pivot, else we again call the quick select function on one half of the array. (see in code)
- In worst case we will end up sorting the whole array with the complexity of quick sort: Big-O(n^2)
## Heap Sort
- have a heap(max-heap) corresponding to the array to be sorted
- extract the max element one by one to have the array sorted in decreasing order
- Time Complexity: O(NlogN) and theta(NlogN).
## Merge Sort
- Have an array to be sorted, divide it into two parts and call the merge sort function on those two parts. Now the parts are sorted(process is explained below), just merge them.
- If we divide the parts long enough, we'll reach individual elements which are already sorted. So the merge process will start with merging two individual elements into a single array and will progress all the way up to top.
- In the merge process, we use the two finger approach in which we have pointers to the beginning of the two sorted arrays, and we take the smaller of the two pointed elements into our merged array and increase the corresponding pointer and then repeat this process.
## Insertion Sort
For each element from left to right:
- The left side of array to current the element is already sorted, so we just have to place that element in its right position in that array, 
- and we do that by swapping the element with its left element in case the left element is larger than the current element.

