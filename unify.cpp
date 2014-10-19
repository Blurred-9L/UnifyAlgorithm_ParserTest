#include "Unifier.h"
#include "UnifyParser.h"
#include "UnifyAutomata.h"
#include "Tokenizer.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
    Unifier unifier;
    string input;
    bool goOn = true;
    
    unifier.parser().tokenizer().automata().loadMatrix("./Resources/matrix.csv");
    cout << boolalpha;
    cout << "Press EOF (Ctrl + D UNIX / Ctrl + Z Windows) to exit" << endl;
    while (goOn) {
        cout << "> ";
        getline(cin, input);
        if (cin.eof()) {
            goOn = false;
        } else {
            cout << unifier.unify(input) << endl;
        }
    }
    cout << endl;
    
    return 0;
}
