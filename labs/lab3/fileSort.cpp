#include <iostream>
#include <fstream>
#include "fstream"
#include <string>

const char* OUT_FILE_NAME = "outfile.txt";

int sortTwoFiles(std::string file1, std::string file2)
{
    std::ifstream fileStream1;
    std::ifstream fileStream2;
    std::ofstream outFileStream;

    //open files for reading and check to make sure we don't have any errors

    fileStream1.open(file1.c_str());
    fileStream2.open(file2.c_str());
    outFileStream.open(OUT_FILE_NAME);


    int fileValue1;
    int fileValue2;
    bool fileValue1Used = true;
    bool fileValue2Used = true;
    bool fileContinue1 = true;
    bool fileContinue2 = true;

    if(fileStream1 && fileStream2 && outFileStream)
    {
        //if we have gotten this far, we can read or write to all files
        do
        {
            //Populate our variables and see if we need to keep populating from a
            //given file
            if(fileContinue1 && fileValue1Used)
            {
                if (fileStream1 >> fileValue1)
                {
                    fileValue1Used = false;
                }
                else
                {
                    fileContinue1 = false;
                }
            }
            if(fileContinue2 && fileValue2Used)
            {
                if (fileStream2 >> fileValue2)
                {
                    fileValue2Used = false;
                }
                else
                {
                    fileContinue2 = false;

                }
            }

            //Now the logic to write out...

            if(!fileContinue1 && fileContinue2)
            {
                outFileStream << fileValue2 << '\n';
                fileValue2Used = true;


            }
            else if(fileContinue1 && !fileContinue2)
            {
                outFileStream << fileValue1 << '\n';
                fileValue1Used = true;
            }
            else if((fileValue1 > fileValue2) && (fileContinue1 && fileContinue2))
            {
                outFileStream << fileValue2 << '\n';
                fileValue2Used = true;
            }
            else if((fileValue1 < fileValue2) && (fileContinue1 && fileContinue2))
            {
                outFileStream << fileValue1 << '\n';
                fileValue1Used = true;
            }
            else if((fileValue1 == fileValue2) && (fileContinue1 && fileContinue2))
            {
                outFileStream << fileValue1 << '\n' << fileValue2 << '\n';
                fileValue1Used = true;
                fileValue2Used = true;
            }



        } while(fileContinue1 || fileContinue2);

    }
    else
    {
        std::cout << "ERROR!" << std::endl;

        if(!fileStream1)
        {
            std::cout << "Unable to read from file: " << file1 << std::endl;
        }
        if(!fileStream2)
        {
            std::cout << "Unable to read from file: " << file2 << std::endl;
        }
        if(!outFileStream)
        {
            std::cout << "Unable to write to file: " << OUT_FILE_NAME << std::endl;
        }
    }

    fileStream1.close();
    fileStream2.close();
    outFileStream.close();


}

int main()
{
    sortTwoFiles("file1.txt", "file2.txt");
    return 0;
}
