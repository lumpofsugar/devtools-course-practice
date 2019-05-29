// Copyright 2019 Holoblo Vladimir

#include <stdlib.h>
#include <iostream>
#include <string>

#include "include/stack_app.h"

int main(int argc, const char** argv) {
    StackApp app;
    std::cout << app(argc, argv) << std::endl;
    return 0;
}
