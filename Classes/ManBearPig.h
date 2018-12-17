
#ifndef HW_8_MANBEARPIG_H
#define HW_8_MANBEARPIG_H


#include "Man.h"
#include "Bear.h"
#include "Pig.h"

class ManBearPig : public Man, public Bear, public Pig {
public:

    explicit ManBearPig(const string &mName);

    void scare();

    void eat() final;
};


#endif //HW_8_MANBEARPIG_H
