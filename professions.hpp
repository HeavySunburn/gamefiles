#ifndef professions_hpp
#define professions_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "loader.hpp"
using namespace std;

class berserker {
public:
void bersekering(characterload & statnums ) {
   statnums.charload_display();
   statnums.statnums[0] = statnums.statnums[0] + 2;
   }
};

class thief {
public:
void thiefing(characterload & statnums ) {
   statnums.charload_display();
   statnums.statnums[1] = statnums.statnums[1] + 2;
   }
};

class warrior {
public:
void warrioring(characterload & statnums ) {
   statnums.charload_display();
   statnums.statnums[2] = statnums.statnums[2] + 2;
   }
};

class mage {
public:
void maging(characterload & statnums ) {
   statnums.charload_display();
   statnums.statnums[3] = statnums.statnums[3] + 2;
   }
};


#endif
