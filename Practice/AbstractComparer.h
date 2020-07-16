#pragma once
#include "Person.h"

class AbstractComparer {
    public:
        virtual bool Compare(Person a, Person b) = 0;
        
};