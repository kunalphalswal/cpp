## Everything should be balanced - Thanos

### Why Balancing matters so much?
- Imagine searching/inserting in a skewed tree. It's complexity will be O(N) instead of O(logN).

## AVL Trees
In AVL trees, the difference in height between left and right subtree cannot be more than 1. 
This doesn't make our BST PERFECTLY balanced but does a very good job in maintaining the O(logN) complexity of search/insert operations in BST.
Of course as long as the step of rebalancing the tree is logN too.
Augmentation: height of each node is stored and height of nullptr is -1.

## Opertions:
### Insert:
1. Simple BST insert.
2. Rebalancing(not perfectly) of AVL Tree to maintain its property.

# Rotations:
These help rebalance(not perfectly), the AVL tree.
Start from the changed node and go upwards and rotate wherever imbalance occurs.
May need to do more than one rotations.
I dont see a case where there are more than one violations be insertion of a single node. I mean once you treat that one violation, others above get treated too.
The case 2 of each rotation is a violation, so might have to recursively treat that down the tree.

### Application:
1. Sort
2. Abstract Data Type or an interface which specifies which all properties and methods a data structure that implements that interface should have.
![alt text](image.png)
### Problem:
storing heights of AVL subtrees and dynamically modigying them:
Solution: Start balancing from the parent of wherever removal/insertion of node takes place.


