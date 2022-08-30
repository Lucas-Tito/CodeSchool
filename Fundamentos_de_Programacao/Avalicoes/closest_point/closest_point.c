#include<stdio.h>
#include<math.h>
#include<limits.h>

typedef struct{
     float x, y; 
}Point;

float calc_distance(Point p1, Point p2){
    
    float result = sqrt( pow((p2.x-p1.x),2) + pow((p2.y-p1.y),2) );
    
    if(result<0) result *= -1; 
 
    return result;
    
}

Point ClosestPoint(Point ordinaryPoints[], int n, Point pointToVerify){
    
    Point closestOne;
    float closestDistance = INT_MAX;
    
    for(int i=0; i<n; i++){
        
        if(calc_distance(pointToVerify, ordinaryPoints[i]) < closestDistance){
          
          closestDistance = calc_distance(pointToVerify, ordinaryPoints[i]);
          closestOne = ordinaryPoints[i];
       
        } 
        
    }
   
    return closestOne;
}


int main(){
    
    printf("Enter how many points array will have:\n");
    int n;
    scanf("%d", &n);
    
    printf("\nEnter the %d points of array\n", n);
    Point ordinaryPoints[n];
    for(int i=0; i<n; i++) scanf("%f %f", &ordinaryPoints[i].x, &ordinaryPoints[i].y);
    
    printf("\nEnter pointA:\n");
    Point pointToVerify;
    scanf("%f %f", &pointToVerify.x, &pointToVerify.y);
    

    Point closest_point = ClosestPoint(ordinaryPoints, n, pointToVerify);
    printf("this is the closest point to pointA: %.2f %.2f", closest_point.x, closest_point.y);
    
    
    return 0;
}