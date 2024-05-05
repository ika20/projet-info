/** Fonction qui teste si un nombre est une puissance de 2 strictement superieure a 1
 * @param n un entier
 * @return true si n est une puissance de 2 strictement superieure a 1, et false sinon
**/
bool puissance2(int n){
  int puissance = 2;  
  while(puissance < n){
    puissance = puissance*2;
  }

  return puissance == n;
}
