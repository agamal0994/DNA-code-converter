#include "CodonsTable.h"
#include "codon.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>

using namespace std;
CodonsTable :: CodonsTable()
{
}
CodonsTable :: ~CodonsTable()
{
}
void CodonsTable::LoadCodonsFromFile()
{
    ifstream in;
    char a[4];
    char b;
    int i=0;
    in.open("RNA.txt");
    while(in>>a>>b)
    {
        strcpy(codons[i].value,a);
        codons[i].AminoAcid=b;
        i++;
    }
}
Codon& CodonsTable::getAminoAcid(char *value)
{
    char * a;
    a = new char[5];
    int count = 0 ;
    for (int j =0 ; j<=strlen(value) ; j++)
    {
        a[count]=value[j];
        count++;
        if(j%3==0 && j !=0)
        {
            for(int i = 0 ; i<64 ; i++)
            {
                if (strcmp(a,codons[i].value)==0)
                {
                    if (codons[i].AminoAcid=='+')
                    {
                        break;
                    }
                    cout<<"your Amino Acid:"<<codons[i].AminoAcid<<endl;
                }
            }
            a = new char[5];
            delete []a;
            count=0;
        }
    }
}
void  CodonsTable::setCodon(char * value , char AminoAcid, int index)
{
    if(index>=64||index<0)
    {
        cout<<"This Index Is Not Found! \n";
    }
    else
    {
        cout<<"This Is Index Was Like \n";
        cout<<"Value Of RNA : "<<codons[index].value<<endl<<"Value Of AminoAcid : "<<codons[index].AminoAcid<<endl;
        strcpy(codons[index].value,value);
        codons[index].AminoAcid=AminoAcid;
        cout<<"This Is Index Will Be Like \n";
        cout<<"Value Of RNA : "<<codons[index].value<<endl<<"Value Of AminoAcid : "<<codons[index].AminoAcid<<endl;
    }
}
istream&operator >> (istream &input,CodonsTable & ob)
{
    input>>ob;
    return input;
}
ostream&operator << (ostream &output,CodonsTable & ob)
{
    output<<ob.codons;
    return output;
}
