#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int main(void){
    vector<int> v; //Création d'un vecteur d'int

    v.resize(3); //On définit sa taille à 3.


    //On affecte des valeurs 3, 1, 4
    v[0] = 3; 
    v[1] = 1; 
    v[2] = 4; 

    /* --- Parcours des valeurs --- */

    cout << "Parcours par Indice :" << endl; 

    // 1. Parcours par indice

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;  
    }

    cout << "Range based loop : " << endl; 
    
    // Range based loop
    for(int i : v){
        cout << i << endl;  
    }

    cout << "A l'aide d'un intérateur : " << endl; 
    
    vector<int>::iterator it; 
    for(it = v.begin(); it != v.end(); it++){
        cout << *it << endl;
    }

    //Ajout d'un élément en fin de vecteur: 
    v.push_back(1);

    cout << "Taille du vecteur : " << v.size() << endl; 

    vector<int> v2;

    v2.assign(v.begin(), v.end());


    return 0; 
}