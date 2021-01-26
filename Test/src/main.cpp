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
 * File:   main.cpp
 * Author: Lakshitha Dayasena
 *
 * Created on 26 January 2021, 11:33
 */

#include "lakvik/properties/threadsafe_event.h"
#include <cstdlib>
int main(int argc, char** argv)
{
    using test_event = lakvik::properties::event<int>;
    using test_threadsafe_event = lakvik::properties::threadsafe_event_for<test_event>;
    test_threadsafe_event event;
    return 0;
}

