#include <fstream>

#include "FileFilter.h"
#include "CopyFileFilter.h"
#include "EncryptFileFilter.h"


int main()
{
    std::ifstream copyInStream;
    std::ofstream copyOutStream;

    //Copy the file
    copyInStream.open("file1.txt");
    copyOutStream.open("copyFileOut.txt");
    CopyFileFilter *copyFilter = new CopyFileFilter();
    copyFilter->doFilter(copyInStream, copyOutStream);
    copyInStream.close();
    copyOutStream.close();
    delete copyFilter;

    //encrypt the file
    copyInStream.open("file1.txt");
    copyOutStream.open("encryptFileOut.txt");
    EncryptFileFilter *encryptFilter = new EncryptFileFilter(2);
    encryptFilter->doFilter(copyInStream, copyOutStream);
    copyInStream.close();
    copyOutStream.close();
    delete encryptFilter;


    return 0;
}