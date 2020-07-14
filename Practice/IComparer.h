#pragma once
#include "Person.h"

class IComparer {
    public:
        IComparer() {

        }
        virtual bool Compare(Person a, Person b) {
            cout << "inside icomparer";
            return true;
        }
        
};