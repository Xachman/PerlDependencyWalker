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


Util::Util() {
    
}

std::vector<std::string> Util::expload(std::string const & s, char delim) {
    std::vector<std::string> result;
    std::istringstream iss(s);

    for (std::string token; std::getline(iss, token, delim); )
    {
        result.push_back(token);
    }

    return result;
}





