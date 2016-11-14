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
#include <sstream>
#include <exception>

UseStatement::UseStatement() {
}

UseStatement::UseStatement(std::string statement) : inputStatement(statement) {
    std::string useStatement = Util::trim(inputStatement);

    std::stringstream use;
    
    try {
        use << useStatement.at(0) << useStatement.at(1) << useStatement.at(2) << useStatement.at(3);
        
    } catch (std::out_of_range e) {
        throw "Bad Input";
    }
    
    if(use.str().compare("use ")) {
        throw "Bad Input";
    }
    
    
    module = parseModule(inputStatement);
    methods = parseMethods(inputStatement);
}

UseStatement::UseStatement(const UseStatement& orig) {
}

UseStatement::~UseStatement() {
}

std::vector<std::string> UseStatement::parseMethods(std::string subject) {
    std::string trimUseStr = this->trimUse(subject);
    bool qw = false;
    int start;
    int end;
    for (int i = 0; i < trimUseStr.length(); i++) {
        if (trimUseStr.at(i) == 'q' && trimUseStr.at(i + 1) == 'w') {
            qw = true;
        }

        if (qw) {
            if (trimUseStr.at(i) == '{' || trimUseStr.at(i) == '(') {
                start = i;
            }
            if (trimUseStr.at(i) == '}' || trimUseStr.at(i) == ')') {
                end = i;
            }
        }
    }

    if (qw) {
        std::string methodsString = Util::trim(trimUseStr.substr(start + 1, (end - start) - 1));
        return Util::expload(methodsString, ' ');
    }
    std::vector<std::string> hi;
    return hi;
}

std::string UseStatement::parseModule(std::string subject) {
    std::string trimUseStr = this->trimUse(subject);
    for (int i = 0; i < trimUseStr.length(); i++) {
        if ((trimUseStr.at(i) == ';' || trimUseStr.at(i) == ' ')) {
            std::string returnString = trimUseStr.substr(0, i);
            if (!checkBadKeywords(returnString)) {
                return returnString;
            }
            throw "Bad Input";
        }
    }
    throw "Bad Input";
}

std::string UseStatement::getModule() {
    return module;
}

std::string UseStatement::trimUse(std::string subject) {
    try {
        return subject.substr(4, subject.length());
    } catch (std::out_of_range e) {
        throw "Bad Input";
    }
}

std::string UseStatement::toString() {
    std::stringstream output;
    output << "Module:" << std::endl << "\t" << module << std::endl;
    if (methods.size() > 0) {
        output << "Methods:" << std::endl;
        for (int i = 0; i < methods.size(); i++) {
            output << "\t" << methods[i] << std::endl;
        }
    }
    return output.str();
}

bool UseStatement::checkBadKeywords(std::string subject) {
    std::vector<std::string> keywords;
    keywords.push_back("lib");
    keywords.push_back("strict");
    keywords.push_back("constant");

    for (int i = 0; i < keywords.size(); i++) {
        if (subject.compare(keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}



