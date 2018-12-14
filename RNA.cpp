#include "Protein.h"
#include "DNA.h"
#include "RNA.h"
#include "Sequence.h"
#include "CodonsTable.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
string P[]={"mRNA", "pre_mRNA", "mRNA_exon", "mRNA_intron"};
RNA:: RNA()
{
    seq = new char;
    type=mRNA;
}
RNA::RNA(char * a , RNA_Type atype)
{
    seq = new char;
    strcpy(seq,a);
    type=atype;
        if(strlen(seq)%3!=0){
        RNA::err1 er1;
        throw er1;
    }
}
RNA::RNA(RNA& rhs)
{
    seq=new char;
    strcpy(seq,rhs.seq);
}
RNA::~RNA()
{
    delete []seq;
}
void RNA:: Print()
{
    cout<<seq<<endl;
}
DNA& RNA::ConvertToDNA()
{
    DNA a;
    a.seq=new char[strlen(seq)];
    strcpy(a.seq,seq);
    for(int i = 0 ; i < strlen(seq) ; i++)
    {
        if(a.seq[i]=='U')
        {
            a.seq[i]='T';
        }
    }
    return  a ;
}
Protein & RNA::ConvertToProtein(const CodonsTable &table)
{
    Protein pro;
    pro.seq=new char[strlen(seq)/3];
    char * a;
    string b;
    a = new char[strlen(seq)];
    int count = 0 ;
    for (int j = 0 ; j < strlen(seq) ; j++)
    {
        a[count]=seq[j];
        count++;
        if((j+1)%3==0&&j!=0)
        {
            for(int i = 0 ; i<64 ; i++)
            {
                if (strcmp(a,table.codons[i].value)==0)
                {
                    if (table.codons[i].AminoAcid=='+')
                    {
                        break;
                    }
                    b+=table.codons[i].AminoAcid;
                    delete[]a;
                    a = new char[5];
                    count=0;
                }
            }
        }
    }
    strcpy(pro.seq,b.c_str());
    return pro;
}
istream&operator >> (istream &input,RNA & ob)
{
    input>>ob.seq;
    int c=0;
        if(strlen(ob.seq)%3!=0){
        RNA::err1 er1;
        throw er1;
    }
        for(int i = 0; i< strlen(ob.seq); i++){
        if(ob.seq[i]!='A'&&ob.seq[i]!='C'&&ob.seq[i]!='G'&&ob.seq[i]!='U'){
              RNA::err3 er3;
            throw er3;
        }
    }
    cout<<"1-mRNA\n2-pre_mRNA\n3-mRNA_exon\n4-mRNA_intron";
    input>>c;
    if(c==1)
        ob.type=mRNA;
    if(c==2)
        ob.type=pre_mRNA;
    if(c==3)
        ob.type==mRNA_exon;
    if(c==4)
        ob.type==mRNA_intron;
    return input;
}
ostream&operator << (ostream &output,RNA & ob)
{
    output<<ob.seq<<endl;
    output<<P[ob.type-1];
    return output;
}
bool RNA ::operator == (RNA otherRNA)
{
    if(strcmp(seq,otherRNA.seq)==0)
        return 1;
    else
        return 0;
}
bool RNA ::operator !=(RNA otherRNA)
{
    if(strcmp(seq,otherRNA.seq)!=0)
        return 0;
    else
        return 1;
}
RNA RNA::operator +(RNA otherRna)
    {
        RNA Rna3;
        strcpy(Rna3.seq,seq);
        strcat(Rna3.seq,otherRna.seq);
        return Rna3;
    }
