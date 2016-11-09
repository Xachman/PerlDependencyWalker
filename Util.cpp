/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Util.cpp
 * Author: xach
 * 
 * Created on November 6, 2016, 6:18 AM
 */

#include "Util.h"
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

Util::Util() {

}

std::vector<std::string> Util::expload(std::string const & s, char delim) {
    std::vector<std::string> result;
    std::istringstream iss(s);

    for (std::string token; std::getline(iss, token, delim);) {
        result.push_back(token);
    }

    return result;
}

bool Util::findInArray(std::string stringAr[], std::string value) {
    std::cout << sizeof(stringAr) << std::endl;
    for (int i = 0; i < (sizeof(stringAr)/sizeof(*stringAr)); i++) {
        
        if (Util::trim(stringAr[i]) == Util::trim(value))
            return true;
    }
    return false;
}

std::string Util::trim(std::string str, const char* t) {
    
    std::string trimend = str.erase(str.find_last_not_of(t) + 1);
    std::string trimbegin = trimend.erase(0, trimend.find_first_not_of(t));

    return trimbegin;
}






