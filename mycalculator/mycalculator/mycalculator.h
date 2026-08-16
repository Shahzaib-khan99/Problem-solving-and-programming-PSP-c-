#pragma once
#ifndef MYCALCULATOR_H
#define MYCALCULATOR_H

#include <string>

class mycalculator {
public:

    int prec(char op);

    bool checkvalid(const std::string& data);

    int usedop(int x, int y, char op);

    std::string infix_to_postfix(const std::string& exp);

    int solved_postfix(const std::string& exp);

    void solve(const std::string& exp);

    void help();
};

#endif