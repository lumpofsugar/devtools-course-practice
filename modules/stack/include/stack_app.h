// Copyright 2019 Holoblo Vladimir

#include <string>

#ifndef MODULES_STACK_INCLUDE_STACK_APP_H_
#define MODULES_STACK_INCLUDE_STACK_APP_H_

class StackApp {
 public:
    StackApp() = default;
    std::string operator()(int argc, const char** argv);
 private:
    std::string message_;
};

#endif  // MODULES_STACK_INCLUDE_STACK_APP_H_
