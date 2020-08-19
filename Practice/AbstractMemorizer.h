#pragma once
#include "Common.h"


class AbstractMemorizer {
public:
    virtual void Set(string key, int value) = 0;
    virtual int Get(string key) = 0;
};