#include "boost/date_time/posix_time/posix_time.hpp"
#include "date/tz.h"
#include <iostream>

int main()
{
    auto now = date::zoned_time { date::current_zone(), std::chrono::system_clock::now() };
    std::cout << format("%Y-%m-%dT%H:%M:%S%z", now) << '\n';
    std::cout << std::flush;
}