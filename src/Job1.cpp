#include <SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <iostream>
#include "Job1.h"

using namespace std;
Job1::Job1()
{
    //id = 0;
}
void Job1::setLight()
{
    float pos[] = {-4,2,-3,1};
    float dif[] = {3,3,3,3};
    float amb[] = {0.2,0.1,0.2,1.0};
    glLightfv(GL_LIGHT0,GL_POSITION,pos);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,dif);
    glLightfv(GL_LIGHT0,GL_AMBIENT,amb);
}
//unsigned int id;
unsigned int Job1::loadingTexture(const char* path)
{
    SDL_Surface* image = IMG_Load(path);
    if(image == NULL)
    {
        cout << "Fail Image" << endl;
    }
    unsigned int id;
    glGenTextures(1,&id);
    glBindTexture(GL_TEXTURE_2D,id);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,image->w,image->h,0,GL_RGB,GL_UNSIGNED_SHORT_5_6_5,image->pixels);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    return id;
}
