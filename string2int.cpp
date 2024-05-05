/** Fonction qui convertit une chaine de caracteres en un entier lorsque cela est possible
 * @param s une chaine de caracteres
 * @return s convertie en entier si elle n'est composee que de chiffres, et -1 sinon
**/
int string2int(string s){
  int res = 0;
  int puissance = 1;

  for(size_t i = 1; i <= s.size(); i+= 1){
    if(s.at(s.size()-i) < '0' or s.at(s.size()-i) > '9'){
      return -1;
    }

    res += (s.at(s.size()-i)-'0')*puissance;
    puissance *= 10;
  }

  return res;
}
