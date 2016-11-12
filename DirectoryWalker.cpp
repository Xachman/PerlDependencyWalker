/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DirectoryWalker.cpp
 * Author: xach
 * 
 * Created on November 6, 2016, 7:17 AM
 */

#include "DirectoryWalker.h"
#include "FilePath.h"
#include "File.h"
#include <iostream>


void DirectoryWalker::process(FilePath filePath) {
    std::vector<std::string> files = filePath.getFiles();
    if(filePath.isDirectory()) {
        
        for(int i = 0; i < files.size(); i++) {
            char hidden = files[i][0];
            if(files[i] == "." || files[i] == ".." || hidden == '.'){
                continue;
            }
            
            FilePath subFilePath = FilePath(filePath.addSeparator()+files[i]);
            if(subFilePath.isDirectory()) {
                this->process(subFilePath);
            }else {
                this->callback(File(subFilePath));
            }
        }
    }
}




