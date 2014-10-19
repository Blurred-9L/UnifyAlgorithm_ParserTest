#include "AbstractAutomata.h"

#include <fstream>
using std::ifstream;

AbstractAutomata::AbstractAutomata() :
    transitions(0), nStates_(0), nInputs_(0), nTerminalStates_(0)
{
}

AbstractAutomata::~AbstractAutomata()
{
    if (transitions != 0) {
        for (int i = 0; i < nInputs_; i++) {
            delete [] transitions[i];
        }
        delete [] transitions;
    }
}

bool AbstractAutomata::loadMatrix(const char * filename)
{
    ifstream matrixFile(filename);
    bool matrixLoaded = false;
    
    if (matrixFile.is_open()) {
        matrixFile >> nStates_ >> nInputs_;
        matrixFile >> nTerminalStates_;
        transitions = new int * [nStates_];
        for (int i = 0; i < nStates_; i++) {
            transitions[i] = new int [nInputs_];
            for (int j = 0; j < nInputs_; j++) {
                matrixFile >> transitions[i][j];
            }
        }
        matrixLoaded = true;
        matrixFile.close();
    }
    
    return matrixLoaded;
}

unsigned AbstractAutomata::nStates() const
{
    return nStates_;
}

unsigned AbstractAutomata::nInputs() const
{
    return nInputs_;
}

unsigned AbstractAutomata::nTerminalStates() const
{
    return nTerminalStates_;
}
