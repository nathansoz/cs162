#include <fstream>
#include <iostream>

#include "FileFilter.h"
#include "CopyFileFilter.h"
#include "EncryptFileFilter.h"
#include "UpcaseFileFilter.h"
#include "GroupEncryptFileFilter.h"


int main()
{
    std::ifstream copyInStream;
    std::ofstream copyOutStream;

    //test that we can open the file
    copyInStream.open("inFile.txt");
    if(!copyInStream.good())
    {
        std::cout << "File 'inFile.txt' cannot be found!" << std::endl;
    }
    else
    {
        copyInStream.close();
    }


    //Copy the file
    copyInStream.open("inFile.txt");
    copyOutStream.open("copyFileOut.txt");
    CopyFileFilter *copyFilter = new CopyFileFilter();
    copyFilter->doFilter(copyInStream, copyOutStream);
    copyInStream.close();
    copyOutStream.close();
    delete copyFilter;

    //encrypt the file
    copyInStream.open("inFile.txt");
    copyOutStream.open("encryptFileOut.txt");
    EncryptFileFilter *encryptFilter = new EncryptFileFilter(5);
    encryptFilter->doFilter(copyInStream, copyOutStream);
    copyInStream.close();
    copyOutStream.close();
    delete encryptFilter;

    //upcase the file
    copyInStream.open("inFile.txt");
    copyOutStream.open("upcaseFileOut.txt");
    UpcaseFileFilter *upcaseFilter = new UpcaseFileFilter();
    upcaseFilter->doFilter(copyInStream, copyOutStream);
    copyInStream.close();
    copyOutStream.close();
    delete upcaseFilter;

    //group encrypt
    copyInStream.open("inFile.txt");
    copyOutStream.open("groupEncryptFileOut.txt");
    GroupEncryptFileFilter *groupEncryptFilter = new GroupEncryptFileFilter(5);
    groupEncryptFilter->doFilter(copyInStream, copyOutStream);
    delete groupEncryptFilter;


    return 0;
}