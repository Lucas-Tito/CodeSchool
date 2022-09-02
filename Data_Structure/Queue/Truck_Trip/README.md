<p align="center">
  <img src="https://www.mercedes-benz-trucks.com/content/dam/mbo/markets/hq_HQ/model-navigation-images/proven/modelthumb-actros-fv-proven.png" alt="header" width="50%" height="50%"/>
</p>


<h1 align="center">Description</h1>


The idea for the program consists in:
+ A gas station is a place to refuel vehicle.
+ Which gas station has a limited amount of fuel.
+ The gas stations are scattered in some places of a circular list  with size N with indexes of 0 to N - 1.
<br>  
You have two informations of which gas station: <br>
- the amount of fuel <br>
- the distance to the next gas station.
<br><br>
Initialy, the truck starts with a empty gas tank with unlimited capacity. <br>
- You can start the trip in any gas station. <br>
- Compute the first gas station where the truck can complete the trip. <br>
- Consider that the truck will stop in every gas station. <br>
- The truck will do one kilometer per fuel liter.


<br> <br>
## Input
The first line will contain the value of N.
The next N lines will contain a pair of integer numbers, that is, the amount of fuel that the gas station will have and the distance to the next gas station.

ex: <br>
3 <br>
1 5 <br>
10 3 <br>
3 4 <br>

## Output
The program prints a integer number that will be the smaller index of the starting gas station to complete the circle.
