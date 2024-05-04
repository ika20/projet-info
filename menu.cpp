void menu() {
  bool jouer;
  string joue;
  cout << "BIENVENUE SUR LE JEU 2048 !" << endl;
  cout << "Entrez 'j' pour jouer ";
  cin >> joue;
  cout << endl;
  jouer = joue=="j";
  Grille g;
  string mode;

  if(jouer){
    cout << endl;
    cout << "--------------------------------------------MODES-------------------------------------------" << endl;
    cout << "| - c : mode classique : grille 4x4, score                                                  |" << endl;
    cout << "|        > grille 4x4                                                                       |" << endl;
    cout << "|        > score a atteindre : 2048                                                         |" << endl;
    cout << "|        > probabilite d'avoir un 2 pour une nouvelle tuile : 9/10                          |" << endl;
    cout << "|                                                                                           |" << endl;
    cout << "| - p : mode personnalise :                                                                 |" << endl;
    cout << "|        > grille de dimension au choix entre 4x4 et 10x10                                  |" << endl;
    cout << "|        > score a atteindre : personnalise                                                 |" << endl;
    cout << "|        > probabilite d'avoir un 2 pour une nouvelle tuille : au choix entre 0 et 10       |" << endl;
    cout << "|                                                                                           |" << endl;
    cout << "| - r : mode aleatoire                                                                      |" << endl;
    cout << "|        > grille de dimension aleaatoire entre 4x4 et 10x10                                |" << endl;
    cout << "|        > score a atteindre : aleatoire entre 128 et 2048                                  |" << endl;
    cout << "|        > probabilite d'avoir un 2 pour une nouvelle tuille : au choix entre 0 et 10       |" << endl;
    cout << "|                                                                                           |" << endl;
    cout << "| - g : mode creation de grille                                                             |" << endl;
    cout << "--------------------------------------------------------------------------------------------" << endl << endl;
    cout << "Choissez un mode de jeu : ";
    cin >> mode;
    cout << "----Creation de la partie----" << endl;
    if(mode == "c"){
      init(g, 4, 2048, 9);
    }
    else if(mode == "p"){
      int dimension;
      int cible;
      int proportion;
      cout << "Saisissez les informations suivantes :" << endl;
      cout << "> dimension de la grille : ";
      cin >> dimension;
      if(dimension < 4 or dimension > 10){
        do{
          cout << "Erreur : la dimension de la grille doit etre comprise entre 4 et 10. Saisissez a nouveau une dimension : ";
          cin >> dimension;
        }while(dimension < 4 or dimension > 10);
      }
      cout << "> score cible : ";
      cin >> cible;
      cout << "> proportion de 2 pour les nouvelles tuiles : ";
      cin >> proportion;
      cout << "-------------------------------" << endl;
      init(g, dimension, cible, proportion);
    }
    else if(mode == "r"){
      int dimension = rand() %7 + 4;
      int cible = rand() %1921 + 128;
      int proportion = rand() %11;
      init(g, dimension, cible, proportion);
    }
    else if(mode == "g"){
      int dimension;
      cout << "> saisisez la dimension de la grille a creer (entre 4 et 10): ";
      cin >> dimension;
      if(dimension < 4 or dimension > 10){
        do{
          cout << "Erreur : la dimension doit etre comprise entre 4 et 10. Saisisez a nouveau une dimension : ";
          cin >> dimension;
        }while(dimension < 4 or dimension > 10);
      }
      cout << endl;
      vector<int> ligne(dimension);
      vector<vector<int>> v;
      for(int d=0; d<dimension; d+=1){
        v.push_back(ligne);
      }

      int valeur;
      for(int i=0; i<dimension; i+= 1){
        for(int j=0; j<dimension; j+=1){
          cout << "> saisissez la valeur de la tuile a la " << i+1 << "e ligne et la " << j+1 << "e colonne (0 pour une case vide) : ";
          cin >> valeur;
          bool p2 = true;
          do{
            int puissance = 2;  
            while(puissance < valeur){
              puissance = puissance*2;
            }
            if(valeur != 0 and puissance != valeur){
              p2 = false;
              cout << "Erreur : les valeurs saisies doivent etre des puissances de 2. Saisissez a nouveau une valeur : ";
              cin >> valeur;
            }
            else if(valeur == 0 or puissance == valeur){
              p2 = true;
            }
          }while(not p2);
          v.at(i).at(j) = valeur;
        }
      }
      int cible;
      cout << endl << "> saisisez le score cible pour cette partie : ";
      cin >> cible;
      int proportion;
      cout << "> saisisez la proportion de 2 : ";
      cin >> proportion;
      charge(g, v, cible, proportion);
    }

    cout << "Grille de depart :";
    affiche(g);
    cout << endl;
    cout << "------COMMANDES------" << endl;
    cout << "| - i : haut         |" << endl;
    cout << "| - j : gauche       |" << endl;
    cout << "| - k : bas          |" << endl;
    cout << "| - l : droite       |" << endl;
    cout << "| - a : abandonner   |" << endl;
    cout << "---------------------" << endl << endl << endl;
    
    do{
    cout << "Entrez une commande : ";
    char action;
    cin >> action;
    switch(action){
      case 'i': haut(g); affiche(g); break;
      case 'j': gauche(g); affiche(g); break;
      case 'k': bas(g); affiche(g); break;
      case 'l': droite(g); affiche(g); break;
      case 'a': jouer=false; break;
      default : cerr << "Veuillez entrer une commande valide" << endl;
    }
    
  }while(jouer); // + que la grille n'est pas bloquée + que le score n'est pas atteint
  }

  
  

}
