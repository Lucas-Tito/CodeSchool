#include<stdio.h>
#include<math.h>

typedef struct{
    float x, y, radius;
}Circle;


int distanceChecker(Circle c1, Circle c2){
    
    float result = sqrt( pow((c2.x-c1.x),2) + pow((c2.y-c1.y),2) );
    
    if(result<=c1.radius) return 1;
    else return 0;
    
}


int main(){
    
    Circle c;
    scanf("%f %f %f", &c.x, &c.y, &c.radius);
    
    Circle ToCheck;
    scanf("%f %f", &ToCheck.x, &ToCheck.y);
    
    int IsIn = distanceChecker(c, ToCheck);
    
    if(IsIn) printf("1");
    else printf("0");    
    
    return 0;
}

