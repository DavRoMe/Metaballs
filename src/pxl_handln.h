#ifndef PXL_HANDLN_H_INCLUDED
#define PXL_HANDLN_H_INCLUDED

#include <list>
#include "blobs.h"

using namespace std;

int getDistance(int i, int j, int x, int y);
float inverseRelation(float dis, float rad);
float calculaCos(float pos, float longitud, float fase, float amplitud_inf, float aplitud_sup);
void Grayscale(sf::Uint8* pxArray, int width, int height, std::list <Blob*> blob);
void SenoidalPxl(sf::Uint8* pxArray, int width, int height, std::list <Blob*> blob, float fase);

#endif // PXL_HANDLN_H_INCLUDED
