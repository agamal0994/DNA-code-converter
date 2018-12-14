#include "Protein.h"
#include "DNA.h"
#include "RNA.h"
#include "Sequence.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
string  t[] ={"promoter" , "motif" , "tail" ," noncoding"};
class RNA;


using namespace std;

DNA::DNA()
{
    seq=new char[50];
    type = tail;
}
DNA::DNA(char * a, DNA_Type atype)
{
    seq = new char [strlen(a)];
    strcpy(seq,a);
    type=atype;
if(strlen(seq)%3!=0){
        DNA::err S;
        throw S;
    }
}
DNA::DNA(DNA& rhs)
{
    seq=new char[strlen(rhs.seq)];
    strcpy(seq,rhs.seq);
}
DNA::~DNA()
{
    delete []seq;
}
void DNA:: Print()
{
    cout<<seq<<endl;
    cout<<t[type-1];
}
RNA DNA::ConvertToRNA()
{
    RNA a;
    a.seq=new char[strlen(seq)];
    strcpy(a.seq,seq);
    for(int i = 0 ; i < strlen(seq) ; i++)
    {
        if(a.seq[i]=='T')
        {
            a.seq[i]='U';
        }
    }
    return  a ;
}
void DNA :: BuildComplementaryStrand(int startIndex , int endIndex)
{
    for (int i = startIndex ; i<=endIndex ; i++ )
    {
        if (seq[i]== 'A')
        {
            seq[i]= 'T';
        }
        else  if (seq[i]== 'T')
        {
            seq[i]= 'A';
        }
        else   if (seq[i]== 'C')
        {
            seq[i]= 'G';
        }
        else if (seq[i]=='G')
        {
            seq[i]= 'C';
        }
    }
    for (int i = endIndex ; i >= startIndex ; i--)
        cout << seq[i];

}
istream&operator >> (istream &input,DNA & ob)
{
    input>>ob.seq;
    if(strlen(ob.seq)%3!=0){
            DNA::err S;
        throw S;
    }
    for(int i = 0; i< strlen(ob.seq); i++){
        if(ob.seq[i]!='A'&&ob.seq[i]!='C'&&ob.seq[i]!='G'&&ob.seq[i]!='T'){
              DNA::def a;
            throw a;
        }
    }
    int c=0;
    cout<<"1-promoter\n2-motif\n3-tail\n4-noncoding\n";
    input>>c;
    if(c==1)
        ob.type=promoter;
    if(c==2)
        ob.type=motif;
    if(c==3)
        ob.type==tail;
    if(c==4)
        ob.type==noncoding;
    return input;
}
ostream&operator << (ostream &output,DNA & ob)
{
    output<<ob.seq<<endl;
    output<<t[ob.type-1];
    return output;
}
bool DNA ::operator == (DNA otherDNA)
{
    if(strcmp(seq,otherDNA.seq)==0)
        return 1;
    else
        return 0;
}
bool DNA ::operator !=(DNA otherDNA)
{
    if(strcmp(seq,otherDNA.seq)!=0)
        return 0;
    else
        return 1;
}
DNA DNA :: operator +(DNA otherDna)
    {
        DNA dna3;
        strcpy(dna3.seq,seq);
        strcat(dna3.seq,otherDna.seq);
        return dna3;
    }
