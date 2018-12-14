#ifndef PROTEIN_H
#define PROTEIN_H
#include "Protein.h"
#include "DNA.h"
#include "RNA.h"
#include "Sequence.h"
#include <vector>
enum Protein_Type {Hormon=1, Enzyme, TF, Cellular_Function};

class DNA;
class Protein  : public Sequence
{
public:
    class err2{};
    Protein();
    Protein(char * p , Protein_Type atype);
    ~Protein();
    void Print();
    DNA & GetDNAStrandsEncodingMe(const DNA & bigDNA);
    friend istream&operator >> (istream &input,Protein & ob);
    friend ostream&operator << (ostream &output,Protein & ob);
    bool operator == (Protein otherProtein);
    bool operator != (Protein otherProtein);
    Protein operator +(Protein otherProtein);
private:
    Protein_Type type;
};

#endif
