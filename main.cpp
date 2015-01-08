#include <iostream>
#include <SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Winform.h"
using namespace std;
const int width = 640;
const int height = 480;
Winform win;
float angle = 0.0;

void DrawCube(float size)
{
    glBegin(GL_QUADS);
    // front face
    glNormal3f(0.0,0.0,1.0);
   glColor3f(1.0,0.0,0.0);
    glVertex3f(size/2,size/2,size/2);
     glColor3f(0.0,1.0,0.0);
    glVertex3f(-size/2,size/2,size/2);
     glColor3f(1.0,0.0,0.0);
    glVertex3f(-size/2,-size/2,size/2);
     glColor3f(1.0,0.0,1.0);
    glVertex3f(size/2,-size/2,size/2);
    // left face
    glNormal3f(-1.0,0.0,0.0);
    glColor3f(1.0,1.0,0.0);
    glVertex3f(-size/2,size/2,size/2);
    glColor3f(3.0,1.0,2.0);
    glVertex3f(-size/2,-size/2,size/2);
    glColor3f(0.0,1.0,5.0);
    glVertex3f(-size/2,-size/2,-size/2);
    glColor3f(9.0,0.0,8.0);
    glVertex3f(-size/2,size/2,-size/2);
    // back face
    glNormal3f(0.0,0.0,-1.0);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(size/2,size/2,-size/2);
    glColor3f(0.0,7.0,1.0);
    glVertex3f(-size/2,size/2,-size/2);
    glColor3f(0.0,0.0,1.0);
    glVertex3f(-size/2,-size/2,-size/2);
    glColor3f(0.0,1.0,0.0);
    glVertex3f(size/2,-size/2,-size/2);
    // right face
    glNormal3f(1.0,0.0,0.0);
    glColor3f(1.0,1.0,0.0);
    glVertex3f(size/2,size/2,size/2);
    glColor3f(1.0,0.0,1.0);
    glVertex3f(size/2,-size/2,size/2);
    glColor3f(0.0,1.0,1.0);
    glVertex3f(size/2,-size/2,-size/2);
    glColor3f(1.0,1.0,7.0);
    glVertex3f(size/2,size/2,-size/2);
    // top face
    glNormal3f(0.0,1.0,0.0);
    glColor3f(1.0,0.0,1.0);
    glVertex3f(size/2,size/2,size/2);
    glColor3f(0.0,1.0,1.0);
    glVertex3f(-size/2,size/2,size/2);
    glColor3f(0.0,1.0,0.0);
    glVertex3f(-size/2,size/2,-size/2);
    glColor3f(0.0,0.0,1.0);
    glVertex3f(size/2,size/2,-size/2);
    // bottom face
    glNormal3f(0.0,-1.0,0.0);
    glColor3f(0.0,1.0,1.0);
    glVertex3f(size/2,-size/2,size/2);
     glColor3f(1.0,1.0,0.0);
    glVertex3f(-size/2,-size/2,size/2);
     glColor3f(1.0,0.0,1.0);
    glVertex3f(-size/2,-size/2,-size/2);
     glColor3f(100.0,51.0,78.0);
    glVertex3f(size/2,-size/2,-size/2);
    glEnd();
}
void Update()
{
    glColor3f(0.0f,0.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
    glLoadIdentity();
    glTranslated(0.0,0.0,-3.0);
    glRotatef(angle,0.0,3.0,1.0);
    glRotatef(angle,3.0,1.0,0.0);
    DrawCube(1.0);
    angle += 0.08;
    if(angle > 360)
    {
        angle -= 360;
    }
}

int main(int argc, char* args[])
{
    if(!win.Init(width,height))
    {
        cout << "Init Fail" << endl;
    }
    else
    {
        win.InitGL();
        if(!win.Setviewport(width,height))
        {
            cout << "Setview Fail" << endl;
        }
        else
        {
            SDL_Event e;
            bool Quit = true;
            while(Quit)
            {
                while(SDL_PollEvent( &e) != 0)
                {
                    if(e.type == SDL_QUIT)
                    {
                        Quit = false;
                    }
                }
                Update();
                SDL_GL_SwapWindow(win.getWindow());
            }
        }
    }
    win.Close();
    return 0;
}
