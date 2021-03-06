#define BOOST_TEST_MODULE GPIOInterfaceTest

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <thread>

#include "../include/Switch.h"

using namespace std;
using namespace hardware;

BOOST_AUTO_TEST_SUITE( switch_test )

        BOOST_AUTO_TEST_CASE( reading )
        {
                GPIO gpio;
                gpio.pinNumber = 97;

                Switch aSwitch(gpio);

        }

BOOST_AUTO_TEST_SUITE_END()
