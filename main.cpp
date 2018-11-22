#include <utility>
#include <iostream>
#include <string>

typedef int *(*function)(char const *);

function *ComplexFunction(int, int *f(double));

template<typename A, typename B>
bool compare(A const &first, A const &second, B (A::*func)() const) {
    return (first.*func)() < (second.*func)();
}

template<typename T>
bool isEqualObjects(const T * const first, const T * const second)
{
    return dynamic_cast<const void*>(first) == dynamic_cast<const void*>(second);
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Unit {
public:
    int getHealthPoints() const {
        return mHealthPoints;
    }

    int getManaPoints() const {
        return mManaPoints;
    }

    Unit(int mHealthPoints, int mManaPoints) :
            mHealthPoints(mHealthPoints), mManaPoints(mManaPoints) {};

    Unit() {
        mManaPoints = 100;
        mHealthPoints = 100;
    }

protected:
    int mHealthPoints;
    int mManaPoints;
};

class Man : public Unit {
public:
    explicit Man(string mName) : Unit(), mName(std::move(mName)) {}

    Man(int mHealthPoints, int mManaPoints, string mName) :
            Unit(mHealthPoints, mManaPoints), mName(std::move(mName)) {}

    const string &getName() const {
        return mName;
    }

private:
    string mName;
};

class Animal {
public:

    Animal() = delete;

    explicit Animal(string mVoice) : mVoice(std::move(mVoice)) {}

    int getHunger() const {
        return mHunger;
    }

    void getVoice() const {
        cout << mVoice << endl;
    }

    virtual void eat() = 0;

protected:
    int mHunger = 45;
    string mVoice;
    int mDeltaEating = 15;
};

class Bear : public virtual Animal {
public:

    Bear() : Animal("AAarrghhh!!1!") {}

    void showTeeth() {
        cout << "______" << endl;
        cout << R"(\/\/\/)" << endl;
        cout << R"(/\/\/\)" << endl;
        cout << "------" << endl;
    }

    void eat() override {
        if (mHunger >= mDeltaEating) {
            mHunger -= mDeltaEating;
            cout << "That was tasty!" << endl;
        } else {
            cout << "I'm full!" << endl;
        }
    }
};

class Pig : public virtual Animal {
public:

    Pig() : Animal("Oink-oink!!!") {}

    void eat() override {
        if (mHunger >= mDeltaEating) {
            mHunger -= mDeltaEating;
            cout << "Oink-oink. That was tasty!" << endl;
        } else {
            mFat += mDeltaEating;
            cout << "Getting fatter! Oink!" << endl;
        }
    }

    int getFat() {
        return mFat;
    }

protected:
    int mFat = 0;
};

class ManBearPig : public Man, public Bear, public Pig {
public:

    explicit ManBearPig(const string &mName) : Man(mName), Animal("I'm a monster!") {
        mHunger = 0;
    }

    void scare() {
        cout << "Booo!" << endl;
    }

    void eat() final {
        cout << "I can live without eating" << endl;
    }
};

void testUnit();

void testMan();

void testBear();

void testPig();

void testMBP();

void testCompare();

int main() {
    std::cout << "Hello, World!" << std::endl;
    testUnit();
    testMan();
    testBear();
    testPig();
    testMBP();
    testCompare();
    return 0;
}

void testUnit() {
    cout << "_________________________TESTING UNIT_________________________" << endl;
    cout << "________Default constructor________" << endl;
    Unit unit;
    cout << unit.getHealthPoints() << endl;
    cout << unit.getManaPoints() << endl;
    cout << "________NONDefault constructor________" << endl;
    unit = Unit(2, 1);
    cout << unit.getHealthPoints() << endl;
    cout << unit.getManaPoints() << endl;
    cout << endl << endl;
}

void testMan() {
    cout << "_________________________TESTING MAN_________________________" << endl;
    cout << "________Name constructor________" << endl;
    Man man("Tray Parker");
    cout << man.getManaPoints() << endl;
    cout << man.getHealthPoints() << endl;
    cout << man.getName() << endl;
    cout << "________Full constructor________" << endl;
    man = Man(0, -2, "Tray Parker");
    cout << man.getManaPoints() << endl;
    cout << man.getHealthPoints() << endl;
    cout << man.getName() << endl;
    cout << endl << endl;
}

void testBear() {
    cout << "_________________________TESTING BEAR_________________________" << endl;
    Bear bear;
    for (int i = 0; i < 4; ++i) {
        cout << "Current hunger: " << bear.getHunger() << endl;
        bear.eat();
        cout << endl;
    }
    bear.showTeeth();
    bear.getVoice();
    cout << endl << endl;

}

void testPig() {
    cout << "_________________________TESTING PIG_________________________" << endl;
    Pig pig;
    for (int i = 0; i < 6; ++i) {
        cout << "Current hunger: " << pig.getHunger() << endl;
        cout << "Current fat: " << pig.getFat() << endl;
        pig.eat();
        cout << endl;
    }
    pig.getVoice();
    cout << endl << endl;
}

void testMBP() {
    cout << "_________________________TESTING ManBearPig_________________________" << endl;
    ManBearPig mbp("El Gor");

    for (int i = 0; i < 6; ++i) {
        cout << "Current hunger: " << mbp.getHunger() << endl;
        cout << "Current fat: " << mbp.getFat() << endl;
        mbp.eat();
        cout << endl;
    }
    mbp.getVoice();
    mbp.showTeeth();
    mbp.scare();
    mbp.getName();
    cout << mbp.getHealthPoints() << endl;
    cout << mbp.getManaPoints() << endl;
    cout << endl << endl;

}

void testCompare() {
    cout << "_________________________TESTING COMPARE_________________________" << endl;
    string s1("Elf");
    string s2("Archer");

    cout << compare(s1, s2, &std::string::size) << endl;
    cout << compare(s1, s1, &std::string::size) << endl;
    cout << endl << endl;
}

#pragma clang diagnostic pop
