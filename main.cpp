#include <utility>
#include <iostream>

//
#include "Classes/Animal.h"
#include "Classes/Man.h"
#include "Classes/Unit.h"
#include "Classes/Pig.h"
#include "Classes/Bear.h"
#include "Classes/ManBearPig.h"


typedef int *(*function)(char const *);

function *ComplexFunction(int, int *f(double));

template<typename A, typename B>
bool compare(A const &first, A const &second, B (A::*func)() const) {
    return (first.*func)() < (second.*func)();
}

template<typename T>
bool isEqualObjects(const T *const first, const T *const second) {
    return dynamic_cast<const void *>(first) == dynamic_cast<const void *>(second);
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

using std::string;
using std::cout;
using std::cin;
using std::endl;

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
    cout << mbp.getName() << endl;
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
