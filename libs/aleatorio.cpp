#include "aleatorio.h"

using namespace std;

int IntRandom(int inferior, int superior) {
  return (rand() % (superior + 1 - inferior) + inferior);
}
