
#ifndef HW_8_MAN_H
#define HW_8_MAN_H

#include <string>
#include "Unit.h"

using std::string;

class Man: public Unit{
public:
    explicit Man(string);

    Man(int, int, string);

    const string &getName() const;

private:
    string mName;
};


#endif //HW_8_MAN_H
