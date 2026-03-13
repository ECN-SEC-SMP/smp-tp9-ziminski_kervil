#include <map>
#include <list>
#include <string>

#include <iostream>

using namespace std;

map<int, list<string>> ajoute_evenement(map<int, list<string>> events, int annee, string event){
    if(events.find(annee) == events.end()){
        //On crée une nouvelle liste 
        list<string> L; 
        L.push_back(event);
        events[annee] = L;
    }else{
        events[annee].push_back(event);
    }

    return events;
}

void affiche_events(map<int, list<string>> events){
    map<int, list<string>>::iterator it ; 

    for(it = events.begin(); it != events.end(); it++){
        // On itère sur les clés (année)
        cout << "--------------------------------" << endl;
        cout << it->first << endl; 
        cout << "--------------------------------" << endl;

        list<string>::iterator it2;
        for(it2 = it->second.begin(); it2!= it->second.end(); it2++){
            // On itère sur les valeurs (events)
            cout << *it2 << endl;
        }

    }
}


int main(void){

    map<int, list<string>> events; 

    //Jeux de tests
    events = ajoute_evenement(events, 2005, "ma naissance");
    events = ajoute_evenement(events, 2005, "ma naissance 2");
    events = ajoute_evenement(events, 2005, "ma naissance 3");
    events = ajoute_evenement(events, 1515, "marignant");


    affiche_events(events);
    return 0; 
}