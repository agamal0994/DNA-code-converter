#include<iostream>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include"CodonsTable.cpp"
#include"DNA.cpp"
#include"Sequence.cpp"
#include"RNA.cpp"
#include"Protein.cpp"
using namespace std;
int main()
{
    int UserChoice;
    while(true)
    {
        cout<<"\nwhat you are want to enter :\n 1-DNA \n 2-RNA \n 3-Protein \n 4-LCS \n 5-Get AminoAcid\n 6-Set Codon \nif you want to end the program enter 0\n";
        cin>>UserChoice;
        if(UserChoice==1)
        {
            try
            {
                cout<<"DNA sequence should be between this characters { A , T , C , G } and should to be capital and his size = 3 or 3 * i \"i = 1 ,2 ,3 ,.....\""<<endl;
                DNA d;
                cout<<"enter your sequence\n";
                cin >>d;
                int User_Choice;
                cout<<"what you want to do in your DNA sequence \n1-Convert To RNA\n2-Build Complementary Strand\n";
                cin>> User_Choice;
                if(User_Choice==1)
                {
                    RNA r;
                    r=d.ConvertToRNA();
                    cout<<"your RNA sequence = "<<r;
                }
                if(User_Choice==2)
                {
                    int start=0,End=0;
                    cout<<"enter your start and end index\nstart = \n";
                    cin>>start;
                    cout<<"end = \n";
                    cin>>End;
                    cout<<"your Complementary Strand = ";
                    d.BuildComplementaryStrand(start, End);
                }
            }
            catch(DNA::def a)
            {
                cout<<"you should enter A or C or G or T only !!"<<endl;
            }
            catch(DNA::err S)
            {
                cout<<"your size should be 3*i";
            }

        }
        if(UserChoice==2)
        {
            try{
            cout<<"RNA sequence should be between this characters { A , U , C , G } and should to be capital and his size = 3 or 3 * i \"i = 1 ,2 ,3 ,.....\""<<endl;
            RNA r;
            cout<<"enter your sequence\n";
            cin>>r;
            int User_Choice;
            cout<<"what you want to do in your RNA sequence \n1-Convert To DNA\n2-Convert To protein\n";
            cin>> User_Choice;
            if(User_Choice==1)
            {
                DNA d1;
                d1=r.ConvertToDNA();
                cout<<"your DNA sequence :";
                cout<<d1;
            }
            if(User_Choice==2)
            {
                Protein p;
                CodonsTable t;
                t.LoadCodonsFromFile();
                p=r.ConvertToProtein(t);
                cout<<"your protein sequence :";
                cout<<p;
            }
            }
            catch(RNA::err1 er1){
                cout<<"your size should be 3*i";
            }
            catch(RNA::err3 er3){

                  cout<<"you should enter A or C or G or U only !!"<<endl;
                  }

        }
        if(UserChoice==3)
        {
            cout<<"protein sequence should be between this characters { K , N , T , R , S , I , M , Q , H , P , L , E , D , A , G , V , Y , C , W , F }"<<endl;
            try{
            Protein p;
            cout<<"enter your sequence\n";
            cin>>p;
            int User_Choice;
            cout<<"what you want to do in your PROTEIN sequence \n1-Convert To DNA\N";
            cin>>User_Choice;
            if(User_Choice==1)
            {
                CodonsTable t;
                t.LoadCodonsFromFile();
                DNA d ;
                DNA d1;
                cout<<"enter your DNA sequence\n";
                cin>>d1;
                d = p.GetDNAStrandsEncodingMe(d1);
                cout<<d;
            }
            }
            catch(Protein::err2 er2)
            {
                cout<<"this protein is not found!!\n";
            }
        }

        if(UserChoice==4)
        {
             cout<<"you should enter DNA sequence and it should be between this characters { A , T , C , G } and should to be capital and his size = 3 or 3 * i \"i = 1 ,2 ,3 ,.....\""<<endl;
        try{
            DNA d1 , d2 , d3;
            cout<<"enter first sequence: ";
            cin>>d1;
            cout<<"enter second sequence: ";
            cin>>d2;
            LCS(d1,d2);
        }
        catch(DNA::def a)
            {
                cout<<"you should enter A or C or G or T only !!"<<endl;
            }
        catch(DNA::err S)
            {
                cout<<"your size should be 3*i";
            }
        }

        if(UserChoice==5)
        {
            CodonsTable c;
            char *value;
            value=new char[50];
            cout<<"enter your RNA: ";
            cin>>value;
            c.LoadCodonsFromFile();
            c.getAminoAcid(value);
            delete []value;
        }
        if(UserChoice==6)
        {
            CodonsTable c;
            char *value;
            value=new char[50];
            char  AminoAcid;
            int index=0;
            cout<<"enter your value : ";
            cin>>value;
            cout<<"\n enter your Amino Acid : ";
            cin>>AminoAcid;
            cout<<"\n enter your index : ";
            cin>>index;
            c.LoadCodonsFromFile();
            c.setCodon(value , AminoAcid ,index);
            delete []value;
        }
        if(UserChoice==0)
        {
            break;
        }
    }
    return 0;
}

