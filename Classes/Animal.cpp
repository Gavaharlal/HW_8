

#include "Animal.h"

Animal::Animal(string mVoice) : mVoice(std::move(mVoice)) {}

int Animal::getHunger() const {
    return mHunger;
}

void Animal::getVoice() const {
    cout << mVoice << endl;
}