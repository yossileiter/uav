#include "Lexer.hpp"
using namespace std;


void Lexer::ReadInstructions(string FilePath)
{
    fstream newfile;
    newfile.open(FilePath,ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()) //checking whether the file is open
    { 
        string line;
        while(getline(newfile, line)) //read data from file object and put it into string.
        {   
            AllLines.push_back(line);
        }
        cout<<"newAllLines.size() after ReadInstructions() is: "<<AllLines.size()<<endl;
        newfile.close(); //close the file object.
    }
}

void Lexer::SplitLine(string s)
    {	
        string temp = "";
        for(int i=0 ;i<s.length(); ++i)
        {
            if(s[i]==' ')
            {
                v.push_back(temp);
                temp = "";
            }
            else { temp.push_back(s[i]); }		
        }
        v.push_back(temp);	
    };


void Lexer::PrintVector(vector<string> v)
    {
        for(int i=0;i<v.size();++i)
            cout<<"line "<<i<<": "<<v[i]<<endl;
        cout<<"\n";
    }

