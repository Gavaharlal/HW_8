

#include "Pig.h"

int Pig::getFat() {
    return mFat;
}

void Pig::eat() {
    if (mHunger >= mDeltaEating) {
        mHunger -= mDeltaEating;
        cout << "Oink-oink. That was tasty!" << endl;
    } else {
        mFat += mDeltaEating;
        cout << "Getting fatter! Oink!" << endl;
    }
}
