#include "Particle.hpp"

class Swarm 
{
public:
    const static int NPARTICLES = 5000;

private:
    int lastTime;
    Particle * m_pParticles;

public:
Swarm();
virtual ~Swarm();
void update(int elapsed);

const Particle * const getParticles() { return m_pParticles; };
};