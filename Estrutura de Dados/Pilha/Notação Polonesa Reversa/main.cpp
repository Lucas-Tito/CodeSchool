#include <iostream>
#include <string>
#include <ctype.h>
#include <stack>
using namespace std;

string expr;    
int pos = 0;

/*
 * Esta função é responsável por separar os tokens
 * (token sendo um número ou uma operação)
 * ela sempre só retornará um destes tokens
 * para não retornar valores iguais, toda vez que chamada
 * acrescenta-se um count chamado de pos
*/
string get_token(){
    string token = "";
    
    //adiciona "$" em token para indicar o final
    if(pos == expr.size() ){
        token = "$";
        return token;
    }
    
    //pula os espaços
    while( expr[pos] == ' ') pos++;

    //se algum token for achado, este é adicionado na string de tokens
    if(expr[pos] == '+' || expr[pos] == '-' || expr[pos] == '/' || expr[pos] == '*'){
        token += expr[pos];
        pos++;
        return token;
    }
    //se for um dígito, todos os dígitos não separados por espaço são adicionados em token
    else if(isdigit(expr[pos]) ){
        while( isdigit(expr[pos]) ){
            token += expr[pos];
            pos++;
        }
        return token;
    }

    return token;
}


int main(){
    
    //preenche a string expr que contém os números e operações
    getline( cin, expr );
    stack <int> numbers;
    string token = get_token();
    
    
    /*
     * A cada vez que o while é percorrido, é chamada a função get_token
     * se um dígito for achado, este é adicionado em na pilha
     * Entretanto, caso o elemento achado seja um operando
     * é verificado se a flag que aponta se alguma operação foi feita
     * Caso tenha, é só realizar a operação com o elemento no topo da pilha e o que está guardado em "resultado"
     * Se não, é realizada a operação com os dois números no topo da pilha
    */
    int operando1, operando2, resultado=0, atLeastOneOPWasDone=0;
    while(token != "$"){
                
        if(token == "+"){

            operando1 = numbers.top();            
            if(!numbers.empty())
                numbers.pop();
            
            if(atLeastOneOPWasDone == 0){
                operando2 = numbers.top();            
                if(!numbers.empty())
                    numbers.pop();
                    resultado += operando1+operando2;
            }
            else
                resultado += operando1;
            
            atLeastOneOPWasDone=1;
        
        }
        else if(token == "-"){
            
            operando1 = numbers.top();            
            if(!numbers.empty())
                numbers.pop();
            
            if(atLeastOneOPWasDone == 0){
                operando2 = numbers.top();            
                if(!numbers.empty())
                    numbers.pop();
                    resultado += operando1-operando2;
            }
            else
                resultado -= operando1;
            
            atLeastOneOPWasDone=1;
            
        }
        else if(token == "*"){
        
            operando1 = numbers.top();            
            if(!numbers.empty())
                numbers.pop();
            
            if(atLeastOneOPWasDone == 0){
                operando2 = numbers.top();            
                if(!numbers.empty())
                    numbers.pop();
                    resultado += operando1*operando2;
            }
            else
                resultado *= operando1;
            
            atLeastOneOPWasDone=1;
        
        }
        else if(token == "/"){
            
            operando1 = numbers.top();            
            if(!numbers.empty())
                numbers.pop();
            
            if(atLeastOneOPWasDone == 0){
                operando2 = numbers.top();            
                if(!numbers.empty())
                    numbers.pop();
                    resultado += operando1/operando2;
            }
            else
                resultado /= operando1;
            
            atLeastOneOPWasDone=1;
        
        }
        else
            numbers.push( atoi(token.c_str() ) );   //atoi converte para int
        
           

        token = get_token();
        
    }
    
    
    cout << resultado << endl;
    
    return 0;

}
