#ifndef WINFORM_H
#define WINFORM_H


class Winform
{
    public:
        Winform();
        bool Init(const int width,const int height);
        bool Setviewport(const int width,const int height);
        void InitGL();
        void Close();
        SDL_Window* getWindow();
    protected:
    private:
        SDL_Window* window;
        SDL_GLContext gl;
};

#endif // WINFORM_H
