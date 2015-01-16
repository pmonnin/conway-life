#include <iostream>
#include <ctime>
#include "conwayworld.h"

using namespace std;

int main()
{
    srand(time(NULL));

    ConwayWorld world(50);
    world.startSimulation();

    return 0;
}
