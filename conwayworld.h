#ifndef CONWAYWORLD_H
#define CONWAYWORLD_H

#include <cstdlib>
#include <ctime>
#include <iostream>

class ConwayWorld
{
    public:
        ConwayWorld(int worldSize = 10);
        virtual ~ConwayWorld();
        void startSimulation();

    private:
        void evolveWorld();
        void printWorld();

        int       m_generationNumber;
        int       m_worldSize;
        bool    **m_world;
};

#endif // CONWAYWORLD_H
