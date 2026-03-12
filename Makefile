# Règle par défaut pour compiler l'exécutable
all: exercice1

# Commande de compilation directe
exercice1: exercice1.cpp
	g++ -Wall -Wextra -std=c++17 exercice1.cpp -o exercice1.out
exercice3: exercice3.cpp
	g++ -Wall -Wextra -std=c++17 exercice3.cpp -o exercice3.out

# Règle pour supprimer l'exécutable
clean:
	rm -f *.out