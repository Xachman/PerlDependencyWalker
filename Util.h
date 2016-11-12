/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Util.h
 * Author: xach
 *
 * Created on November 6, 2016, 6:18 AM
 */

#ifndef UTIL_H
#define UTIL_H
#include <vector>
#include <string>

class Util {
public:
    Util();
    static std::vector<std::string> expload(std::string const & s, char delim);
    static bool findInArray(std::vector<std::string> stringAr, std::string value);
    static std::string trim(std::string str, const char* t = " \t\n\r\f\v");
private:

};

#endif /* UTIL_H */

