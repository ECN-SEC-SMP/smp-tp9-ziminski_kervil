#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Affiche le contenu du vecteur passé en référence constante
void affiche(const std::vector<std::string>& v) {
    for (const std::string& s : v)
        std::cout << s << " ";
    std::cout << std::endl;
}

// Concatène tous les éléments du vecteur en une seule string séparés par des espaces
std::string concatene(const std::vector<std::string>& v) {
    std::string result;
    for (size_t i = 0; i < v.size(); i++) {
        result += v[i];
        if (i + 1 < v.size())
            result += " ";
    }
    return result;
}

// Foncteur qui ajoute une virgule derrière chaque mot
struct AjouteVirgule {
    void operator()(std::string& s) {
        s += ",";
    }
};

// Ajoute une virgule derrière chaque mot du vecteur via for_each
void ajoute_virgule(std::vector<std::string>& v) {
    std::for_each(v.begin(), v.end(), AjouteVirgule());
}

int main(void) {

    // 1. Déclaration du vecteur de strings
    std::vector<std::string> v;

    // 2. Ajout de cinq strings
    v.push_back("Bonjour");
    v.push_back("comment");
    v.push_back("allez");
    v.push_back("vous");
    v.push_back(" ?");

    // 3. Taille du vecteur
    std::cout << "Taille    : " << v.size() << std::endl;

    // 4. Capacité du vecteur
    std::cout << "Capacité  : " << v.capacity() << std::endl;
    std::cout << "(La taille est le nombre d'éléments présents, la capacité est la mémoire" << std::endl;
    std::cout << " réservée. La capacité >= taille et double généralement par palliers.)" << std::endl;

    // Ajout d'éléments pour observer les différences taille/capacité
    v.push_back("extra1");
    std::cout << "Après push_back -> taille : " << v.size() << ", capacité : " << v.capacity() << std::endl;
    v.push_back("extra2");
    std::cout << "Après push_back -> taille : " << v.size() << ", capacité : " << v.capacity() << std::endl;
    // On retire les éléments ajoutés pour la suite
    v.pop_back();
    v.pop_back();

    // 5. Affichage sur une ligne avec les trois méthodes
    std::cout << "\nAffichage par indices         : ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    std::cout << "Affichage par range-based loop: ";
    for (const std::string& s : v)
        std::cout << s << " ";
    std::cout << std::endl;

    std::cout << "Affichage par itérateur       : ";
    for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    // 6. Échange entre l'indice 1 et l'indice 3 avec swap
    std::cout << "\nAvant swap(1,3) : ";
    affiche(v);
    std::swap(v[1], v[3]);
    std::cout << "Après swap(1,3) : ";
    affiche(v);

    // 7. Insertion de "a tous" après le premier élément (position 1)
    v.insert(v.begin() + 1, "a tous");
    std::cout << "\nAprès insert \"a tous\" en pos 1 : ";
    affiche(v);

    // 8. Remplacement du point d'interrogation final par " ???"
    v.back() = " ???";
    std::cout << "Après remplacement du '?' : ";
    affiche(v);

    // 9. Affichage séparé par des virgules
    std::cout << "\nContenu séparé par virgules : ";
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i];
        if (i + 1 < v.size()) std::cout << ", ";
    }
    std::cout << std::endl;

    // 10. Tri alphabétique avec std::sort
    std::sort(v.begin(), v.end());
    std::cout << "\nAprès tri alphabétique : ";
    affiche(v);

    // 11. Utilisation de la fonction affiche
    std::cout << "\nVia la fonction affiche() : ";
    affiche(v);

    // 12. Utilisation de la fonction concatene
    std::cout << "Concaténation : \"" << concatene(v) << "\"" << std::endl;

    // 13. Ajout de virgules via ajoute_virgule (for_each + foncteur)
    ajoute_virgule(v);
    std::cout << "\nAprès ajoute_virgule : ";
    affiche(v);

    return 0;
}
