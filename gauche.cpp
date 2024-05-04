/** Fonction qui effectue le déplacement vers la gauche de la grille
 * @param g une grille
 * @return le nombre de cases vides de la grille apres le deplacement si le deplacement a ete possible, et -1 sinon
**/
int gauche(Grille &g){
  vector<vector<int>> grille_depart = g.table;

  for(size_t i = 0; i < g.table.size(); i += 1){
    vector<int> ligne = g.table.at(i);        // Puisque le mouvement s'effectue horizontalement, on cree un vecteur pour la ligne courante afin de simplifier l'ecriture

    size_t k = 1;                             // Indice qui va parcourir la ligne de gauche a droite
    int m = -1;                               // Indice qui va servir a marquer la derniere case qui a ete fusionnee afin de ne pas la fusionner une deuxieme fois
    while(k <= ligne.size()-1){
      if(ligne.at(k) != 0){                   // Si la case n'est pas vide, on regarde la valeur de celle a sa gauche
        if(ligne.at(k-1) != 0){               // Si la case a sa gauche n'est pas vide et qu'elles ont la meme valeur, on les fusionne
          if(ligne.at(k-1) == ligne.at(k)){
            ligne.at(k-1) = ligne.at(k-1)*2;
            ligne.at(k) = 0;
            m = k-1;
            g.score += ligne.at(k-1);
          }
        }
        else if(ligne.at(k-1) == 0){        // Si la case a sa gauche est vide, on cherche la case vide la plus loin
          int l = k-1;                      // a sa gauche et on echange notre case et cette case vide
          while(l >= 0 and ligne.at(l) == 0){
            l -= 1;
          }

          ligne.at(l+1) = ligne.at(k);
          ligne.at(k) = 0;

          if(l < 0){                        // Si on a deborde de la ligne, la case vide la plus eloignee a gauche 
            l += 1;                         // est la premiere case de la ligne
          }

          if(ligne.at(l) == ligne.at(l+1) and l != m){  // Si la case a droite de notre case qui vient d'etre deplacee
            ligne.at(l) = ligne.at(l)*2;                // est egale a notre case et qu'elle n'a pas deja ete fusionnee, 
            ligne.at(l+1) = 0;                          // on les fusionne
            m = l;
            g.score += ligne.at(l);
          }
        }
      }

      k += 1; // On passe a la case suivante
    }

    g.table.at(i) = ligne;
  }

  bool egaux = true;
  for(size_t a = 0; a < g.table.size(); a += 1){          // On verifie si le mouvement a bien eu lieu ou non en regardant si la grille 
    for(size_t b = 0; b < g.table.at(a).size(); b += 1){  // apres le deplacement est la meme que la grille initiale
      if(grille_depart.at(a).at(b) != g.table.at(a).at(b)){
        egaux = false;
      }
    }
  }

  if(egaux){
    return -1;
  }

  if(vides(g) >= 1 and not(egaux)){   // Ajout d'une case de valeur et d'emplacement aleatoires
    int tuile = nouvelle(g);
    int plc = place(g);
    int x = 0;                        // Indices pour parcourir les cases de la grille
    int y = 0;
    int compteur = 0;

    if(g.table.at(y).at(x) == 0){
      compteur += 1;
    }

    while(compteur < plc){
      if(x == g.table.size()-1){      // On se deplace a la prochaine case, et si elle est vide on ajoute 1 au compteur
        x = 0;
        y += 1;
      }
      else{
        x += 1;
      }

      if(g.table.at(y).at(x) == 0){
        compteur += 1;
      }
    }

    g.table.at(y).at(x) = tuile;      // Lorsqu'on a atteint la case vide a la place desiree, on la remplace par sa nouvelle valeur
  }

  return vides(g); 
}
