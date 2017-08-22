#include "pxl_handln.h"

using namespace std;

int getDistance(int i, int j, int x, int y) {
  /// Regresa la distancia entre dos puntos
  int a, b;

  if(i > x) a = i - x;
  else      a = x - i;

  if(j > y) b = j - y;
  else      b = y - j;

  return sqrt(a * a + b * b);
}

float inverseRelation(float dis, float rad) {
  if(dis == 0) dis = 0.1;   //Evita division entre cero

  return (100 * rad / dis); //Relacion inversa con la distancia y multiplicada por escalar
}

float calculaCos(float pos, float longitud, float fase, float amplitud_inf, float aplitud_sup) {
  const float PI = 3.141592;
  float amplitud = (aplitud_sup - amplitud_inf) / 2;

  if(amplitud < 0) amplitud *= -1;
  if(aplitud_sup == -amplitud_inf)
    return (amplitud * cos((2 * PI * pos / longitud) - fase));
  else {
    return (amplitud * cos((2 * PI * pos / longitud) - fase) + amplitud_inf + amplitud);
  }

}

void Grayscale(sf::Uint8* pxArray, int width, int height, std::list <Blob*> blob) {
  std::list <Blob*>::iterator iBlob;

  for(int i = 0; i < width; i ++) {
    for(int j = 0; j < height; j ++) {
      float sum = 0, dist;
      for(iBlob = blob.begin(); iBlob != blob.end(); iBlob++) {
        if(sum < 255) {
          dist = getDistance(i, j, (*iBlob)->GetXpos(), (*iBlob)->GetYpos());
          sum += inverseRelation(dist, (*iBlob)->GetRadius());
        }
        if(sum > 255) {
          sum = 255;
          break;
        }
      }
      pxArray[(j * width + i) * 4] = uint8_t(sum);
      pxArray[(j * width + i) * 4 + 1] = uint8_t(sum);
      pxArray[(j * width + i) * 4 + 2] = uint8_t(sum);
      pxArray[(j * width + i) * 4 + 3] = 255;
    }
  }
}

void SenoidalPxl(sf::Uint8* pxArray, int width, int height, std::list <Blob*> blob, float fase) {
  std::list <Blob*>::iterator iBlob;

  for(int i = 0; i < width; i ++) {
    for(int j = 0; j < height; j ++) {
      float sum = 0, dist;
      for(iBlob = blob.begin(); iBlob != blob.end(); iBlob++) {
        if(sum < width / 2) {
          dist = getDistance(i, j, (*iBlob)->GetXpos(), (*iBlob)->GetYpos());
          sum += inverseRelation(dist, (*iBlob)->GetRadius());
        }
        if(sum >= width / 2) {
          sum = width / 2;
          break;
        }
      }
      pxArray[(j * width + i) * 4] = (uint8_t)calculaCos(sum, width / 2, 0, 0, 255);
      pxArray[(j * width + i) * 4 + 1] = (uint8_t)calculaCos(sum, width / 2, fase * 0.9, 0, 255);
      pxArray[(j * width + i) * 4 + 2] = (uint8_t)calculaCos(sum, width / 2, fase, 0, 255);
      pxArray[(j * width + i) * 4 + 3] = 255;
    }
  }
}
