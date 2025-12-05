Input Output Instructions and Example test case for Problems 1 , 2 , 3 :




Initialize the tree by inserting n elements from the array given in the second line
(in order). Duplicates must not be inserted (see messages below). After
initialization, the program reads queries until EOF.
Query types:
• 1 — search query
• 2 — insert query
• 3 — delete query
• 4 — print level-order
Input format
• First line will contain n, which indicates the number of elements to be
inserted into the tree.
• Second line will contain n one-space-separated integers, which are your
tree elements. Assume this to be an array of n integers, inserted in order
to build the initial tree (ignore duplicates).
• Queries: Each subsequent line is either:
– Two integers: <type> <value> for types 1 (search), 2 (insert), 3
(delete), or
– One integer: 4 to print the tree level-by-level.
Output messages (uniform across Problems 1–3):
• Search: ‘<x> present’’ or ‘<x> not present’’.
• Insert: if duplicate ‘<x> already present. So no need to insert.’’;
else ‘<x> inserted’’.
• Delete: if present ‘<x> deleted’’; else ‘<x> not present. So it
can not be deleted’’.
• Level-order print (type 4): Each level on a new line, nodes left-to-right,
single spaces between nodes.
Example:
Input and Output:
17
9 8 5 4 99 78 31 34 89 90 21 23 45 77 88 112 32
1 56
56 not present
2 21
21 already present. So no need to insert.
2 56
56 inserted
2 90
90 already present. So no need to insert.
3 51
51 not present. So it can not be deleted
1 32
32 present
3 32
32 deleted
4
Level-order (one line per level). Example format:
<level 0 nodes>
<level 1 nodes>
<level 2 nodes>
Note:- Code should run in infinite loop expecting the query. Type EXIT in console to exit the infinite loop.





Problem 1: 

To run the program , use the following command.
g++ problem1.cpp -o problem1 && ./problem1
Example input and output:
17
9 8 5 4 99 78 31 34 89 90 21 23 45 77 88 112 32
1 56
56 not present
2 21
21 already present. So no need to insert.
2 56
56 inserted
2 90
90 already present. So no need to insert.
3 51
51 not present. So it can not be deleted
1 32
32 present
3 32
32 deleted
4
31
8 78
5 21 45 90
4 9 23 34 77 89 99
56 88 112
EXIT




Problem 2:

To run the program , use the following command.
g++ problem2.cpp -o problem2 && ./problem2

Example input and output :
17
9 8 5 4 99 78 31 34 89 90 21 23 45 77 88 112 32
1 56
56 not present
2 21
21 already present. So no need to insert.
2 56
56 inserted
2 90
90 already present. So no need to insert.
3 51
51 not present. So it can not be deleted
1 32
32 present
3 32
32 deleted
4
31
8 45 78 90
4 5 9 21 23 34 56 77 88 89 99 112
EXIT



Problem 3:

To run the program , use the following command.
g++ problem3.cpp -o problem3 && ./problem3

Example input and output :
17
9 8 5 4 99 78 31 34 89 90 21 23 45 77 88 112 32
1 56
56 not present
2 21
21 already present. So no need to insert.
2 56
56 inserted
2 90
90 already present. So no need to insert.
3 51
51 not present. So it can not be deleted
1 32
32 present
3 32
32 deleted
4
8 34 89
4 5 9 21 23 31 45 56 77 78 88 90 99 112
EXIT



Problem 4:

To run the program , use the following command
g++ problem4.cpp -o problem4 && ./problem4

Example input:

7
I 10
I 20
I 30
I 25
I 28
D 10
D 25
Example output:
Inorder: 20 28 30
Single rotations: 2
Double rotations: 1



Problem 5:
To run the program , use the following command
g++ problem5.cpp -o problem5 && ./problem5



