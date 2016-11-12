/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UseStatement.h
 * Author: xach
 *
 * Created on November 8, 2016, 1:05 PM
 */

#ifndef USESTATEMENT_H
#define USESTATEMENT_H
#include <string>
#include <vector>

class UseStatement {
public:
    UseStatement();
    UseStatement(const UseStatement& orig);
    virtual ~UseStatement();
    UseStatement(std::string statement);
    std::string toString();
private:
    std::string inputStatement;
    std::string module;
    std::vector<std::string> methods;
    std::string trimUse(std::string subject);
    std::string parseModule(std::string subject);
    bool checkBadKeywords(std::string subject);
    std::vector<std::string> parseMethods(std::string subject);

};

#endif /* USESTATEMENT_H */

