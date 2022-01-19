#ifndef person_h
#define person_h
#include <string>

using namespace std;

class Box {
   public:
      double length;   // Length of a box
      double breadth;  // Breadth of a box
      double height;   // Height of a box

      // Member functions declaration
      double getVolume(void);
};

#endif