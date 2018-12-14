#ifndef RNA_H
#define RNA_H
#include "Protein.h"
#include "DNA.h"
#include "RNA.h"
#include "Sequence.h"
#include "CodonsTable.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>

using namespace std;
class Protein;
class DNA;
class CodonsTable;
enum RNA_Type {mRNA=1, pre_mRNA, mRNA_exon, mRNA_intron};
class RNA  : public Sequence
{
public:
    class err1{};
    class err3{};
    RNA();
    RNA(char * a, RNA_Type atype);
    RNA(RNA& rhs);
    ~RNA();
    void Print();
    Protein& ConvertToProtein(const CodonsTable &table);
    DNA& ConvertToDNA();
    friend istream&operator >> (istream &input,RNA & ob);
    friend ostream&operator << (ostream &output,RNA & ob);
    bool operator == (RNA otherRNA);
    bool operator != (RNA otherRNA);
    RNA operator +(RNA otherRna);
private:
    RNA_Type type;
};

#endif // RNA_H
