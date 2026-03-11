#include <stdio.h>
#include <vector>

using namespace std;

int main(void){
    vector<int> v; //Création d'un vecteur d'int

    v.resize(3); //On définit sa taille à 3.


    //On affecte des valeurs 3, 1, 4
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);

    

    return 0; 
}