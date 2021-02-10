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
 * File:   threadsafe_event_test.cpp
 * Author: Lakshitha Dayasena
 *
 * Created on 10 February 2021, 12:27
 */
#include "lakvik/properties/threadsafe_event.h"
#include <stdlib.h>
#include <iostream>

void test1()
{
    std::cout << "threadsafe_event_test test 1" << std::endl;
    using test_event = lakvik::properties::event<int>;
    using test_threadsafe_event = lakvik::properties::threadsafe_event_for<test_event>;
    test_threadsafe_event event;
    if(!event.empty())
    {
        std::cout << "%TEST_FAILED% time=0 testname=test1 (threadsafe_event_test) message=default constructed event not empty" << std::endl;
    }
    auto id = event.add([](int){});
    if(event.empty())
    {
        std::cout << "%TEST_FAILED% time=0 testname=test1 (threadsafe_event_test) message=callback not added" << std::endl;
    }
    event.remove(id);
    if(!event.empty())
    {
        std::cout << "%TEST_FAILED% time=0 testname=test1 (threadsafe_event_test) message=callback not removed" << std::endl;
    }
}

void test2()
{
    //std::cout << "threadsafe_event_test test 2" << std::endl;
    //std::cout << "%TEST_FAILED% time=0 testname=test2 (threadsafe_event_test) message=error message sample" << std::endl;
}

int main(int argc, char** argv)
{
    std::cout << "%SUITE_STARTING% threadsafe_event_test" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (threadsafe_event_test)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% time=0 test1 (threadsafe_event_test)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (threadsafe_event_test)\n" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% time=0 test2 (threadsafe_event_test)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return(EXIT_SUCCESS);
}

