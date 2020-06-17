#include "Particle.hpp"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>

Particle::Particle(): m_x(0), m_y(0)
{
   m_direction = (2 * M_PI *rand())/RAND_MAX;
   m_speed = (0.02 * rand())/RAND_MAX;
   m_speed *= m_speed;
}

Particle::~Particle()
{
    
}

void Particle::init()
{
   m_x = 0;
   m_y = 0;
   m_direction = (2 * M_PI *rand())/RAND_MAX;
   m_speed = (0.02 * rand())/RAND_MAX;
   m_speed *= m_speed;
}

void Particle::update(int interval)
{
   m_direction += interval * .0003;
   double xspeed = m_speed * cos(m_direction);
   double yspeed = m_speed * sin(m_direction);

   m_x += xspeed * interval;
   m_y += yspeed * interval;

   // re-init any that float off the screen.
   if ( m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1 )
   {
      init();
   }

   // re-init some percent of the particles randomly
   if(rand() < RAND_MAX / 100)
   {
      init();
   }
}