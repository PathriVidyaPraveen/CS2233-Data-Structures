Problem 1: Odd Even Linked List

To run: Compile the C++ program and run the executable.
g++ problem1.cpp -o problem1 && ./problem1

Input: A sequence of comma-separated integers. The input ends with -1.

Example: 2, 1, 3, 5, 6, 4, 7, -1

Problem 2: Doubly Linked List with a single pointer

To run: Compile the C++ program and run the executable.
g++ problem2.cpp -o problem2 && ./problem2

Input: The first line contains k, the number of operations. The next k lines contain the operation number followed by necessary values (if any).

Operations:

1 x: Search for value x in the list.

2 x: Insert value x into the list.

3 x: Delete value x from the list.

4: Reverse the list.

Example:

Input:
9
2 10
2 20
4
1 20
1 30
2 40
3 30
3 40
4

Problem 3: Infix to Postfix Conversion

To run: Compile the C++ program and run the executable.
g++ problem3.cpp -o problem3 && ./problem3

Input: The first line contains k, the number of test cases. The next k lines each contain an infix expression string.

Example:

Input:
3
a*(b+c)-d
a+bc
a^bc+d

Problem 4: Perfect Hashing

To run: Compile the C++ program and run the executable. Makse sure that the CSV file of data is present with the name "dataset.csv" in the same directory as that of C++ file.
g++ problem4.cpp -o problem4 && ./problem4

Input: A single NHS number (integer) to search for.

Example 1:

Input:
5808001331

Example 2:

Input:
9999999999

Problem 5: Sort Stack using Recursion

To run: Compile the C++ program and run the executable.
g++ problem5.cpp -o problem5 && ./problem5

Input: The first line contains n, the number of elements. The second line contains n space-separated integers for the stack elements.

Example:

Input:
5
11 2 32 3 41

Problem 6: Stack with Middle Operations

To run: Compile the C++ program and run the executable.
g++ problem6.cpp -o problem6 && ./problem6

Input: The first line contains Q, the number of operations. The next Q lines each contain an operation number and a value if required.

Operations:

1 x: Push integer x onto the stack.

2: Pop the top element from the stack.

3: Find the middle element of the stack.

4: Delete the middle element from the stack.

Example 1:

Input:
8
1 1
1 2
1 3
1 4
3
4
3
2

Example 2:

Input:
3
2
2
3