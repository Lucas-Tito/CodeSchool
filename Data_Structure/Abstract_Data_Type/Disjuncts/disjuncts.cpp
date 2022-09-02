#ifndef DISJUNCTS_HPP
#define DISJUNCTS_HPP

#include <bits/stdc++.h>
#include <vector>

using namespace std;
    
class Disjuncts{

    private:
      
    int n;
    
    vector<vector<int>> vec; //vector of vectores (what a crazy world)

    
    public:
    
    DISJUNCTS_HPP(int n){ 
        vector<int> v2 {0};
        
        for(int i=0; i<n; i++){
            v2.at(0) = i;
            vec.push_back(v2);
        }
    
    }

    void unite(int x, int y){
    
    /*    
    //TEST
    cout<<endl<<endl << "######OPERATION UNITE######" <<endl;

    cout<<endl<<endl << "PRINTING VECTOR X" <<endl;
    cout <<"{";
    for(int k=0; k<vec.at(x).size(); k++){
        cout<<vec.at(x).at(k) <<" ";
    }
    cout <<"} ";
    
    cout<<endl<<endl << "PRINTING VECTOR Y" <<endl;
    cout <<"{";
    for(int k=0; k<vec.at(y).size(); k++){
        cout<<vec.at(y).at(k) <<" ";
    }
    cout <<"} ";
    
    cout<<endl<<endl << "#############################" <<endl;
    */
    
    
    vector<int> aux;
    aux = vec.at(x);
    
    for(int i=0; i<vec.at(y).size(); i++)
        vec.at(x).push_back(vec.at(y).at(i));   //put vectorY elements on vectorX
    sort(vec.at(x).begin(), vec.at(x).end()); 
    
    for(int i =0; i<vec.size(); i++)
        if(vec.at(i) == aux)
            vec.at(i) = vec.at(x);  //swap vectors previously united with x for a copy of vectorX
      
     vec.at(y) = vec.at(x);
     
    }

    int same(int x, int y){

        int areEquals=1;
        
        /*
        //TESTE
        cout<<endl<<endl << "-------OPERATION SAME-------" <<endl;
            
        cout<<endl << "PRINTING GLOBAL VECTOR" <<endl;
        for(int i=0; i<vec.size(); i++){
            cout <<"{";
            for(int k=0; k<vec.at(i).size(); k++){
                cout<<vec.at(i).at(k) <<" ";
            }
            cout <<"} ";
        }
           
        cout<<endl<<endl << "PRINTING VECTOR X" <<endl;
        cout <<"{";
        for(int k=0; k<vec.at(x).size(); k++){
            cout<<vec.at(x).at(k) <<" ";
        }
        cout <<"} ";
            
            
        cout<<endl<<endl << "PRINTING VECTOR Y" <<endl;
        cout <<"{";
        for(int k=0; k<vec.at(y).size(); k++){
            cout<<vec.at(y).at(k) <<" ";
        }
        cout <<"} ";
        
        cout<<endl<<endl << "----------------------------" <<endl;
        */
        
        
        if(vec.at(x).size() == vec.at(y).size()){
            
            for(int i=0; i<vec.at(x).size(); i++)
                if(vec.at(x).at(i) != vec.at(y).at(i)){
                    areEquals=0;
                    break;
                }
                    
        }
        else
            areEquals=0;   
        
           
    
        return areEquals;
    }
};


#endif
