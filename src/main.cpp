#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include <iostream>

#include "Universe.h"
#include "Star.h"
#include "Barnes.h"

using namespace std;

int main(int argc, char *argv[])
{

    Universe u1 = Universe(200, 100000);
    cout << u1 << endl;

    // main
    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("Mon premier programme OpenGL !",NULL);
    SDL_SetVideoMode(640, 480, 32, SDL_OPENGL);

    SDL_Event event;

    // Time managment
    Uint32 last_time = SDL_GetTicks();
    Uint32 current_time,ellapsed_time;
    Uint32 start_time; // for fps limitation
    int step = 0;

    for (;;)
    {
        cerr << endl <<endl <<  "Step " << step << endl;
        step ++;

        start_time = SDL_GetTicks(); 
        while (SDL_PollEvent(&event))
        {

            switch(event.type)
            {
                case SDL_QUIT:
                exit(0);
                break;
            }
        }

        // Time computation
        current_time = SDL_GetTicks();
        ellapsed_time = current_time - last_time;
        last_time = current_time;

        // Compute next iteration of the universe
        u1.compute(ellapsed_time);
        // Display universe
        u1.display();

        // wait until next frame
        ellapsed_time = SDL_GetTicks() - start_time;
        if (ellapsed_time < 10)
        {
            SDL_Delay(10 - ellapsed_time);
        }

    }

    SDL_Quit();

    return 0;
}