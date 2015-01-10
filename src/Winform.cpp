#include <SDL.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Winform.h"

using namespace std;
Winform::Winform()
{
    window = NULL;
    gl = NULL;
}
bool Winform::Init(const int width,const int height)
{
    bool success = true;
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        success = false;
    }
    else
    {
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,2);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,1);

        window = SDL_CreateWindow("MemberteenBagIdea",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width,height,SDL_WINDOW_SHOWN|SDL_WINDOW_OPENGL);
        if (window == NULL)
        {
            success = false;
        }
        else
        {
            gl = SDL_GL_CreateContext(window);
            InitGL();
        }
    }
    return success;
}
bool Winform::Setviewport(const int width,const int height)
{
    bool sucees = true;
    if(width <= 0|| height <=0)
    {
        sucees = false;
    }
    else
    {
        GLfloat ratio = (GLfloat)width/(GLfloat)height;
        glViewport(0,0,(GLfloat)width,(GLfloat)height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45,ratio,1.0,500);
        glMatrixMode(GL_MODELVIEW);
        glEnable(GL_DEPTH_TEST);

    }
    return sucees;
}
void Winform::InitGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
}
void Winform::Close()
{
    SDL_DestroyWindow(window);
    window = NULL;
    SDL_GL_DeleteContext(gl);
    gl = NULL;

    SDL_Quit();
}
SDL_Window* Winform::getWindow()
{
    return window;
}
