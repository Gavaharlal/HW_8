
#include "Man.h"
#include <utility>

Man::Man(int mHealthPoints, int mManaPoints, string mName) :
        Unit(mHealthPoints, mManaPoints), mName(std::move(mName)) {}

Man::Man(string name) : mName(std::move(name)) {}

const string &Man::getName() const {
    return mName;
}
