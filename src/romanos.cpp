// Copyright [2020] <Copyright Joao Pedro>
#include <string.h>
#include <cctype>
#include <iostream>
#include "../include/catch.hpp"
#include "../include/romanos.hpp"

bool checkString(string numRomano) {
    int sizeString = numRomano.size();
    bool returnCheck = false;
    for (int i = 0; i< sizeString; i++) {
        if (isdigit(numRomano[i])) {
            returnCheck = false;
            break;
        }  else if (ispunct(numRomano[i])) {
            returnCheck = false;
            break;
        } else if (isspace(numRomano[i])) {
            returnCheck = false;
            break;
        } else if (islower(numRomano[i])) {
            returnCheck = false;
            break;
        } else if (isalpha(numRomano[i])) {
            returnCheck = true;
        }
    }
    return returnCheck;
}
