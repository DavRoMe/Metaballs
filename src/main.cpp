#include <cstdio>
#include <SFML/Graphics.hpp>

#include <physical.h>
#include <vec2op.h>

#include "blobs.h"
#include "pxl_handln.h"

const int WIDTH = 640;
const int HEIGHT = 360;
const int BLOBS = 8;

/*********************************************************************************/
/*********************************************************************************/

int main() {
  sf::RenderWindow wndw(sf::VideoMode(WIDTH, HEIGHT), "Metaballs");
  sf::Texture textura;
  sf::Uint8* arrPixel;
  arrPixel = new sf::Uint8[WIDTH * HEIGHT * 4];
  std::list <Blob*> blb;
  std::list <Blob*>::iterator iBlob;
  uint8_t ciclo;
  float fase;

  if(!textura.create(WIDTH, HEIGHT)) return -1;
  sf::Sprite sprt(textura);
  srand((unsigned int)time(NULL));

  uint8_t totalBlob = 0;
  for(int i = 0; i < BLOBS; i++) {
        sf::Vector2f pos((float)IntRandom(10, WIDTH - 10), (float)IntRandom(10, HEIGHT - 10));
    blb.push_back(new Blob(pos, WIDTH, HEIGHT));
    totalBlob++;
  }

  while(wndw.isOpen()) {
    sf::Event evnt;
    while(wndw.pollEvent(evnt)) {
      if(evnt.type == sf::Event::Closed) {
        wndw.close();
      }
    }

    SenoidalPxl(arrPixel, WIDTH, HEIGHT, blb, fase);
    ciclo++;
    if(ciclo == 3) {
      fase += 0.1;
      ciclo = 0;
    }

    textura.update(arrPixel);
    wndw.clear(sf::Color::Black);
    wndw.draw(sprt);
    for(iBlob = blb.begin(); iBlob != blb.end(); iBlob++) {
      (*iBlob)->Update();
    }
    wndw.display();
  }
  return 0;
}
