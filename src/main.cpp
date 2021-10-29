#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include <iostream>

#include "Universe.h"
#include "Star.h"

using namespace std;

int main(int argc, char *argv[])
{
    // Test
    Star s1 = Star(1, 1, 1);
    cout << s1 << endl;

    Universe u1 = Universe();
    cout << u1 << endl;

    // main
    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("Mon premier programme OpenGL !",NULL);
    SDL_SetVideoMode(640, 480, 32, SDL_OPENGL);

    bool continuer = true;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = false;
        }

        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);

        glPointSize( 2 );

        glBegin(GL_POINTS);
            // glColor3f(1,1,1);    glVertex3d(-0.75,-0.75, -0.9); 
            // glColor3f(1,1,1);    glVertex3d(0,0.75, 0.9);  
            // glColor3f(1,1,1);    glVertex3d(0.75,-0.75, 0); 
        glEnd();

        glFlush();
        SDL_GL_SwapBuffers();
    }

    SDL_Quit();

    return 0;
}