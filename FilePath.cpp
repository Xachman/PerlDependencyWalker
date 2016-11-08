/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * FilePath:   file.cpp
 * Author: xach
 * 
 * Created on November 5, 2016, 1:29 PM
 */

#include "FilePath.h"
#include <iostream>
#include <string>
#include <fstream>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <vector>
#include <bits/stdio_lim.h>
#include "Util.h"


FilePath::FilePath() {
    
}
FilePath::FilePath(const FilePath& orig) {
    this->path = orig.path;
    this->name = orig.name;
}

FilePath::FilePath(std::string path) {
    this->path = path;
    std::vector<std::string> pathsVector = Util::expload(path, separator());
    for (int i = 0; i < pathsVector.size(); i++) {
        if (i == (pathsVector.size() - 1)) {
            this->name = pathsVector[i];
        }
    }

}

std::string FilePath::getPath() {
    return this->path;
}

std::string FilePath::getName() {
    return this->name;
}

bool FilePath::isDirectory() {
    DIR *dirptr;

    if (access ( this->path.c_str(), F_OK ) != -1 ) {
        // file exists
        if ((dirptr = opendir (this->path.c_str())) != NULL) {
            closedir (dirptr);
        } else {
            return false; /* d exists, but not dir */
        }
    } else {
        return false;     /* d does not exist */
    }

    return true;
}

std::vector<std::string> FilePath::getFiles() {
    std::vector<std::string> returnVector = std::vector<std::string>();
    DIR *dir;
    struct dirent *item;
    dir = opendir(this->path.c_str());
    while ((item = readdir(dir)) != NULL) {
        returnVector.push_back(item->d_name);
    }
    closedir(dir);
    return returnVector;
}

char FilePath::separator() {
#ifdef _WIN32
    return '\\';
#else
    return '/';
#endif
}

std::string FilePath::addSeparator() {
    char lastChar = this->path[this->path.length() - 1];
    if (lastChar != separator()) {
        return this->path + separator();
    }
    return this->path;
}

bool FilePath::checkPath() {
    struct stat info;
    std::cout << addSeparator().c_str() << std::endl;
    if (stat(addSeparator().c_str(), &info) != 0)
        return true;
    else if (info.st_mode & S_IFDIR) // S_ISDIR() doesn't exist on my windows 
        return true;

    return false;
}