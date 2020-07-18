#pragma once
#include "..\Person\Person.h"

class AbstractComparer {
    public:
        virtual bool Compare(Person& a, Person& b) = 0;
        
};