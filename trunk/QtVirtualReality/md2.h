/*
 * md2.c -- md2 model loader
 * last modification: aug. 14, 2007
 *
 * Copyright (c) 2005-2007 David HENRY
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * gcc -Wall -ansi -lGL -lGLU -lglut md2.c -o md2
 */

#ifndef H_MD2
#define H_MD2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/gl.h>



/* Vector */
typedef float vec3_t[3];

/* MD2 header */
struct md2_header_t
{
    int ident;
    int version;

    int skinwidth;
    int skinheight;

    int framesize;

    int num_skins;
    int num_vertices;
    int num_st;
    int num_tris;
    int num_glcmds;
    int num_frames;

    int offset_skins;
    int offset_st;
    int offset_tris;
    int offset_frames;
    int offset_glcmds;
    int offset_end;
};

/* Texture name */
struct md2_skin_t
{
    char name[64];
};

/* Texture coords */
struct md2_texCoord_t
{
    short s;
    short t;
};

/* Triangle info */
struct md2_triangle_t
{
    unsigned short vertex[3];
    unsigned short st[3];
};

/* Compressed vertex */
struct md2_vertex_t
{
    unsigned char v[3];
    unsigned char normalIndex;
};

/* Model frame */
struct md2_frame_t
{
    vec3_t scale;
    vec3_t translate;
    char name[16];
    struct md2_vertex_t *verts;
};

/* GL command packet */
struct md2_glcmd_t
{
    float s;
    float t;
    int index;
};

/* MD2 model structure */
typedef struct md2_model_t
{
    struct md2_header_t header;

    struct md2_skin_t *skins;
    struct md2_texCoord_t *texcoords;
    struct md2_triangle_t *triangles;
    struct md2_frame_t *frames;
    int *glcmds;

    GLuint tex_id;
}Mesh;


/**
 * Load an MD2 model from file.
 *
 * Note: MD2 format stores model's data in little-endian ordering.  On
 * big-endian machines, you'll have to perform proper conversions.
 */
int ReadMD2Model(const char *filename, struct md2_model_t *mdl);

/**
 * Free resources allocated for the model.
 */
void FreeModel(struct md2_model_t *mdl);

/**
 * Render the model at frame n.
 */
void RenderFrame(int n, const struct md2_model_t *mdl);

/**
 * Render the model at frame n.
 */
void RenderFrameV(int n, const struct md2_model_t *mdl, float vezes);

/**
 * Render the model with interpolation between frame n and n+1.
 * interp is the interpolation percent. (from 0.0 to 1.0)
 */
void RenderFrameItp(int n, float interp, const struct md2_model_t *mdl);

/**
 * Render the model at frame n using model's GL command list.
 */
void RenderFrameWithGLCmds(int n, const struct md2_model_t *mdl);

/**
 * Render the model with interpolation between frame n and n+1
 * using model's GL command list.
 * interp is the interpolation percent. (from 0.0 to 1.0)
 */
void RenderFrameItpWithGLCmds(int n, float interp, const struct md2_model_t *mdl);

/**
 * Calculate the current frame in animation beginning at frame
 * 'start' and ending at frame 'end', given interpolation percent.
 * interp will be reseted to 0.0 if the next frame is reached.
 */
void Animate(int start, int end, int *frame, float *interp);

/// BRAVE HEART EDITED FUNCTION ///
Mesh* load_MD2(const char *filename);

#endif  //H_MD2
