#include<iostream>
#include<math.h>
using namespace std;

int main(){
    
    int nChurchs, donation;
    cin >> nChurchs;
    cin >> donation;
    
    
    float initialBalance = ((pow(2, nChurchs)-1) * donation)/pow(2, nChurchs);
    
    printf("%.2f", initialBalance);
    
    return 0;
}
