/** Fonction qui effectue le déplacement vers le haut de la grille
 * @param g une grille
 * @return le nombre de cases vides de la grille apres le deplacement si le deplacement a ete possible, et -1 sinon
**/
int haut(Grille &g){
  vector<vector<int>> grille_depart = g.table;

  for(size_t  i = 0; i < g.table.size(); i += 1){
    size_t k = 1;                               // Indice qui va parcourir chaque colonne de haut en bas
    int m = -1;                                 // Indice qui va servir a marquer la derniere case qui a ete fusionnee afin de ne pas la fusionner une deuxieme fois
    while(k <= g.table.size()-1){
      if(g.table.at(k).at(i) != 0){             // Si la case n'est pas vide, on regarde la valeur de celle en haut
        if(g.table.at(k-1).at(i) != 0){         // Si la case du dessus n'est pas vide et qu'elles ont la meme valeur, on les fusionne
          if(g.table.at(k-1).at(i) == g.table.at(k).at(i)){
            g.table.at(k-1).at(i) = g.table.at(k-1).at(i)*2;
            g.table.at(k).at(i) = 0;
            m = k-1;
            g.score += g.table.at(k-1).at(i);
          }
        }
        else if(g.table.at(k-1).at(i) == 0){    // Si la case en haut est vide, on cherche la case vide la plus loin
          int l = k-1;                          // au dessus et on echange notre case et cette case vide
          while(l >= 0 and g.table.at(l).at(i) == 0){
            l -= 1;
          }
          g.table.at(l+1).at(i) = g.table.at(k).at(i);
          g.table.at(k).at(i) = 0;

          if(l < 0){                            // Si on a deborde de la colonne, la case vide la plus eloignee au dessus 
            l += 1;                             // est la premiere case de la colonne
          }

          if(g.table.at(l).at(i) == g.table.at(l+1).at(i) and m != l){  // Si la case au dessus de notre case qui vient d'etre deplacee
            g.table.at(l).at(i) = g.table.at(l).at(i)*2;                // est egale a notre case et qu'elle n'a pas deja ete fusionnee, 
            g.table.at(l+1).at(i) = 0;                                  // on les fusionne
            m = l;
            g.score += g.table.at(l).at(i);
          }
        }
      }

      k += 1;  // On passe a la case suivante
    }
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
