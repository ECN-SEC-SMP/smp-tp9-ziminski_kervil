#include <list>
#include <iostream>

using namespace std;


int main(void){
    list<int> L; 

    //Création d'une liste random     
    for(int i = 0 ; i < 8; i++){
        L.push_back(rand()%256);
    }

    //Affichage
    list<int>::iterator it; 
    for(it = L.begin(); it != L.end() ; it ++){
        cout << *it << endl;
    }



    // On efface le troisième élément
    list<int>::iterator it1 = L.begin();
    advance(it1, 2);
    L.erase(it1);

    //affichage 
    list<int>::iterator it2; 
    for(it2 = L.begin(); it2 != L.end() ; it2 ++){
        cout << *it2 << endl;
    }




    return 0;
}