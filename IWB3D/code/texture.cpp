#include "texture.h"

#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"
#include "SDL/SDL_image.h"

#include <iostream>
using namespace std;

texture::texture(){
}

texture::~texture(){
	glDeleteTextures( 1, &id );
}

void texture::loadTexture(string filepath){
	SDL_Surface *loaded_surface;
    SDL_Surface *surface;	// This surface will tell us the details of the image
    GLenum texture_format;
    GLint  nOfColors;

    if ( (loaded_surface = IMG_Load(filepath.c_str())) ) {

		//optimize
		surface = SDL_DisplayFormat( loaded_surface );
		SDL_FreeSurface( loaded_surface );

        // Check that the image's width is a power of 2
        if ( (surface->w & (surface->w - 1)) != 0 ) {
            cout << "warning: "<< filepath.c_str() <<"'s width is not a power of 2" << endl;
        }

        // Also check if the height is a power of 2
        if ( (surface->h & (surface->h - 1)) != 0 ) {
            cout << "warning: "<< filepath.c_str() <<"'s height is not a power of 2" << endl;
        }

        // get the number of channels in the SDL surface
        nOfColors = surface->format->BytesPerPixel;
        if (nOfColors == 4)     // contains an alpha channel
        {
            if (surface->format->Rmask == 0x000000ff)
                texture_format = GL_RGBA;
            else
                texture_format = GL_BGRA;
        } else if (nOfColors == 3)     // no alpha channel
        {
            if (surface->format->Rmask == 0x000000ff)
                texture_format = GL_RGB;
            else
                texture_format = GL_BGR;
        } else {
            cout << "warning: "<< filepath.c_str() <<" is not truecolor..  this will probably break\n" << endl;
            // this error should not go unhandled
        }

        // Have OpenGL generate a texture object handle for us
        glGenTextures( 1, &id );

        // Bind the texture object
        glBindTexture( GL_TEXTURE_2D, id );

        // Set the texture's stretching properties
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

        // Edit the texture object's image data using the information SDL_Surface gives us
        glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, surface->w, surface->h, 0,
                      texture_format, GL_UNSIGNED_BYTE, surface->pixels );
    }
    else {
        printf("SDL could not load image: %s\n", SDL_GetError());
        SDL_Quit();
    }

// Free the SDL_Surface only if it was successfully created
    if ( surface ) {
        SDL_FreeSurface( surface );
    }
}
