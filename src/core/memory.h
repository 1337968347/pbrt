#include "pbrt.h"

class ReferenceCounted {
   private:
    /* data */
   public:
    int nReferences;
    ReferenceCounted() { nReferences = 0; };
};
