#include <bits/stdc++.h>
#include "Disjuncts.hpp"
using namespace std;


int main(){
    
    Disjuncts D(5);

    cout << D.same(0,1) << endl; // 0
    cout << D.same(1,2) << endl; // 0
    cout << D.same(2,3) << endl; // 0
    cout << D.same(3,4) << endl; // 0
    cout << D.same(4,0) << endl; // 0
    
    
    D.unite(0,4);
    D.unite(0,1);

    cout << D.same(0,1) << endl; // 1
    cout << D.same(1,2) << endl; // 0
    cout << D.same(2,3) << endl; // 0
    cout << D.same(3,4) << endl; // 0
    cout << D.same(4,0) << endl; // 1

    D.unite(1,3);

    cout << D.same(0,1) << endl; // 1
    cout << D.same(1,2) << endl; // 0
    cout << D.same(2,3) << endl; // 0
    cout << D.same(3,4) << endl; // 1
    cout << D.same(4,0) << endl; // 1



}
