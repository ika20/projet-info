void menu() {
  bool rejouer = true;
  bool jouer;
  string joue;
  string modecmd;
  bool ijkl;
  cout << endl;
  cout << "\t\t-----------------------------------------------" << endl;
  cout << "\t\t|        BIENVENUE SUR LE JEU 2048 !          |" << endl;
  cout << "\t\t-----------------------------------------------" << endl << endl << endl;
  cout << "Choisissez vos commandes. Entrez : " << endl;
  cout << "> z pour ZQSD" << endl;
  cout << "> i pour IJKL" << endl;
  cout << "--> ";
  cin >> modecmd;
  if(modecmd != "z" and modecmd != "i"){
    do{
      cout << "Erreur : veuillez saisir z ou i : ";
      cin >> modecmd;
    }while(modecmd != "z" and modecmd != "i");
  }
  if(modecmd == "z"){
    ijkl = false;
  }
  else if(modecmd == "i"){
    ijkl = true;
  }
  cout << endl;

  do{
    cout << ">> Entrez j pour jouer >> ";
    cin >> joue;
    cout << endl << endl;
    jouer = joue=="j";
    Grille g;
    string mode;

  
    if(jouer){
      // cout << endl;
      cout << "----------------------------------------------MODES--------------------------------------------" << endl;
      cout << "| - c : mode classique :                                                                       |" << endl;
      cout << "|        > grille 4x4                                                                          |" << endl;
      cout << "|        > valeur a atteindre : 2048                                                           |" << endl;
      cout << "|        > probabilite d'avoir un 2 pour une nouvelle tuile : 9/10                             |" << endl;
      cout << "|                                                                                              |" << endl;
      cout << "| - p : mode personnalise :                                                                    |" << endl;
      cout << "|        > grille de dimension au choix entre 4x4 et 10x10                                     |" << endl;
      cout << "|        > valeur a atteindre : personnalisee                                                  |" << endl;
      cout << "|        > probabilite d'avoir un 2 pour une nouvelle tuille : au choix entre 0/10 et 10/10    |" << endl;
      cout << "|                                                                                              |" << endl;
      cout << "| - r : mode aleatoire :                                                                       |" << endl;
      cout << "|        > grille de dimension aleaatoire entre 4x4 et 10x10                                   |" << endl;
      cout << "|        > score a atteindre : aleatoire entre 128 et 2048                                     |" << endl;
      cout << "|        > probabilite d'avoir un 2 pour une nouvelle tuille : aleatoire entre 0/10 et 10/10   |" << endl;
      cout << "|                                                                                              |" << endl;
      cout << "| - g : mode creation de grille                                                                |" << endl;
      cout << "-----------------------------------------------------------------------------------------------" << endl << endl;
      cout << "Choissez un mode de jeu : ";
      cin >> mode;
      if(mode != "c" and mode != "p" and mode != "r" and mode != "g"){
        do{
          cout << "Veuillez saisir un mode existant : ";
          cin >> mode;
        }while(mode != "c" and mode != "p" and mode != "r" and mode != "g");
      }
      cout << endl << "-------------Creation de la partie-------------" << endl;
      if(mode == "c"){
        init(g, 4, 2048, 9);
      }
      else if(mode == "p"){
        string dimension;
        string cible;
        string proportion;
        cout << "Saisissez les informations suivantes :" << endl;
        cout << "> dimension de la grille : ";
        cin >> dimension;
        if((string2int(dimension) == -1) or (string2int(dimension) < 4 or string2int(dimension) > 10)){
          do{
            cout << "Erreur : la dimension de la grille doit etre comprise entre 4 et 10. Saisissez a nouveau une dimension : ";
            cin >> dimension;
          }while((string2int(dimension) == -1) or (string2int(dimension) < 4 or string2int(dimension) > 10));
        }
        cout << "> valeur cible : ";
        cin >> cible;
        if(string2int(cible) == -1 or not(puissance2(string2int(cible)))){
          do{
            cout << "Erreur : la cible doit etre une puissance de 2 strictement superieure a 1. Saisissez a nouveau une cible : ";
            cin >> cible;
          }while(string2int(cible) == -1 or not(puissance2(string2int(cible))));
        }

        cout << "> proportion de 2 pour les nouvelles tuiles : ";
        cin >> proportion;
        if(string2int(proportion)==-1 or string2int(proportion) < 0 or string2int(proportion) > 10){
          do{
            cout << "Erreur : la proportion de 2 doit etre comprise entre 0 et 10. Saisissez a nouveau une proportion : ";
            cin >> proportion;
          }while(string2int(proportion)==-1 or string2int(proportion) < 0 or string2int(proportion) > 10);
        }
        init(g, string2int(dimension), string2int(cible), string2int(proportion));
      }
      else if(mode == "r"){
        int dimension = rand() %7 + 4;
        int cible = rand() %5;
        if(cible == 0){
          cible = 128;
        }
        else if(cible == 1){
          cible = 256;
        }
        else if(cible == 2){
          cible = 512;
        }
        else if(cible == 3){
          cible = 1024;
        }
        else if(cible == 4){
          cible = 2048;
        }
        int proportion = rand() %11;
        init(g, dimension, cible, proportion);
      }
      else if(mode == "g"){
        string dimension;
        cout << "> saisisez la dimension de la grille a creer (entre 4 et 10): ";
        cin >> dimension;
        if(string2int(dimension)==-1 or string2int(dimension) < 4 or string2int(dimension) > 10){
          do{
            cout << "Erreur : la dimension doit etre comprise entre 4 et 10. Saisisez a nouveau une dimension : ";
            cin >> dimension;
          }while(string2int(dimension)==-1 or string2int(dimension) < 4 or string2int(dimension) > 10);
        }
        cout << endl;
        vector<int> ligne(string2int(dimension));
        vector<vector<int>> v;
        for(int d=0; d<string2int(dimension); d+=1){
          v.push_back(ligne);
        }

        string valeur;
        for(int i=0; i<string2int(dimension); i+= 1){
          for(int j=0; j<string2int(dimension); j+=1){
            cout << "> saisissez la valeur de la tuile a la " << i+1 << "e ligne et la " << j+1 << "e colonne (0 pour une case vide) : ";
            cin >> valeur;
            bool p2;
            do{
              p2 = puissance2(string2int(valeur));
              if(string2int(valeur) != 0 and not(p2)){
                cout << "Erreur : les valeurs saisies doivent etre des puissances de 2. Saisissez a nouveau une valeur : ";
                cin >> valeur;
              }
              else if(string2int(valeur) == 0){
                p2 = true;
              }
            }while(not p2);
            v.at(i).at(j) = string2int(valeur);
          }
        }
        string cible;
        cout << endl << "> saisisez le score cible pour cette partie : ";
        cin >> cible;
        if(not(puissance2(string2int(cible)))){
          do{
            cout << "Erreur : la cible doit etre une puissance de 2 strictement superieure a 1. Saisissez a nouveau une cible : ";
            cin >> cible;
          }while(not(puissance2(string2int(cible))));
        }
        string proportion;
        cout << "> saisisez la proportion de 2 : ";
        cin >> proportion;
        if(string2int(proportion) == -1 or string2int(proportion) < 0 or string2int(proportion) > 10){
          do{
            cout << "Erreur : la proportion de 2 doit etre comprise entre 0 et 10. Saisissez a nouveau une proportion : ";
            cin >> proportion;
          }while(string2int(proportion) == -1 or string2int(proportion) < 0 or string2int(proportion) > 10);
        }
  
        charge(g, v, string2int(cible), string2int(proportion));
      }
      cout << "-----------------------------------------------" << endl << endl;

      cout << "\t===== Grille de depart =====";
      affiche(g);
      cout << "> Valeur cible : " << g.cible << endl << endl;
      cout << endl;
      if(ijkl){
        cout << "------COMMANDES------" << endl;
        cout << "| - i : haut         |" << endl;
        cout << "| - j : gauche       |" << endl;
        cout << "| - k : bas          |" << endl;
        cout << "| - l : droite       |" << endl;
        cout << "| - a : abandonner   |" << endl;
        cout << "---------------------" << endl;
      }
      else{
        cout << "------COMMANDES------" << endl;
        cout << "| - z : haut         |" << endl;
        cout << "| - q : gauche       |" << endl;
        cout << "| - s : bas          |" << endl;
        cout << "| - d : droite       |" << endl;
        cout << "| - a : abandonner   |" << endl;
        cout << "---------------------" << endl;
      }

      
      do{
        cout << endl << endl << "Entrez une commande : ";
        char action;
        cin >> action;
        if(not(ijkl)){
          if(action == 'z'){
            action = 'i';
          }
          else if(action == 'q'){
            action = 'j';
          }
          else if(action == 's'){
            action = 'k';
          }
          else if(action == 'd'){
            action = 'l';
          }
        }
        cout << endl << endl;
        switch(action){
          case 'i': haut(g); affiche(g); break;
          case 'j': gauche(g); affiche(g); break;
          case 'k': bas(g); affiche(g); break;
          case 'l': droite(g); affiche(g); break;
          case 'a': 
            jouer=false; 
            char rejoue;
            cout << "Voulez vous rejouer ? Entrez r pour rejouer ";
            cin >> rejoue;
            rejouer = rejoue=='r';
            break;
          default : cerr << "Veuillez entrer une commande valide" << endl;
        }

        Grille test;
        charge(test, g.table, g.cible, g.proportion);
        if(succes(g)){
          jouer = false;
          string rejoue;
          cout << endl << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl;
          cout << "\t\t BRAVO ! VOUS AVEZ ATTEINT " << g.cible << " !" << endl;
          cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl << endl;
          cout << "Voulez-vous rejouer ? Entrez r pour rejouer ";
          cin >> rejoue;
          rejouer = rejoue=="r";
        }
        else if(droite(test) == -1 and gauche(test)==-1 and haut(test)==-1 and bas(test)==-1){
          jouer = false;
          string rejoue;
          cout << "VOUS AVEZ PERDU !" << endl << endl;
          cout << "Voulez-vous rejouer ? Entrez r pour rejouer ";
          cin >> rejoue;
          rejouer = rejoue=="r";
        }
        cout << endl;
      }while(jouer); 
    }
  }while(rejouer);
  

}
