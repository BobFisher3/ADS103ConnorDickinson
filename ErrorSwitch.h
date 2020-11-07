#pragma once
#include <iostream>

using namespace std;

class ErrorSwitch {
public:
    int lineCheck, listSize;

    //This is a seperate class as it is reusable to check the first two lines for errors
    bool errorCheck() {
        switch (lineCheck) {
        case 0:
            return true;
            break;
        case 1:
            return true;
            break;
        default:
            return false;
        }
    }

    //Check for 3rd line error
    bool errorCheck2() {
       if (lineCheck < 0){
           return false;
       }
       else {
           return true;
       }
    }

    //Check to see if 4th line matches 3rd line input
    bool errorCheck3() {
        if (lineCheck != listSize){
            return false;
        }
        else {
            return true;
        }
    }
};

