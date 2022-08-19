#ifndef DISJUNTOS_HPP
#define DISJUNTOS_HPP

#include <bits/stdc++.h>
#include <vector>

using namespace std;
    
class Disjuntos{

    private:
      
    int n;
    
    vector<vector<int>> vec; //vetor de vetores (que loucura)

    
    public:
    
    Disjuntos(int n){ 
        vector<int> v2 {0};
        
        for(int i=0; i<n; i++){
            v2.at(0) = i;
            vec.push_back(v2);
        }
    
    }

    void une(int x, int y){
    
    /*    
    //TESTE
    cout<<endl<<endl << "######OPERAÇÃO DE UNIÃO######" <<endl;

    cout<<endl<<endl << "IMPRIMINDO VETOR X" <<endl;
    cout <<"{";
    for(int k=0; k<vec.at(x).size(); k++){
        cout<<vec.at(x).at(k) <<" ";
    }
    cout <<"} ";
    
    cout<<endl<<endl << "IMPRIMINDO VETOR Y" <<endl;
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
        vec.at(x).push_back(vec.at(y).at(i));   //coloca os elementos do vetor y no vetor x
    sort(vec.at(x).begin(), vec.at(x).end()); 
    
    for(int i =0; i<vec.size(); i++)
        if(vec.at(i) == aux)
            vec.at(i) = vec.at(x);  //troca os vetores anteriormente unidos com x por uma cópia do vetor x
      
     vec.at(y) = vec.at(x);
     
    }

    int mesmo(int x, int y){

        int areEquals=1;
        
        /*
        //TESTE
        cout<<endl<<endl << "-------OPERAÇÃO MESMO-------" <<endl;
            
        cout<<endl << "IMPRIMINDO VETOR GLOBAL" <<endl;
        for(int i=0; i<vec.size(); i++){
            cout <<"{";
            for(int k=0; k<vec.at(i).size(); k++){
                cout<<vec.at(i).at(k) <<" ";
            }
            cout <<"} ";
        }
           
        cout<<endl<<endl << "IMPRIMINDO VETOR X" <<endl;
        cout <<"{";
        for(int k=0; k<vec.at(x).size(); k++){
            cout<<vec.at(x).at(k) <<" ";
        }
        cout <<"} ";
            
            
        cout<<endl<<endl << "IMPRIMINDO VETOR Y" <<endl;
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
