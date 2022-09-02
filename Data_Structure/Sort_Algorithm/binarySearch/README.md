<p align="center">
  <img src="https://miro.medium.com/max/1400/1*uMpAuvIGRy9aTqREM3X-0w.jpeg" alt="header" width="50%" height="50%"/>
</p>


 <h1>Description</h1>

This code implements a algorithm called Binary Search, these are it's basics steps:

+ The elements need to be sorted.
+ Start with middle of array.
+ If the item is on the middle, the program return the that index of the array.
+ Else, in case the element in the middle is greate thant the item to find, the search interval changes to the lower half of the array.
+ If the value of middle element is smaller thant the item to find, the search interval change to the higher half of the array.


<br> <br>
## Input
In the first line, the number of element of the array and the number of elements to find will be provided. <br>
On the second one, is expected the elements of the array separated by space (in a single line).<br>
In the third one, the itens to find will be provided separate by space (in a single line).

ex: <br>
8 4<br>
2 3 4 8 10 45 54 72<br>
8 9 54 72<br>
1 3 2 5 4 <br>

## Output
The program prints the amount of interations that the algorithm needed to find each item.
