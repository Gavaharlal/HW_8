
#ifndef HW_8_BEAR_H
#define HW_8_BEAR_H


#include "Animal.h"

class Bear : public virtual Animal {
public:

    Bear();

    void showTeeth();

    void eat() override;
};


#endif //HW_8_BEAR_H
