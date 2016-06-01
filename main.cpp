#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "Baralho.cpp"


using namespace std;

int main() {

  allegro_init();
  install_keyboard();

//Ajusta video para 16 bits de cores
  set_color_depth(32);

//Autodetecta a placa  de   video e usa resolucao de 640x480 em modo janela
  set_gfx_mode(GFX_AUTODETECT_WINDOWED,640,480,640,480);

  iniciaNaipes();
  srand(time(NULL));


  Baralho B;

  Carta C;

  do {
    textprintf_ex(screen, font, 150, 20, Cor::verde(), 0,"Aperte espaco para um novo sorteio de cartas");
    readkey();

    if(key[KEY_SPACE] && B.qtdCartas() >=4) {
      B = Baralho();
      B.embaralha(30);

      //cartas comunitarias
      C = B.tiraCarta();
      C.desenha(0, 100);
      C = B.tiraCarta();
      C.desenha(40, 100);
      C = B.tiraCarta();
      C.desenha(80, 100);
      /*
      C = B.tiraCarta();
      C.desenha(120, 100);
      C = B.tiraCarta();
      C.desenha(160, 100);
      */

      //1 carta da mão
      C = B.tiraCarta();
      C.desenha(40, 250);
      C = B.tiraCarta();
      C.desenha(80, 250);

      B.imprime();
      B.desalocaBMP();
    }

  } while( !key[KEY_ESC] && !B.vazio() );


  allegro_exit();
  return 0;
}
END_OF_MAIN();
