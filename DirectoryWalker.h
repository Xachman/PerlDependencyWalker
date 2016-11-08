/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DirectoryWalker.h
 * Author: xach
 *
 * Created on November 6, 2016, 7:17 AM
 */

#ifndef DIRECTORYWALKER_H
#define DIRECTORYWALKER_H
#include "FilePath.h"
#include "File.h"
#include <vector>
#include <string>


class DirectoryWalker {
public:
    virtual void callback(File file) = 0;    
    void process(FilePath filePath);
protected:
    FilePath filePath;
    
};

#endif /* DIRECTORYWALKER_H */

