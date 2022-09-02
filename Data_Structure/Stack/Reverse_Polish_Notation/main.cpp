#include <iostream>
#include <string>
#include <ctype.h>
#include <stack>
using namespace std;

string expr;    
int pos = 0;

/*
 * This function sepates the tokens
 * (token is a number or an operation)
 * this function always return one of these tokens
 * to prevent returning duplicate values, when the function is called
 * pos is incremented
*/
string get_token(){
    string token = "";
    
    //adds "$" in token to indicate the end
    if(pos == expr.size() ){
        token = "$";
        return token;
    }
    
    //skips the spaces
    while( expr[pos] == ' ') pos++;

    //if the token is found, it's added in the tokens string
    if(expr[pos] == '+' || expr[pos] == '-' || expr[pos] == '/' || expr[pos] == '*'){
        token += expr[pos];
        pos++;
        return token;
    }
    //if it's a digit, all digits not separate by space are added in token
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
    
    //fills the string expr that contains the numbers and operations
    getline( cin, expr );
    stack <int> numbers;
    string token = get_token();
    
    
    /*
     * Each time the program goes through the while, the get_token function is called
     * if a digit is found, it's added to the stack
     * However, in case a operand is found
     * it's verified if a flag tells that a operation were done
     * In positive case, the program just need to do the operation with the element on top of the stack and the one stored at "result"
     * Else, the operation is done with the two numbers at the top of the stack
    */
    int perando1, operand2, result=0, atLeastOneOPWasDone=0;
    while(token != "$"){
                
        if(token == "+"){

            operand1 = numbers.top();            
            if(!numbers.empty())
                numbers.pop();
            
            if(atLeastOneOPWasDone == 0){
                operand2 = numbers.top();            
                if(!numbers.empty())
                    numbers.pop();
                    result += operand1+operand2;
            }
            else
                result += operand1;
            
            atLeastOneOPWasDone=1;
        
        }
        else if(token == "-"){
            
            operand1 = numbers.top();            
            if(!numbers.empty())
                numbers.pop();
            
            if(atLeastOneOPWasDone == 0){
                operand2 = numbers.top();            
                if(!numbers.empty())
                    numbers.pop();
                    result += operand1-operand2;
            }
            else
                result -= operand1;
            
            atLeastOneOPWasDone=1;
            
        }
        else if(token == "*"){
        
            operand1 = numbers.top();            
            if(!numbers.empty())
                numbers.pop();
            
            if(atLeastOneOPWasDone == 0){
                operand2 = numbers.top();            
                if(!numbers.empty())
                    numbers.pop();
                    result += operand1*operand2;
            }
            else
                result *= operand1;
            
            atLeastOneOPWasDone=1;
        
        }
        else if(token == "/"){
            
            operand1 = numbers.top();            
            if(!numbers.empty())
                numbers.pop();
            
            if(atLeastOneOPWasDone == 0){
                operand2 = numbers.top();            
                if(!numbers.empty())
                    numbers.pop();
                    result += operand1/operand2;
            }
            else
                result /= operand1;
            
            atLeastOneOPWasDone=1;
        
        }
        else
            numbers.push( atoi(token.c_str() ) );   //atoi converts to int        
           

        token = get_token();
        
    }
    
    
    cout << result << endl;
    
    return 0;

}
