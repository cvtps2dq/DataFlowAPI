#include <iostream>
#include "DataFlow/Iris.API/Iris.Color/Iris.Color.h"

int main()
{
    const Iris::Color color(0.2,0.3,0.4,1.0);
    std::cout << color.toString() << std::endl;
    return 0;
}
