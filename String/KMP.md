## Crux: Not to traverse some part of the string t again if the current substring is equal to some prefix.
Must watch video tutorial: https://www.youtube.com/watch?v=V5-7GzOfADQ

### How to know if current substring is a prefix?
LPS table:
Mentioning if a substring ending at a given string is equal to a prefix of the overall string. if yes, then what is the length of the prefix it's equal to.

### Algorithm
1. Traverse i through each character of the large string and keep incrementing pointer to the smaller string:j if the characters are matching.
2. In case there is a mismatch, we rollback j to lps[j] because the characters before lps[j] can act as prefix and have already been traversed in the main string, hence no need to backtrack i.
3. If j reaches m(size of pattern), we reset it back to lps[m-1], to traverse the whole pattern again. (not the whole pattern, because we only roll j back to lps[m-1], taking into account what prefix of the pattern we have already traversed in the main string.)

