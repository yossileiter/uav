#include "parser.cpp"

using namespace std;

int main()
{
    static Lexer *lexer = new Lexer;
    static Parser *parser = new Parser;
    lexer->ReadInstructions("FlightInstructions.txt");  
    // lexer->PrintVector(AllLines);
    for (int i = 0; i < AllLines.size(); i++)
    {
        lexer->SplitLine(AllLines[i]);
        AllLinesSeparated.push_back(v);
        parser->parse(v);
    }
    
    return 0;
}