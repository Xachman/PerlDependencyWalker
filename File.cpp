/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   File.cpp
 * Author: xach
 * 
 * Created on November 8, 2016, 1:28 PM
 */
#include "FilePath.h"
#include "File.h"

File::File() {
}

File::File(FilePath filePath): filePath(filePath){
    
}

File::File(const File& orig) {
}

File::~File() {
}

FilePath File::getFilePath() {
    return this->filePath;
}
