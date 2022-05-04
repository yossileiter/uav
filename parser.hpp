#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

vector<string> AllLines, v;
vector<vector<string>> AllLinesSeparated;

class Lexer
{
private:

public:
    Lexer(){}
    void ReadInstructions(string FilePath);
    void SplitLine(string s);
    void PrintVector(vector<string> v);
};


class Parser
{
public:
    void parse(vector<string> v);    
};



class Command
{
public:
	virtual void doCommand(vector<string> v) = 0;
};

class openServerCommand : public Command
{
public:
    void doCommand(vector<string> v) override;
};

class connectCommand : public Command
{
public:
    void doCommand(vector<string> v);
};