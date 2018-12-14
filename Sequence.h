#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>

using namespace std;

class Sequence
{
public:
    char * seq;
    Sequence();
    Sequence(Sequence& rhs);
    virtual ~Sequence();
    virtual void Print()=0;
    friend void LCS(Sequence & s1, Sequence & s2);
    friend ostream&operator << (ostream &output, Sequence& ob);
};

#endif
