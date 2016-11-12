/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UseStatement.cpp
 * Author: xach
 * 
 * Created on November 8, 2016, 1:05 PM
 */

#include "UseStatement.h"
#include "Util.h"
#include <vector>
#include <string>
#include <iostream>

UseStatement::UseStatement() {
}
UseStatement::UseStatement(std::string statement): inputStatement(statement){
    module = parseModule(inputStatement);
    
}
UseStatement::UseStatement(const UseStatement& orig) {
}

UseStatement::~UseStatement() {
}

std::vector<std::string> UseStatement::parseMethods(std::string subject) {
}

std::string UseStatement::parseModule(std::string subject) {
    std::string trimUseStr = this->trimUse(subject);
    for(int i = 0; i < trimUseStr.length(); i++) {
        if((trimUseStr.at(i) == ';' || trimUseStr.at(i) == ' ')) {
            std::string returnString = trimUseStr.substr(0, i);
            if(!checkBadKeywords(returnString)) {
                return returnString;
            }
            return "false";
        }
    }
    return "false";
}

std::string UseStatement::trimUse(std::string subject) {
    return subject.substr(4, subject.length());
}

std::string UseStatement::toString() {
    return parseModule(inputStatement);
}

bool UseStatement::checkBadKeywords(std::string subject) {
    std::vector<std::string> keywords;
    keywords.push_back("lib");
    keywords.push_back("strict");
    keywords.push_back("constant");
    
    for(int i = 0; i < keywords.size(); i++) {
        if(subject.compare(keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}



