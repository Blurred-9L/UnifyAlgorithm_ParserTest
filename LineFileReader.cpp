#include "LineFileReader.h"
#include "Tokenizer.h"

#include <string>
using std::string;
using std::getline;

/**
 *  @details    Constructs a LineFileReader object an opens
 *              the associated file for reading. If the given
 *              filename is not valid, the file object remains
 *              closed.
 *
 *  @param[in]  filename        The filename of the file to open.
 */
LineFileReader::LineFileReader(const char * filename) :
    file(filename)
{
}

/**
 *  @details    Destroys the LineFileReader object.
 */
LineFileReader::~LineFileReader()
{
    close();
}

/**
 *  @details    Checks if another line can be read from the file
 *              that is currently opened by this object.
 *
 *  @return     A boolean value indicating if another line can be read.
 */
bool LineFileReader::hasNext() const
{
    return !file.eof();
}

/**
 *  @details    Gets the next line from the file and sets it for
 *              use by the given tokenizer.
 *
 *  @param[in/out]  tokenizer   The tokenizer requiring a new line.
 */
void LineFileReader::sendNextLine(Tokenizer & tokenizer)
{
    string nextLine = "";
    
    getline(file, nextLine);
    tokenizer.setLine(nextLine);
}

/**
 *  @details    Opens a new file to read. If another file had already
 *              been opened, then it is closed before opening the new
 *              one.
 *
 *  @return     A boolean value indicating if the file was properly
 *              opened.
 */
bool LineFileReader::open(const char * filename)
{
    close();
    file.open(filename);
    
    return file.is_open();
}

/**
 *  @details    Closes the associated file object.
 */
void LineFileReader::close()
{
    if (file.is_open()) {
        file.close();
    }
}
