#include <iostream>
#include <SDL.h>
#include <math.h>
#include "Screen.hpp"
#include <stdlib.h>
#include <time.h>
#include "Swarm.hpp"

#define SDL_main main

using namespace std;

using namespace zmgfx;

int main()
{
    

    cout << "Start of program." << endl;

    // Seeding random number generator
    srand(time(NULL));

    Screen *screen = new Screen();

    if(screen->init("Particle Explosion Simulator") == false )
    {
        cout << "Error intializing SDL." << endl;
    }


    int elapsed;
    unsigned char red;
    unsigned char green;
    unsigned char blue;


    Swarm *swarm = new Swarm();

    while( true )
    {
        
        // Update Particles
        // Draw Particles
        // Check for messages/events


        // Draw particles
        elapsed = SDL_GetTicks();

        // screen->clear();
        screen->boxBlur();

        swarm->update(elapsed);

        // Slowly change these values from 0 to 255.
        // Using sin because this smoothly goes from -1 to 1 as time goes on.
        // Multiplying by elapsed time and decreasing rate
        // Add 1 to this value so it goes from 0 to 2
        // multiply by 128 so it goes from 0 to 256
        red = (sin(elapsed * .0001) + 1) * 128;
        green = (sin(elapsed * .0002) + 1) * 128;
        blue = (sin(elapsed * .0003) + 1) * 128;

        const Particle * const pParticles = swarm->getParticles();
        
        for ( int i = 0; i < Swarm::NPARTICLES; i++ )
        {
            Particle particle = pParticles[i];
            int x = (particle.m_x + 1) * (Screen::SCREEN_WIDTH / 2);
            int y = (particle.m_y * Screen::SCREEN_WIDTH / 2) + Screen::SCREEN_HEIGHT / 2;

            screen->setPixel(x, y , red, green, blue);

        }
        
        /*
        int elapsed = SDL_GetTicks();

        // Slowly change these values from 0 to 255.
        // Using sin because this smoothly goes from -1 to 1 as time goes on.
        // Multiplying by elapsed time and decreasing rate
        // Add 1 to this value so it goes from 0 to 2
        // multiply by 128 so it goes from 0 to 256
        red = (sin(elapsed * .0001) + 1) * 128;
        green = (sin(elapsed * .0002) + 1) * 128;
        blue = (sin(elapsed * .0003) + 1) * 128;


        
        for( int y = 0; y < Screen::SCREEN_HEIGHT; y++)
        {
            for ( int x = 0; x < Screen::SCREEN_WIDTH; x++ )
            {
                screen->setPixel(x, y, red, green, blue);
            }
        }

        */

        screen->update();
        if ( screen->processEvents() == false )
        {
            break;
        }
    }
    screen->close();
    delete screen;
    delete swarm;
    
    return 0;
}