### Fulfilling the k minute check:
- Whatevere you take right from, youre greater than that, whatver you take left from, youre smaller than that.
- The closest elements to you would be the ones you took the above step most recently.
- If you don't take any one of these steps then that corresponding element doesnt exist.

### Complexity of search and insertion:
- O(height of the tree) because if there is no notion to balance the tree after insertion/removal, the tree can get skewed.

Our goal: convert this complexity to logN too.

### Augmentation
- means enhancing the basic structure/operation of the bst to have additional features other than basic ones.
- here we are adding rank (knowing how many elements are less than given element.)
- For this: we have an additional value with each node, denoting the no of nodes in that subtree.   
- Finding rank of an element: whatever you take right from, add 1 (for that node) and the size of left subtree of that node.
    spl case: if the element it self exists: stop at that element and add the size of its left subtree.
### Application
- Runway allocation problem: requirements:

### Enhancing time complexity from O(height) to O(log N) or basically keeeping things balanced as they should be: AVL Tree
