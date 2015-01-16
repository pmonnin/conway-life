#include <unistd.h>
#include "conwayworld.h"

ConwayWorld::ConwayWorld(int worldSize) : m_worldSize(worldSize), m_world(0), m_generationNumber(0)
{
    //Memory allocation
    m_world = new bool*[m_worldSize];

    if(m_world == 0)
        std::exit(-1);

    for(int i = 0 ; i < m_worldSize ; i++)
    {
        m_world[i] = 0;
        m_world[i] = new bool[m_worldSize];

        if(m_world[i] == 0)
            std::exit(-1);
    }

    //Memory random allocation
    for(int i = 0 ; i < m_worldSize ; i++)
    {
        for(int j  = 0 ; j < m_worldSize ; j++)
        {
            m_world[i][j] = (rand() % 2 != 0);
        }
    }
}

ConwayWorld::~ConwayWorld()
{
    for(int i = 0 ; i < m_worldSize ; i++)
    {
        delete m_world[i];
    }

    delete m_world;
}

void ConwayWorld::startSimulation()
{
    while(true)
    {
        printWorld();
        evolveWorld();
        sleep(1);
    }
}

void ConwayWorld::evolveWorld()
{
    bool worldCopy[m_worldSize][m_worldSize];

    //Computation
    for(int i = 0 ; i < m_worldSize ; i++)
    {
        for(int j = 0 ; j < m_worldSize ; j++)
        {
            int nbNeighborAlive = 0;

            for(int k = i - 1 ; k <= i + 1 ; k++)
            {
                if(k >= 0 && k < m_worldSize)
                {
                    for (int l = j - 1 ; l <= j + 1 ; l++)
                    {
                        if(l >= 0 && l < m_worldSize)
                        {
                            if(m_world[k][l] && !(k == i && l == j))
                                nbNeighborAlive++;
                        }
                    }
                }
            }

            worldCopy[i][j] = (nbNeighborAlive == 3) || (nbNeighborAlive == 2 && m_world[i][j]);
        }
    }

    //Copy
    for(int i = 0 ; i < m_worldSize ; i++)
    {
        for(int j = 0 ; j < m_worldSize ; j++)
        {
            m_world[i][j] = worldCopy[i][j];
        }
    }

    m_generationNumber++;
}

void ConwayWorld::printWorld()
{
    for(int i = 0 ; i < m_worldSize*10 ; i++)
        std::cout << std::endl;

    for(int i = 0 ; i < m_worldSize ; i++)
    {
        for(int j = 0 ; j < m_worldSize ; j++)
        {
            if(m_world[i][j])
                std::cout << "o";

            else
                std::cout << " ";
        }

        std::cout << std::endl;
    }

    std::cout << "Generation number: " << m_generationNumber << std::endl;
}
