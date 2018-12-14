#ifndef DNA_H
#define DNA_H
#include "Protein.h"
#include "DNA.h"
#include "RNA.h"
#include "Sequence.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>


using namespace std;
class RNA;
enum DNA_Type {promoter=1 , motif , tail , noncoding};

class DNA  : public Sequence
{
private:
    DNA_Type type;
    DNA * complementary_strand;
    int startIndex;
    int endIndex;
public:
        class err{};
        class def{};

    DNA();
    DNA(char * a ,DNA_Type atype);
    DNA(DNA& rhs);
    ~DNA();
    void Print();
    RNA ConvertToRNA();
    void BuildComplementaryStrand(int startIndex , int endIndex);
    friend istream&operator >> (istream &input,DNA & ob);
    friend ostream&operator << (ostream &output,DNA & ob);
    bool operator == (DNA otherDNA);
    bool operator != (DNA otherDNA);
    DNA  operator +(DNA otherDna);
};
#endif
