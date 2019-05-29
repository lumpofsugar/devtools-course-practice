// Copyright 2019 Holobko Vladimir

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include "include/stack_app.h"
#include "include/TStack.h"

std::string StackApp::operator()(int argc, const char** argv) {
    std::ostringstream stream;
    if (atoi(argv[1]) < 0) {
        stream << "-101";
        message_ = stream.str();
        return message_;
    }
    if (atoi(argv[1]) == 0) {
        stream << DataNoMem << "-103";
        message_ = stream.str();
        return message_;
    } else {
        TStack st(atoi(argv[1]));
        for (int i = 0; i < atoi(argv[1]); i++) {
            st.Put(i);
        }
        while (!st.IsEmpty()) {
            int temp;
            temp = st.Get();
            stream << "took_the_meaning" << temp << "code" << st.GetRetCode();
        }
    }
    message_ = stream.str();
    return message_;
}
