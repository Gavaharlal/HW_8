
#include "Unit.h"

Unit::Unit(int mHealthPoints, int mManaPoints) :
        mHealthPoints(mHealthPoints), mManaPoints(mManaPoints) {}

int Unit::getManaPoints() const {
    return mManaPoints;
}

int Unit::getHealthPoints() const {
    return mHealthPoints;
}

Unit::Unit() {
    mManaPoints = 100;
    mHealthPoints = 100;
}
