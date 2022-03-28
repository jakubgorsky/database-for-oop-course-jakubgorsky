//
// Created by Jakub Górski on 28/03/2022.
//

#include "HelperMethods.h"

std::string left(const std::string s, const int w) {
    std::stringstream ss, spaces;
    int padding = w - s.size();
    for(int i=0; i<padding; ++i)
        spaces << " ";
    ss << s << spaces.str();
    return ss.str();
}