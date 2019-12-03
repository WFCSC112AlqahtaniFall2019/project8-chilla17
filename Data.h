#ifndef PROJECT8_DATA_H
#define PROJECT8_DATA_H
#include <iostream>
using namespace std;


class Data {
public:
    // default constructor
    Data();

    // alternate constructor
    Data(string pN, int h, int w, double d, int b);

    friend ostream& operator<<(ostream &out, const Data& print);
    bool operator< (const Data& rhs) const;

protected:
    string playerName;
    int height;
    int weight;
    double dash;
    int bench;

};


#endif //PROJECT8_DATA_H
