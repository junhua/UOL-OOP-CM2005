#include <iostream>
#include "WeatherMain.h"

int main()
{
    try
    {
        WeatherMain weatherMain;
        weatherMain.init();
    }
    catch (const std::exception &e)
    {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
    return 0;
}