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

