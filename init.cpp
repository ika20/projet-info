/** Fonction qui initialise une grille passee par reference avec les parametres indiques et avec deux tuiles dont la valeur et la position sont generees aleatoirement
 * @param g une grille
 * @param dimension la dimension de la grille a initialiser
 * @param cible le score a atteindre pour cette grille
 * @param proportion la proportion de tuiles 2 au tirage pour cette grille
 * @return true si l'initialisation a ete possible, false sinon
*/
bool init(Grille &g, int dimension, int cible, int proportion) {
  if(cible < 0){
    cerr << "Erreur : la cible doit etre un entier positif" << endl;
    return false;
  }

  if(proportion < 0 or proportion > 10){
    cerr << "Erreur : la proportion doit etre un entier compris entre 0 et 10" << endl;
    return false;
  }

  if(dimension < 4){
    cerr << "Erreur : dimension insuffisente" << endl;
    return false;
  }

  g.table.clear(); // On vide la grille au cas ou elle ait deja ete utilisee

  g.cible = cible;
  g.proportion = proportion;
  g.score = 0;

  vector<int> ligne(dimension, 0);  // On cree une ligne de 0
  for(int i = 0; i < dimension; i += 1){
    g.table.push_back(ligne);       // On ajoute cette ligne autant de fois que necessaire pour que la grille ait la dimension choisie
  }
  
  int tuile1 = nouvelle(g);         // Creation de deux nouvelles tuiles avec une probabilite de proportion/10 que ce soit un 2
  int tuile2 = nouvelle(g);         // et une probabilite de (1 - proportion)/10 que ce soit un 4

  int place1 = place(g);            // Generation de la position des deux nouvelle tuiles
  int place2 = place(g);
  while(place1 == place2){          // Si la position de la deuxieme tuile est identique a celle de la premiere, on en genere
    place2 = place(g);              // une nouvelle jusqu'a ce qu'elles soient differentes
  }
  
  g.table.at((place1-1)/dimension).at((place1-1)%dimension) = tuile1; // Ajout de ces deux tuile a leur positions respectives generee precedemment
  g.table.at((place2-1)/dimension).at((place2-1)%dimension) = tuile2;

  return true;
}
