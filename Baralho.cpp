#include "Carta.cpp"



class Baralho {

private:
  int cartaTopo;
  Carta cartas[52];
public:
  Baralho();
  Carta tiraCarta();
  bool vazio();
  void embaralha();
  void embaralha(int qtd);
  void imprime();
  void desalocaBMP();
  int qtdCartas();

};

Baralho::Baralho() {
  //Cartas de Ouro
  cartas[0] = Carta(2,   'O');
  cartas[1] = Carta(3,   'O');
  cartas[2] = Carta(4,   'O');
  cartas[3] = Carta(5,   'O');
  cartas[4] = Carta(6,   'O');
  cartas[5] = Carta(7,   'O');
  cartas[6] = Carta(8,   'O');
  cartas[7] = Carta(9,   'O');
  cartas[8] = Carta(10,  'O');
  cartas[9] = Carta(11,  'O');
  cartas[10] = Carta(12, 'O');
  cartas[11] = Carta(13, 'O');
  cartas[12] = Carta(14, 'O');
  //Cartas de Copas
  cartas[13] = Carta(2,  'C');
  cartas[14] = Carta(3,  'C');
  cartas[15] = Carta(4,  'C');
  cartas[16] = Carta(5,  'C');
  cartas[17] = Carta(6,  'C');
  cartas[18] = Carta(7,  'C');
  cartas[19] = Carta(8,  'C');
  cartas[20] = Carta(9,  'C');
  cartas[21] = Carta(10, 'C');
  cartas[22] = Carta(11, 'C');
  cartas[23] = Carta(12, 'C');
  cartas[24] = Carta(13, 'C');
  cartas[25] = Carta(14, 'C');
  //Cartas de Espadas
  cartas[26] = Carta(2,  'E');
  cartas[27] = Carta(3,  'E');
  cartas[28] = Carta(4,  'E');
  cartas[29] = Carta(5,  'E');
  cartas[30] = Carta(6,  'E');
  cartas[31] = Carta(7,  'E');
  cartas[32] = Carta(8,  'E');
  cartas[33] = Carta(9,  'E');
  cartas[34] = Carta(10, 'E');
  cartas[35] = Carta(11, 'E');
  cartas[36] = Carta(12, 'E');
  cartas[37] = Carta(13, 'E');
  cartas[38] = Carta(14, 'E');
  //Cartas de Paus
  cartas[39] = Carta(2,  'P');
  cartas[40] = Carta(3,  'P');
  cartas[41] = Carta(4,  'P');
  cartas[42] = Carta(5,  'P');
  cartas[43] = Carta(6,  'P');
  cartas[44] = Carta(7,  'P');
  cartas[45] = Carta(8,  'P');
  cartas[46] = Carta(9,  'P');
  cartas[47] = Carta(10, 'P');
  cartas[48] = Carta(11, 'P');
  cartas[49] = Carta(12, 'P');
  cartas[50] = Carta(13, 'P');
  cartas[51] = Carta(14, 'P');

  cartaTopo = 51;
}

Carta Baralho::tiraCarta() {
  if(!this->vazio()) {
    cartaTopo--;
    return cartas[cartaTopo+1];
  } else
    return Carta(0, '0');
}

bool Baralho::vazio() {
  if(cartaTopo < 0)
    return true;
  else
    return false;
}

void Baralho::embaralha() {
  Carta cartasEmbaralhadas[52];
  bool copiadas[52]; // 0 a carta não foi copiada // 1 a carta já foi copiada do baralho principal para o baralho embaralhamento;
  int contador = 51; // conta as cartas que ja foram copiadas
  int numRand;

  for(int i = 0; i < 52; i++)
    copiadas[i] = false;//inicia todas as cartas como não copiadas

  while(contador > -1) { //enquanto ainda tiver carta no baralho original

    numRand = rand() % 52; //sorteia numero
    while(copiadas[numRand] == true)// enquanto o numero sorteado representar uma carta do baralho original que ja foi copiada para o baralho temporario, refaz o sorteio
      numRand = rand() % 52; //sorteia

    cartasEmbaralhadas[contador] = cartas[numRand];//o baralho temporario recebe a carta sorteada
    copiadas[numRand] = true;//marca a carta sorteada do vetor original como copiada
    contador--;//diminui o tamanho do baralho
  }
  //saiu do while pois todas as cartas do baralho original foram copiadas para o baralho temporário.

  for(int i = 0; i < 52; i++)//agora copia todas as cartas do baralho temporario para o baralho original
    cartas[i] = cartasEmbaralhadas[i];
}

void Baralho::embaralha(int qtd) {
  for(int i = 0; i < qtd; i++)
    embaralha();
}

void Baralho::imprime() {
  for(int i = 0; i <= cartaTopo; i++) {
    if(i % 13 == 0)
      cout << endl;
    cartas[i].imprime();
  }
  cout << endl << endl;
}

void Baralho::desalocaBMP() {
  for(int i = 0; i < 52; i++)
    cartas[i].destroyBMP();
}

int Baralho::qtdCartas() {
  return cartaTopo;
}
