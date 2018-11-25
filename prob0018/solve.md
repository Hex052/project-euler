#Usage

For problem 18, set ROWS to 15, and for problem 67, set to 100. Arguments are the input triangle file and output triangle file.
If no output file is given, no file is written.

#Methods

The path with the greatest sum can be calculated by starting from row 2 and
proceeding downwards, adding the greatest from the one above and the one above and to the left (ignore the other).

For example, with the triangle  
```
3  
7  4  
2  4  6  
8  5  9  3  
```
the operations would proceed as follows:
```
3
10 7
2  4  6
8  5  9  3

3
10 7
12 14 13
8  5  9  3

3
10 7
12 14 13
20 19 23 16
```
From there, the longest path is simply the largest number in the bottom row.
