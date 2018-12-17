
#ifndef HW_8_PIG_H
#define HW_8_PIG_H

#include "Animal.h"

class Pig : public virtual Animal {
public:

    Pig() : Animal("Oink-oink!!!") {}

    void eat() override;

    int getFat();

protected:
    int mFat = 0;
};

#endif //HW_8_PIG_H
