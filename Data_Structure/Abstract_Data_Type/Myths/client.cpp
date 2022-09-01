#include <bits/stdc++.h>
#include "Lightnings.hpp"
using namespace std;


int main(){
    
    cout << "Enter how many lightnings will be tracked: ";
    int n;
    cin >> n;

    Lightnings R(500,500);

    cout << "Enter all the lightnings cordinates: ";
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        R.add(x,y);
    }

    cout << "Lightning struck in the same place?: "
    cout << R.same_place() << endl;

}
