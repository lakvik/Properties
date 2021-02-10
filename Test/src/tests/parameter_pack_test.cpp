/*
 * Copyright 2021 Lakshitha Dayasena.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* 
 * File:   parameter_pack_test.cpp
 * Author: Lakshitha Dayasena
 *
 * Created on 26 January 2021, 17:59
 */

#include "lakvik/properties/parameter_pack.h"
#include <stdlib.h>
#include <iostream>
#include <concepts>

namespace
{

    template<typename... args>
    struct dummy
    {
    };
}

void test1()
{
    std::cout << "parameter_pack_test test 1" << std::endl;
    using test = lakvik::properties::parameter_pack<int, double>;
    using expected = dummy<int, double>;
    using actual = test::apply_to<dummy>;
    if constexpr(!std::same_as<expected, actual>)
    {
        std::cout << "%TEST_FAILED% time=0 testname=test1 (parameter_pack_test) message=apply_to wrong output" << std::endl;
    }
}

int main(int argc, char** argv)
{
    std::cout << "%SUITE_STARTING% parameter_pack_test" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (parameter_pack_test)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% time=0 test1 (parameter_pack_test)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return(EXIT_SUCCESS);
}

