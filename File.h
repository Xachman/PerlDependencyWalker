/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   File.h
 * Author: xach
 *
 * Created on November 8, 2016, 1:28 PM
 */

#ifndef FILE_H
#define FILE_H
#include "FilePath.h"
#include <string>

class File {
public:
    File();
    File(const File& orig);
    File(FilePath filePath);
    virtual ~File();
    FilePath getFilePath();
private:
    FilePath filePath;
    
};

#endif /* FILE_H */

