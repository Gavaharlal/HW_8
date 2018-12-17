
#ifndef HW_8_UNIT_H
#define HW_8_UNIT_H


class Unit {
public:
    int getHealthPoints() const;

    int getManaPoints() const;

    Unit(int mHealthPoints, int mManaPoints);

    Unit();

protected:
    int mHealthPoints;
    int mManaPoints;
};


#endif //HW_8_UNIT_H
