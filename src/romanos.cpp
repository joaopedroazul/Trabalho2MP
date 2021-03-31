// Copyright [2020] <Copyright Joao Pedro>
#include <string.h>
#include <cctype>
#include <iostream>
#include <fstream>
#include "../include/catch.hpp"
#include "../include/romanos.hpp"

char algarismosSignificativos[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
char dezena[2] = {'I', 'V'};
char centena[4] = {'I', 'V', 'X', 'L'};
int valuesAlgarismos[7] = {1, 5, 10, 50, 100, 500, 1000};
int checkString(string numRomano) {
    int sizeString = numRomano.size();
    int returnCheck = 0;
    int flag = 0;
    if (sizeString > 30) {
        return -1;
    }
    for (int i = 0; i < sizeString; i++) {
        if (isdigit(numRomano[i])) {
            returnCheck = -1;
            break;
        } else if (ispunct(numRomano[i])) {
            returnCheck = -1;
            break;
        } else if (isspace(numRomano[i])) {
            returnCheck = -1;
            break;
        } else if (islower(numRomano[i])) {
            returnCheck = -1;
            break;
        } else if (isupper(numRomano[i])) {
            for (int j = 0; j < 7; j++) {
                if (numRomano[i] == algarismosSignificativos[j]) {
                    flag += 1;
                }
            }
        }
    }
    if (flag != sizeString) {
        returnCheck = -1;
    } else if (flag = sizeString) {
        returnCheck = 0;
    }
    if (returnCheck == 0) {
        returnCheck = toInt(numRomano);
    }
    return returnCheck;
}

int toInt(string numRomano) {
    int counter = 0;
    for (int j = 0; j < numRomano.size(); j++) {
        // numRomano[j] = M
        if (numRomano[j] == algarismosSignificativos[6]) {
            counter += 1000;
            if (counter == 3000) {
                 if (numRomano[j+1] != '\0') {
                     return -1;
                 }
            }
        // numRomano[j] = C
        } else if (numRomano[j] == algarismosSignificativos[4]) {
            // numRomano[j],numRomano[j+1] = CM
            if (numRomano[j+1] == algarismosSignificativos[6]) {
                counter += 900;
                j++;
                bool flag = true;
                for (int z = 0; z< 4; z++) {
                    if (numRomano[j+1] == centena[z]) {
                        flag = true;
                        break;
                    } else {
                        flag = false;
                    }
                }
                if (numRomano[j+1] == '\0')
                    flag = true;
                if (flag == false) {
                    return -1;
                }
            // numRomano[j],numRomano[j+1] = CD
            } else if (numRomano[j+1] == algarismosSignificativos[5]) {
                counter += 400;
                j++;
                bool flag = true;
                for (int z = 0; z < 4; z++) {
                    if (numRomano[j+1] == centena[z]) {
                        flag = true;
                        break;
                    } else {
                        flag = false;
                    }
                }
                if (numRomano[j+1] == '\0')
                    flag = true;
                if (flag == false) {
                    return -1;
                }
            } else {  // numRomano[j] = C , CC , CCC
                int cLimit = 0;
                for (int z = 0; z < 3; z++) {
                    cLimit = cLimit+1;
                    counter = counter + 100;
                    if (numRomano[j+1] != algarismosSignificativos[4]) {
                        break;
                    } else {
                        if (cLimit ==3) {
                            break;
                        }
                        j++;
                    }
                }
                bool flag = true;
                for (int z = 0; z < 4; z++) {
                    if (numRomano[j+1] == centena[z]) {
                        flag = true;
                        break;
                    } else {
                        flag = false;
                    }
                }
                if (numRomano[j+1] == '\0')
                    flag = true;
                if (flag == false) {
                    return -1;
                }
            }
        // numRomano[j] = D
        } else if (numRomano[j] == algarismosSignificativos[5]) {
            counter += 500;
            if (numRomano[j+1] == algarismosSignificativos[4]) {
                int cLimit = 0;
                j++;
                for (int z = 0; z < 3; z++) {
                    cLimit = cLimit+1;
                    counter = counter + 100;
                    if (numRomano[j+1] != algarismosSignificativos[4]) {
                        break;
                    } else {
                        if (cLimit ==3) {
                            break;
                        }
                        j++;
                    }
                }
                bool flag1 = true;
                for (int z = 0; z< 4; z++) {
                    if (numRomano[j+1] == centena[z])  {
                        flag1 = true;
                        break;
                    } else {
                        flag1 = false;
                    }
                }
                if (numRomano[j+1] == '\0')
                    flag1 = true;
                if (flag1 == false) {
                    return -1;
                }
            } else {
                bool flag = true;
                for (int z = 0; z < 4; z++) {
                    if (numRomano[j+1] == centena[z]) {
                        flag = true;
                        break;
                    } else {
                        flag = false;
                    }
                }
                if (numRomano[j+1] == '\0')
                    flag = true;
                if (flag == false) {
                    return -1;
                }
            }
        // numRomano[j] = X
        }  else if (numRomano[j] == algarismosSignificativos[2]) {
            // numRomano[j],numRomano[j+1] = XC
            if (numRomano[j+1] == algarismosSignificativos[4]) {
                counter += 90;
                bool flag = true;
                j++;
                for (int z = 0; z< 2; z++) {
                    if (numRomano[j+1] == dezena[z]) {
                        flag = true;
                        break;
                    } else {
                        flag = false;
                    }
                }
                if (numRomano[j+1] == '\0')
                    flag = true;
                if (flag == false) {
                    return -1;
                }
            // numRomano[j],numRomano[j+1] = XL
            } else if (numRomano[j+1] == algarismosSignificativos[3]) {
                counter += 40;
                bool flag = true;
                j++;
                for (int z = 0; z< 2; z++) {
                    if (numRomano[j+1] == dezena[z]) {
                        flag = true;
                        break;
                    } else {
                        flag = false;
                    }
                }
                if (numRomano[j+1] == '\0')
                    flag = true;
                if (flag == false) {
                    return -1;
                }
            // numRomano[j] = X , XX , XXX
            } else {
                int xLimit = 0;
                for (int z = 0; z < 3; z++) {
                    xLimit = xLimit+1;
                    counter = counter + 10;
                    if (numRomano[j+1] != algarismosSignificativos[2]) {
                        break;
                    } else {
                        if (xLimit ==3) {
                            break;
                        }
                        j++;
                    }
                }
                bool flag = true;
                for (int z = 0; z< 2; z++) {
                    if (numRomano[j+1] == dezena[z]) {
                        flag = true;
                        break;
                    } else {
                        flag = false;
                    }
                }
                if (numRomano[j+1] == '\0')
                    flag = true;
                if (flag == false) {
                    return -1;
                }
                
            }
        // numRomano[j] = L
        } else if (numRomano[j] == algarismosSignificativos[3]) {
                counter += 50;
                bool flag = true;
                for (int z = 0; z< 3; z++) {
                    if (numRomano[j+1] == centena[z]) {
                        flag = true;
                        break;
                    } else {
                        flag = false;
                    }
                }
                if (numRomano[j+1] == '\0')
                    flag = true;
                if (flag == false) {
                    return -1;
                }
         // numRomano[j] = I
        } else if (numRomano[j] == algarismosSignificativos[0]) {
             // numRomano[j],numRomano[j+1] = IX
            if (numRomano[j+1] == algarismosSignificativos[2]) {
                counter += 9;
                bool flag = true;
                j++;
                if (numRomano[j+1] == '\0') {
                    flag = true;
                    break;
                } else {
                    flag = false;
                }
                if (flag == false) {
                    return -1;
                }
            // numRomano[j],numRomano[j+1] = IV
            } else if (numRomano[j+1] == algarismosSignificativos[1]) {
                counter += 4;
                bool flag = true;
                j++;
                if (numRomano[j+1] == '\0') {
                    flag = true;
                    break;
                } else {
                    flag = false;
                }
                if (flag == false) {
                    return -1;
                }
            } else {  // numRomano[j] = I , II , III
                int iLimit = 0;
                for (int z = 0; z < 3; z++) {
                    iLimit = iLimit+1;
                    counter = counter + 1;
                    if (numRomano[j+1] != algarismosSignificativos[0]) {
                        break;
                    } else {
                        if (iLimit ==3) {
                            break;
                        }
                        j++;
                    }
                }
                bool flag = true;
                for (int z = 0; z< 2; z++) {
                    if (numRomano[j+1] == '\0')  {
                        flag = true;
                        break;
                    } else {
                        flag = false;
                    }
                }
                if (flag == false) {
                    return -1;
                }
            }
        // numRomano[j] = V
        } else if (numRomano[j] == algarismosSignificativos[1]) {
            counter += 5;
            j++;
            if (numRomano[j] == algarismosSignificativos[0]) {
                int iLimit = 0;
                for (int z = 0; z < 3; z++) {
                    iLimit = iLimit+1;
                    counter = counter + 1;
                    if (numRomano[j+1] != algarismosSignificativos[0]) {
                        break;
                    } else {
                        if (iLimit ==3) {
                            break;
                        }
                        j++;
                    }
                }
                bool flag1 = true;
                for (int z = 0; z< 2; z++) {
                    if (numRomano[j+1] == '\0')  {
                        flag1 = true;
                        break;
                    } else {
                        flag1 = false;
                    }
                }
                if (flag1 == false) {
                    return -1;
                }
            } else {    
                bool flag = true;
                j--;
                for (int z = 0; z< 4; z++) {
                    if (numRomano[j+1] == '\0') {
                        flag = true;
                        break;
                    } else {
                        flag = false;
                    }
                }
                if (flag == false) {
                    return -1;
                }
            }
        }
    }
    return counter;
}

