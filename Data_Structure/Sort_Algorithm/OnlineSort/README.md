<h1>Descrição</h1>


A algorithm is online when it receives a data flow and needs to answer to events during the process without need to know future requests.

The program need to process two types of operations:
+ The operation of type 1 receives a new element.
+ The operation of type 2 requests the ith element in the vector populated so far.<br><br>

Note that the algorithm needs to answer the operations during the process.


<br> <br>
## Input
The first line contains a integer representing the amount of requisitions that your program needs to attend to. The next N lines contain a integer indicating the operation to be done. If Operation = 1, than the line will contain one more integer representing a item to be added to the vector. If Operation = 2, than the line will contain one more integer indicating the desired position in the sorted vector.

ex: <br>
10<br>
1 2<br>
1 4<br>
1 3<br>
2 0<br>
1 5<br>
2 1<br>
2 0<br>
1 1<br>
1 4<br>
2 3<br>

## Output
The program pints the results of operation of type 2.
