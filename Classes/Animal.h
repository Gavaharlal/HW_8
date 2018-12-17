


#ifndef HW_8_ANIMAL_H
#define HW_8_ANIMAL_H

#include <string>
#include <iostream>

using std::string;
using std::endl;
using std::cin;
using std::cout;

class Animal {
public:

    Animal() = delete;

    explicit Animal(string);

    int getHunger() const;

    void getVoice() const;

    virtual void eat() = 0;

protected:
    int mHunger = 45;
    string mVoice;
    int mDeltaEating = 15;
};


#endif //HW_8_ANIMAL_H
