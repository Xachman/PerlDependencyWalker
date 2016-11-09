/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: xach
 *
 * Created on November 5, 2016, 1:25 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm> // for std::find
#include <iterator> // for std::begin, std::end
#include "FilePath.h"
#include "DirectoryWalker.h"
#include "Util.h"


using namespace std;

class MainDirectoryWalker : public DirectoryWalker {
private:
public:

    void callback(File file) {
        size_t dot = file.getFilePath().getName().find_last_of(".");
        string extention = file.getFilePath().getName().substr(dot+1);
        string allowedExtentions[] = {"pl","pm"};
        cout << Util::findInArray(allowedExtentions, extention) << endl;
        
//        string line;
//        ifstream myfile(file.getFilePath().getPath().c_str());
//        if (myfile) // same as: if (myfile.good())
//        {
//            while (getline(myfile, line)) // same as: while (getline( myfile, line ).good())
//            {
//                //cout << file.getFilePath().getName() << endl;
//            }
//            myfile.close();
//        } 
    }
};

/*
 * 
 */
int main(int argc, char** argv) {

    FilePath filePath(argv[1]);

    MainDirectoryWalker dw = MainDirectoryWalker();
    dw.process(filePath);
    return 0;
}




