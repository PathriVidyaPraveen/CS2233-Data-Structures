Problem 1: Non-recursive Inorder, Preorder, Postorder Traversal
To run: Compile the C++ program and run the executable.
g++ problem1.cpp -o problem1 && ./problem1


Input: The first line will contain k, the number of test cases. The following k lines will contain arrays of integers, denoting the array representation of a tree.


Example:

Input:
2
1 2 3 4 5 6 7
1 2 3 4 5 NULL 6


Problem 2: Construct Tree from Inorder and Preorder Traversal
To run: Compile the C++ program and run the executable.
g++ problem2.cpp -o problem2 && ./problem2


Input: The first line contains k, the number of test cases. For each test case, the first line contains the inorder traversal, and the second line contains the preorder traversal.


Example:

Input:
3
4 2 5 1 6 3 7
1 2 4 5 3 6 7
4 2 5 1 3 6
1 2 4 5 3 6
4 2 6 1 3 5
1 2 4 5 3 6


Problem 3: Most Frequent Pair Distance in a Binary Tree
To run: Compile the C++ program and run the executable.
g++ problem3.cpp -o problem3 && ./problem3


Input: The first line contains an integer n, the number of nodes. The second line contains n space-separated integers for the Preorder traversal. The third line contains n space-separated integers for the Inorder traversal.



Example:

Input:
5
1 2 4 5 3
4 2 5 1 3


Problem 4: Longest Equal-Value Path in a Binary Tree
To run: Compile the C++ program and run the executable.
g++ problem4.cpp -o problem4 && ./problem4


Input: The first line contains an integer n, the number of nodes. The next line contains n integers representing the values of the nodes (1-indexed). The next n-1 lines each contain two integers u and v, representing an edge between the nodes.




Example 1:

Input:
6
5 5 5 5 1 5
1 2
1 3
2 4
3 5
3 6


Example 2:

Input:
5
2 2 2 3 2
1 2
1 3
2 4
2 5


Problem 5: K-th Node on the Path in a BST
To run: Compile the C++ program and run the executable.
g++ problem5.cpp -o problem5 && ./problem5


Input: The first line contains an integer n, the number of nodes. The next line contains n integers, which are the node values inserted in order into the BST. The third line contains an integer q, the number of queries. The following q lines each contain three integers: u, v, k.




Example 1:

Input:
7
4 2 6 1 3 5 7
2
1 7 3
3 5 2


Example 2:

Input:
5
10 5 15 3 7
3
3 15 4
7 5 2
10 7 4


Problem 6: Range Sum of BST
To run: Compile the C++ program and run the executable.
g++ problem6.cpp -o problem6 && ./problem6


Input: The first line contains the array representation of the BST. The second line contains two integers, low and high.


Example 1:

Input:
10 5 15 3 7 null 18
7 15


Example 2:

Input:
10 5 15 3 7 13 18 1 null 6
6 10
