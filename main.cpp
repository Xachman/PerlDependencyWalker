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
#include <vector>
#include <fstream>
#include <algorithm> // for std::find
#include <iterator> // for std::begin, std::end
#include <sstream>
#include "FilePath.h"
#include "DirectoryWalker.h"
#include "Util.h"
#include "UseStatement.h"


using namespace std;

class MainDirectoryWalker : public DirectoryWalker {
private:
public:

    void callback(File file) {
        size_t dot = file.getFilePath().getName().find_last_of(".");
        string extention = file.getFilePath().getName().substr(dot + 1);
        std::vector<std::string> allowedExtentions;
        allowedExtentions.push_back("pl");
        allowedExtentions.push_back("pm");
        if (Util::findInArray(allowedExtentions, extention)) {
            //cout << file.getFilePath().getPath() << endl;

            string line;
            ifstream myfile(file.getFilePath().getPath().c_str());
            if (myfile) // same as: if (myfile.good())
            {
                while (getline(myfile, line)) // same as: while (getline( myfile, line ).good())
                {

                    try {
                        stringstream useStatement;
                        useStatement << lookForUse(line) << endl;
                        if(useStatement.str().compare("false") != 1 ) {
                            cout << useStatement.str() << endl;
                        }
                        

                        //line.at
                        //    std::string use =  line.at(0)+""+line.at(1)+""+line.at(2);
                        //                cout << use << endl;
                    } catch (const std::out_of_range& e) {
                    }
                }
                myfile.close();
            }
        }

    }

    string lookForUse(string line) {
        string newLine = Util::trim(line);
        stringstream match;
        match << newLine.at(0) << newLine.at(1) << newLine.at(2) << newLine.at(3) << endl;
        
        if(match.str().compare("use ") == 1) {
            UseStatement useStatement(newLine);
            return useStatement.toString();
        }
        
        if(checkMatch(line, " use ")) {
            
        }
//        for(int i = 0; i < line.length(); i++) {
//            match << line.at(i);
//            if(checkMatch(match.str(), "use ")) {
//                
//            }
//            
//        }
        return "false";
    }
    
    bool checkMatch(string input, string match) {
        for(int i = 0; i < input.length(); i++) {
            if(input[i] != match[i]) {
                return false;
            }
        }
        return true;
    }
//    
//    bool 
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




