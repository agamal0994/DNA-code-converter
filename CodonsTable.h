#ifndef CODONSTABLE_H
#define CODONSTABLE_H
#include "codon.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>

using namespace std;
class CodonsTable
{
public:
    CodonsTable();
    ~CodonsTable();
    void LoadCodonsFromFile();
    Codon& getAminoAcid(char * value);
    void setCodon(char * value , char AminoAcid, int index);
    friend istream&operator >> (istream &input,CodonsTable & ob);
    friend ostream&operator << (ostream &output,CodonsTable & ob);
    Codon codons[64];
private:

};
#endif
