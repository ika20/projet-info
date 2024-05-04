/** Fonction qui initialise une grille a partir d'un vecteur passe en parametres
 * @param g une grille
 * @param v vecteur a partir duquel la grille doit etre construite
 * @param cible le score a atteindre pour cette grille
 * @param proportion la proportion de tuiles 2 au tirage pour cette grille
 * @return true si l'initialisation a ete possible, false sinon
**/
bool charge(Grille &g, vector<vector<int>> &v, int cible, int proportion) {
  size_t dim = v.size(); 
  if (dim < 4) {
    cerr << "Erreur : nombre de lignes insuffisant: " << dim << endl;
    return false;
  }
  
  if(cible < 0){
    cerr << "Erreur : la cible doit etre un entier positif";
    return false;
  }

  if(proportion < 0 or proportion > 10){
    cerr << "Erreur : la proportion doit etre un entier compris entre 0 et 10";
    return false;
  }

  vector<int> tailles_lignes; // Verification que la grille fournie est bien carree
  for(size_t t = 0; t < v.size(); t += 1){
    tailles_lignes.push_back(v.at(t).size()); // On cree un vecteur avec les tailles de toutes les lignes
  }
  for(size_t i1 = 0; i1 < tailles_lignes.size(); i1 += 1){
    for(size_t i2 = i1+1; i2 < tailles_lignes.size(); i2 += 1){
      if(tailles_lignes.at(i1) != tailles_lignes.at(i2)){ // On verifie que tous les elements de tailles_lignes sont egaux, c'est-a-dire que toutes les lignes font la meme taille
        cerr << "Erreur : les lignes doivent toutes faire la meme taille, sinon ce n'est pas une grille carree." << endl;
        return false;
      }
    }
  }
  if(tailles_lignes.at(0) != v.size()){ // On verifie que le nombre de lignes est bien egal au nombre de colonnes
    cerr << "Erreur : la grille doit contenir autant de lignes que de colonnes pour avoir une grille carree. Or, ici il y a " << v.size() << " lignes et " << tailles_lignes.at(0) << " colonnes." << endl;
    return false;
  }

  for(size_t p1 = 0; p1 < v.size(); p1 += 1){ // Verification que la grille fournie ne contient que des puissances de 2
    for(size_t p2 = 0; p2 < v.size(); p2 += 1){
      if(v.at(p1).at(p2) != 0){
        int puissance = 1;  
        while(puissance < v.at(p1).at(p2)){
          puissance = puissance*2;
        }
        if(puissance != v.at(p1).at(p2) /*or v.at(p1).at(p2) < 0*/){  // On verifie que le nombre a la (p1+1)e ligne et la (p2+1)e colonne est bien une puissance de 2
          cerr << "Erreur : la grille ne doit contenir que des puissances de 2. Or, a la " << p1+1 <<"e ligne et " << p2+1 << "e colonne, il y a un " << v.at(p1).at(p2) << "." << endl;
          return false;
        }
      }
    }
  }

  g.cible = cible;
  g.proportion = proportion;
  g.score = 0;

  g.table.clear();  // On vide la grille au cas ou elle ait deja ete utilisee

  for(size_t i = 0; i < v.size(); i += 1){  // Remplissage de la grille a partir de v
    vector<int> ligne;
    for(size_t j = 0; j < v.at(i).size(); j += 1){
      ligne.push_back(v.at(i).at(j));   // On remplit une ligne avec la i-eme ligne de v
    }
    g.table.push_back(ligne);           // On ajoute cette ligne a notre grille
  }

  return true;
}
