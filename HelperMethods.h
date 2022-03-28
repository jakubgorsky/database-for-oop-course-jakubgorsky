//
// Created by Jakub Górski on 28/03/2022.
//

#ifndef DATABASE_FOR_OOP_COURSE_JAKUBGORSKY_HELPERMETHODS_H
#define DATABASE_FOR_OOP_COURSE_JAKUBGORSKY_HELPERMETHODS_H

#include <string>
#include <sstream>

template <class Container>
void split_string(const std::string& str, Container& cont, char delim = ',') {
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) cont.push_back(token);
}

std::string left(std::string s, int w);

#endif //DATABASE_FOR_OOP_COURSE_JAKUBGORSKY_HELPERMETHODS_H
