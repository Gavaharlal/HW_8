#include "Bear.h"

void Bear::showTeeth() {
    cout << "______" << endl;
    cout << R"(\/\/\/)" << endl;
    cout << R"(/\/\/\)" << endl;
    cout << "------" << endl;
}

void Bear::eat() {
    if (mHunger >= mDeltaEating) {
        mHunger -= mDeltaEating;
        cout << "That was tasty!" << endl;
    } else {
        cout << "I'm full!" << endl;
    }
}

Bear::Bear() : Animal("AAarrghhh!!1!") {}
