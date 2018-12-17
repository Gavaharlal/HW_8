
#include "ManBearPig.h"

ManBearPig::ManBearPig(const string &mName) : Man(mName), Animal("I'm a monster!") {
    mHunger = 0;
}

void ManBearPig::scare() {
    cout << "Booo!" << endl;
}

void ManBearPig::eat() {
    cout << "I can live without eating" << endl;
}
