/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * FilePath:   file.h
 * Author: xach
 *
 * Created on November 5, 2016, 1:29 PM
 */

#ifndef FILEPATH_H
#define FILEPATH_H
#include <vector>
#include <string>

class FilePath {
    private:
        std::string path;
        std::string name;
        
        bool checkPath();
    public:
        FilePath();
        std::string addSeparator();
        FilePath(const FilePath& orig);
        FilePath(std::string path);
        std::string getPath();
        std::string getName();
        std::vector<std::string> getFiles();
        bool isDirectory();
        char separator();
};

#endif /* FILE_H */

