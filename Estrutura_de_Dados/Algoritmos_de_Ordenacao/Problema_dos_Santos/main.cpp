#include<iostream>
#include<math.h>
using namespace std;

int main(){
    
    int nIgrejas, doacao;
    cin >> nIgrejas;
    cin >> doacao;
    
    
    float saldoInicial = ((pow(2, nIgrejas)-1) * doacao)/pow(2, nIgrejas);
    
    printf("%.2f", saldoInicial);
    
    return 0;
}
