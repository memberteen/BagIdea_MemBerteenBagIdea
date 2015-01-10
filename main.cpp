#include <iostream>
#include <SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Winform.h"
#include "Job1.h"
using namespace std;
const int width = 640;
const int height = 480;
Winform win;
Job1 job;
unsigned int texure = 0;
float angle = 0.0;
float moveZ = -3.0;
float moveX = 0;
float moveY = 0;
bool sucZ = true;
bool sucX = true;
bool sucY = true;
void DrawCube(float size)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    //glLoadIdentity();
    float difamb[] = {1,0.5,0.3,1};
    glBindTexture(GL_TEXTURE_2D,texure);
    glBegin(GL_QUADS);
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,difamb);
    //front
    //glColor3f(1.0,0.0,0.0);
    glNormal3f(0,0,1);
    glTexCoord2f(0,1);
    glVertex3f(-size/2,size/2,size/2);
    glTexCoord2f(0,0);
    glVertex3f(-size/2,-size/2,size/2);
    glTexCoord2f(1,0);
    glVertex3f(size/2,-size/2,size/2);
    glTexCoord2f(1,1);
    glVertex3f(size/2,size/2,size/2);

    //back
    glNormal3f(0,0,-1);
    glTexCoord2f(0,1);
    glVertex3f(size/2,size/2,-size/2);
    glTexCoord2f(0,0);
    glVertex3f(-size/2,size/2,-size/2);
    glTexCoord2f(1,0);
    glVertex3f(-size/2,-size/2,-size/2);
    glTexCoord2f(1,1);
    glVertex3f(size/2,-size/2,-size/2);

    //top
    glNormal3f(0,1,0);
    glTexCoord2f(0,1);
    glVertex3f(size/2,size/2,size/2);
    glTexCoord2f(0,0);
    glVertex3f(-size/2,size/2,size/2);
    glTexCoord2f(1,0);
    glVertex3f(-size/2,size/2,-size/2);
    glTexCoord2f(1,1);
    glVertex3f(size/2,size/2,-size/2);

    //buttom
    glNormal3f(0,-1,0);
    glTexCoord2f(0,1);
    glVertex3f(size/2,-size/2,size/2);
    glTexCoord2f(0,0);
    glVertex3f(-size/2,-size/2,size/2);
    glTexCoord2f(1,0);
    glVertex3f(-size/2,-size/2,-size/2);
    glTexCoord2f(1,1);
    glVertex3f(size/2,-size/2,-size/2);

    //left
    glNormal3f(-1,0,0);
    glTexCoord2f(0,1);
    glVertex3f(-size/2,size/2,-size/2);
    glTexCoord2f(0,0);
    glVertex3f(-size/2,-size/2,-size/2);
    glTexCoord2f(1,0);
    glVertex3f(-size/2,-size/2,size/2);
    glTexCoord2f(1,1);
    glVertex3f(-size/2,size/2,size/2);

    //right
    glNormal3f(1,0,0);
    glTexCoord2f(0,1);
    glVertex3f(size/2,size/2,-size/2);
    glTexCoord2f(0,0);
    glVertex3f(size/2,-size/2,-size/2);
    glTexCoord2f(1,0);
    glVertex3f(size/2,-size/2,size/2);
    glTexCoord2f(1,1);
    glVertex3f(size/2,size/2,size/2);
    glEnd();
}
void Move(float x,float y,float z)
{
    if(moveZ < -7)
    {
        sucZ = false;
    }
    if(moveZ > -2)
    {
        sucZ = true;
    }
    if(moveX >= 2)
    {
        sucX = false;
    }
    if(moveX < -2)
    {
        sucX = true;
    }
    if(moveY >= 2)
    {
        sucY = false;
    }
    if(moveY < -2)
    {
        sucY = true;
    }
}
void Update()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
    glLoadIdentity();
    glTranslated(moveX,moveY,moveZ);
    glRotated(45,1.0,0.0,0.0);
    glRotated(angle,0.0,1.0,0.0);
    DrawCube(1.0);
    angle += 0.1;
    Move(moveX,moveY,moveZ);
    if(sucY == false)
    {
        moveY -= 0.005;
    }
    else if(sucY == true)
    {
        moveY += 0.005;
    }
    if(sucZ == true)
    {
        moveZ -=0.005;
    }
    else if(sucZ == false)
    {
        moveZ += 0.005;
    }
    if(sucX == false)
    {
        moveX -= 0.005;
    }
    if(sucX == true)
    {
        moveX += 0.005;
    }
    else if(angle > 360)
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
        job.setLight();
        texure = job.loadingTexture("bg.bmp");
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
