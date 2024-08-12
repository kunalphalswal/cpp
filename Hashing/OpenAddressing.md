No chaining
Each index in the hash table only stores one item.
and we know that we don't fill the hash table in a particular sequence, we fill it in a non-sequential manner, so in case of a collision, we'll need another index to store the new item, which will be stored at a new index and that is not guaranteed to be near the original index. so the length of our hash table would be m >= n.
In chaining, it was m~O(n).