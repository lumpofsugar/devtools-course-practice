// Copyright 2019 Holoblo Vladimir

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/stack_app.h"
#include "include/TStack.h"

using ::testing::internal::RE;
using std::vector;
using std::string;
using ::testing::internal::RE;
using std::vector;
using std::string;
class StackApplicationTest :public::testing::Test {
 protected:
    void Act(std::vector<std::string> args_) {
        std::vector<const char*> options;
        options.push_back("stack");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }
        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;
        output_ = app_(argc, argv);
    }
    void Assert(std::string expected) {
        EXPECT_TRUE(::testing::internal::RE::PartialMatch(output_,
        ::testing::internal::RE(expected)));
    }
 private:
    StackApp app_;
    std::string output_;
};

TEST_F(StackApplicationTest, Cant_Create_Negative_Size_Stack) {
    // Arrange
    std::vector<std::string> args = {"-1"};

    // Act
    Act(args);

    // Assert
    Assert("-101");
}

TEST_F(StackApplicationTest, Can_Create_Little_Stack) {
     // Arrange
     std::vector<std::string> args = {"1"};

     // Act
    Act(args);

     // Assert
    Assert("took_the_meaning0code0");
}

TEST_F(StackApplicationTest, Can_Create_Big_Stack) {
    // Arrange
    std::vector<std::string> args = {"10"};

     // Act
    Act(args);

     // Assert
    Assert("took_the_meaning9code0took_the_meaning8code0took_the_meaning7code0"
        "took_the_meaning6code0took_the_meaning5code0took_the_meaning4code0too"
        "k_the_meaning3code0took_the_meaning"
        "2code0took_the_meaning1code0took_the_meaning0code0");
}

TEST_F(StackApplicationTest, GetRetCode) {
    // Arrange
    TStack c;
    int b = DataOK;
    std::vector<std::string> args = {"0"};
    // Act
    Act(args);

    // Assert
    if (b == DataOK) {
        Assert("0");
    } else if (b == DataErr) {
        Assert("-1");
    }
}
