#ifndef LINE_FILE_READER_H
#define LINE_FILE_READER_H

#include <fstream>
using std::ifstream;

class Tokenizer;

/**
 *  @class  LineFileReader
 *
 *  @brief  Class used to pass lines from a file
 *          to a tokenizer object.
 */
class LineFileReader {
private:
    /// The file object
    ifstream file;
    
public:
    /// LineFileReader constructor.
    explicit LineFileReader(const char * filename);
    /// LineFileReader destructor.
    ~LineFileReader();
    /// Checks if there's another line to read.
    bool hasNext() const;
    /// Sends line to tokenizer.
    void sendNextLine(Tokenizer & tokenizer);
    /// Opens a file.
    bool open(const char * filename);
    /// Closes the file.
    void close();
};

#endif /// NOT LINE_FILE_READER_H
