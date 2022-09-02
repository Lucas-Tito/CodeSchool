<h1 align="center">Descrição</h1>

<p align="center">
Given a vector A of N integers. Compute the value of next_greater(X) defined as follows:

next_greater(i) : j is the smaller index j such that i < j < n and A[j] > A[i].

You need to comput the next_greater for each index o from the vectorA for 0 <= i < n. If the number does not exist, assign the value -1.

For example, consider the vector A = [3,7,1,7,8,4,5,2], we have the following values:
</p>

<br> <br>
## Input
The first line has a integer N representing the size of vector A. Each following N lines have a integer where the integer on the ith line denotes A[i].

ex: <br>
8 <br>
3 <br>
7 <br>
1 <br>
7 <br>
8 <br>
4 <br>
5 <br>
2 <br>

## Output
The program prints the N numbers separate by space (in a single line), where the ith integer denotes the next_greater(i).
