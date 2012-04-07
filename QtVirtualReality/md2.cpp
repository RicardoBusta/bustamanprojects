#include "md2.h"

/* Table of precalculated normals */
vec3_t anorms_table[162] = {
#include "anorms.h"
};

/*** An MD2 model ***/
struct md2_model_t md2file;



/**
 * Load an MD2 model from file.
 *
 * Note: MD2 format stores model's data in little-endian ordering.  On
 * big-endian machines, you'll have to perform proper conversions.
 */
int ReadMD2Model(const char *filename, struct md2_model_t *mdl)
{
    FILE *fp;
    int i;
    FILE* f;

    fp = fopen (filename, "rb");
    if(!fp)
    {
        f = fopen("debug.txt", "a");
        fprintf(f, "Erro...\n");
        fclose(f);
        fprintf (stderr, "Error: couldn't open \"%s\"!\n", filename);
        return 0;
    }



    /* Read header */
    fread (&mdl->header, 1, sizeof (struct md2_header_t), fp);


    if((mdl->header.ident != 844121161) || (mdl->header.version != 8))
    {
        f = fopen("debug.txt", "a");
        fprintf(f, "Erro...\n");
        fclose(f);
        /* Error! */
        fprintf (stderr, "Error: bad version or identifier\n");
        fclose (fp);
        return 0;
    }

    /* Memory allocations */
    mdl->skins = (struct md2_skin_t *) malloc(sizeof (struct md2_skin_t) * mdl->header.num_skins);
    mdl->texcoords = (struct md2_texCoord_t *) malloc(sizeof (struct md2_texCoord_t) * mdl->header.num_st);
    mdl->triangles = (struct md2_triangle_t *) malloc(sizeof (struct md2_triangle_t) * mdl->header.num_tris);
    mdl->frames = (struct md2_frame_t *) malloc(sizeof (struct md2_frame_t) * mdl->header.num_frames);
    mdl->glcmds = (int *) malloc(sizeof (int) * mdl->header.num_glcmds);


    /* Read model data */
    fseek (fp, mdl->header.offset_skins, SEEK_SET);
    fread (mdl->skins, sizeof (struct md2_skin_t), mdl->header.num_skins, fp);

    fseek (fp, mdl->header.offset_st, SEEK_SET);
    fread (mdl->texcoords, sizeof (struct md2_texCoord_t), mdl->header.num_st, fp);

    fseek (fp, mdl->header.offset_tris, SEEK_SET);
    fread (mdl->triangles, sizeof (struct md2_triangle_t), mdl->header.num_tris, fp);

    fseek (fp, mdl->header.offset_glcmds, SEEK_SET);
    fread (mdl->glcmds, sizeof (int), mdl->header.num_glcmds, fp);

    /* Read frames */
    fseek (fp, mdl->header.offset_frames, SEEK_SET);
    for (i = 0; i < mdl->header.num_frames; ++i)
    {
        /* Memory allocation for vertices of this frame */
        mdl->frames[i].verts = (struct md2_vertex_t *) malloc(sizeof (struct md2_vertex_t) * mdl->header.num_vertices);

        /* Read frame data */
        fread (mdl->frames[i].scale, sizeof (vec3_t), 1, fp);
        fread (mdl->frames[i].translate, sizeof (vec3_t), 1, fp);
        fread (mdl->frames[i].name, sizeof (char), 16, fp);
        fread (mdl->frames[i].verts, sizeof (struct md2_vertex_t), mdl->header.num_vertices, fp);
    }

    fclose (fp);
    return 1;
}

/**
 * Free resources allocated for the model.
 */
void FreeModel(struct md2_model_t *mdl)
{
    int i;

    if(mdl!=NULL)
    {
        if(mdl->skins)
        {
            free (mdl->skins);
            mdl->skins = NULL;
        }

        if(mdl->texcoords)
        {
            free (mdl->texcoords);
            mdl->texcoords = NULL;
        }

        if(mdl->triangles)
        {
            free (mdl->triangles);
            mdl->triangles = NULL;
        }

        if(mdl->glcmds)
        {
            free (mdl->glcmds);
            mdl->glcmds = NULL;
        }

        if(mdl->frames)
        {
            for (i = 0; i < mdl->header.num_frames; ++i)
            {
                free (mdl->frames[i].verts);
                mdl->frames[i].verts = NULL;
            }

            free (mdl->frames);
            mdl->frames = NULL;
        }
    }
}

void calcNormals(float v1[], float v2[], float v3[], float norm[])
{
    float vert1[3] = {v2[0] - v1[0], v2[1] - v1[1], v2[2] - v1[2]};
    float vert2[3] = {v3[0] - v1[0], v3[1] - v1[1], v3[2] - v1[2]};

    norm[0] = vert1[1]*vert2[2] - vert1[2]*vert2[1];
    norm[1] = vert1[2]*vert2[0] - vert1[0]*vert2[2];
    norm[2] = vert1[0]*vert2[1] - vert1[1]*vert2[0];
}

/**
 * Render the model at frame n.
 */
void RenderFrame(int n, const struct md2_model_t *mdl)
{
    if(mdl!=NULL)
    {
        int i, j;
        GLfloat s1, t1, s2, t2, s3, t3;
        vec3_t v1, v2, v3;
        struct md2_frame_t *pframe;
        struct md2_vertex_t *pvert;

        /* Check if n is in a valid range */
        if((n < 0) || (n > mdl->header.num_frames - 1))
            return;

        /* Draw the model */
        glBegin(GL_TRIANGLES);
        /* Draw each triangle */
        for (i = 0; i < mdl->header.num_tris; ++i)
        {
            /* Draw each vertex */
            //for (j = 0; j < 3; ++j)
            {
                pframe = &mdl->frames[n];
                pvert = &pframe->verts[mdl->triangles[i].vertex[0]];

                /* Compute texture coordinates */
                s1 = (GLfloat)mdl->texcoords[mdl->triangles[i].st[0]].s / mdl->header.skinwidth;
                t1 = (GLfloat)mdl->texcoords[mdl->triangles[i].st[0]].t / mdl->header.skinheight;

                /* Normal vector */
                //glNormal3fv(anorms_table[pvert->normalIndex]);

                /* Calculate vertex real position */
                v1[0] = (pframe->scale[0] * pvert->v[0]) + pframe->translate[0];
                v1[1] = (pframe->scale[1] * pvert->v[1]) + pframe->translate[1];
                v1[2] = (pframe->scale[2] * pvert->v[2]) + pframe->translate[2];

                pframe = &mdl->frames[n];
                pvert = &pframe->verts[mdl->triangles[i].vertex[1]];

                /* Compute texture coordinates */
                s2 = (GLfloat)mdl->texcoords[mdl->triangles[i].st[1]].s / mdl->header.skinwidth;
                t2 = (GLfloat)mdl->texcoords[mdl->triangles[i].st[1]].t / mdl->header.skinheight;

                /* Normal vector */
                //glNormal3fv(anorms_table[pvert->normalIndex]);

                /* Calculate vertex real position */
                v2[0] = (pframe->scale[0] * pvert->v[0]) + pframe->translate[0];
                v2[1] = (pframe->scale[1] * pvert->v[1]) + pframe->translate[1];
                v2[2] = (pframe->scale[2] * pvert->v[2]) + pframe->translate[2];

                pframe = &mdl->frames[n];
                pvert = &pframe->verts[mdl->triangles[i].vertex[2]];

                /* Compute texture coordinates */
                s3 = (GLfloat)mdl->texcoords[mdl->triangles[i].st[2]].s / mdl->header.skinwidth;
                t3 = (GLfloat)mdl->texcoords[mdl->triangles[i].st[2]].t / mdl->header.skinheight;

                /* Normal vector */
                //glNormal3fv(anorms_table[pvert->normalIndex]);

                /* Calculate vertex real position */
                v3[0] = (pframe->scale[0] * pvert->v[0]) + pframe->translate[0];
                v3[1] = (pframe->scale[1] * pvert->v[1]) + pframe->translate[1];
                v3[2] = (pframe->scale[2] * pvert->v[2]) + pframe->translate[2];

                float norm[3];
                calcNormals(v1,v2,v3,norm);

                glNormal3fv(norm);
                glTexCoord2f(s1, 1-t1);
                glVertex3fv(v1);

                glNormal3fv(norm);
                glTexCoord2f(s2, 1-t2);
                glVertex3fv(v2);

                glNormal3fv(norm);
                glTexCoord2f(s3, 1-t3);
                glVertex3fv(v3);
            }
        }
        glEnd();
    }
}

/**
 * Render the model at frame n.
 */
void RenderFrameV(int n, const struct md2_model_t *mdl, float vezes)
{
    if(mdl!=NULL)
    {
        int i, j;
        GLfloat s, t;
        vec3_t v;
        struct md2_frame_t *pframe;
        struct md2_vertex_t *pvert;

        /* Check if n is in a valid range */
        if((n < 0) || (n > mdl->header.num_frames - 1))
            return;

        /* Draw the model */
        glBegin(GL_TRIANGLES);
        /* Draw each triangle */
        for (i = 0; i < mdl->header.num_tris; ++i)
        {
            /* Draw each vertex */
            for (j = 0; j < 3; ++j)
            {
                pframe = &mdl->frames[n];
                pvert = &pframe->verts[mdl->triangles[i].vertex[j]];

                /* Compute texture coordinates */
                s = (GLfloat)mdl->texcoords[mdl->triangles[i].st[j]].s / mdl->header.skinwidth;
                t = (GLfloat)mdl->texcoords[mdl->triangles[i].st[j]].t / mdl->header.skinheight;

                /* Pass texture coordinates to OpenGL */
                glTexCoord2f(s, t);

                /* Normal vector */
                glNormal3fv(anorms_table[pvert->normalIndex]);

                /* Calculate vertex real position */
                v[0] = (pframe->scale[0] * pvert->v[0]) + pframe->translate[0];
                v[1] = (pframe->scale[1] * pvert->v[1]) + pframe->translate[1];
                v[2] = (pframe->scale[2] * pvert->v[2]) + pframe->translate[2];

                v[0] = v[0]*vezes;
                v[1] = v[1]*vezes;
                v[2] = v[2]*vezes;

                glVertex3fv(v);
            }
        }
        glEnd();
    }
}

/**
 * Render the model with interpolation between frame n and n+1.
 * interp is the interpolation percent. (from 0.0 to 1.0)
 */
void RenderFrameItp(int n, float interp, const struct md2_model_t *mdl)
{
    int i, j;
    GLfloat s, t;
    vec3_t v_curr, v_next, v, norm;
    float *n_curr, *n_next;
    struct md2_frame_t *pframe1, *pframe2;
    struct md2_vertex_t *pvert1, *pvert2;

    /* Check if n is in a valid range */
    if((n < 0) || (n > mdl->header.num_frames))
        return;

    /* Enable model's texture */
    glBindTexture(GL_TEXTURE_2D, mdl->tex_id);

    /* Draw the model */
    glBegin(GL_TRIANGLES);
    /* Draw each triangle */
    for (i = 0; i < mdl->header.num_tris; ++i)
    {
        /* Draw each vertex */
        for (j = 0; j < 3; ++j)
        {
            pframe1 = &mdl->frames[n];
            pframe2 = &mdl->frames[n + 1];
            pvert1 = &pframe1->verts[mdl->triangles[i].vertex[j]];
            pvert2 = &pframe2->verts[mdl->triangles[i].vertex[j]];

            /* Compute texture coordinates */
            s = (GLfloat)mdl->texcoords[mdl->triangles[i].st[j]].s / mdl->header.skinwidth;
            t = (GLfloat)mdl->texcoords[mdl->triangles[i].st[j]].t / mdl->header.skinheight;

            /* Pass texture coordinates to OpenGL */
            glTexCoord2f (s, t);

            /* Interpolate normals */
            n_curr = anorms_table[pvert1->normalIndex];
            n_next = anorms_table[pvert2->normalIndex];

            norm[0] = n_curr[0] + interp * (n_next[0] - n_curr[0]);
            norm[1] = n_curr[1] + interp * (n_next[1] - n_curr[1]);
            norm[2] = n_curr[2] + interp * (n_next[2] - n_curr[2]);

            glNormal3fv (norm);

            /* Interpolate vertices */
            v_curr[0] = pframe1->scale[0] * pvert1->v[0] + pframe1->translate[0];
            v_curr[1] = pframe1->scale[1] * pvert1->v[1] + pframe1->translate[1];
            v_curr[2] = pframe1->scale[2] * pvert1->v[2] + pframe1->translate[2];

            v_next[0] = pframe2->scale[0] * pvert2->v[0] + pframe2->translate[0];
            v_next[1] = pframe2->scale[1] * pvert2->v[1] + pframe2->translate[1];
            v_next[2] = pframe2->scale[2] * pvert2->v[2] + pframe2->translate[2];

            v[0] = v_curr[0] + interp * (v_next[0] - v_curr[0]);
            v[1] = v_curr[1] + interp * (v_next[1] - v_curr[1]);
            v[2] = v_curr[2] + interp * (v_next[2] - v_curr[2]);

            glVertex3fv (v);
        }
    }
    glEnd();
}

/**
 * Render the model at frame n using model's GL command list.
 */
void RenderFrameWithGLCmds(int n, const struct md2_model_t *mdl)
{
  int i, *pglcmds;
  vec3_t v;
  struct md2_frame_t *pframe;
  struct md2_vertex_t *pvert;
  struct md2_glcmd_t *packet;

  /* Check if n is in a valid range */
  if((n < 0) || (n > mdl->header.num_frames - 1))
    return;

  /* Enable model's texture */
  glBindTexture (GL_TEXTURE_2D, mdl->tex_id);

  /* pglcmds points at the start of the command list */
  pglcmds = mdl->glcmds;

  /* Draw the model */
  while((i = *(pglcmds++)) != 0)
    {
      if(i < 0)
        {
          glBegin (GL_TRIANGLE_FAN);
          i = -i;
        }
      else
        {
          glBegin (GL_TRIANGLE_STRIP);
        }

      /* Draw each vertex of this group */
      for (/* Nothing */; i > 0; --i, pglcmds += 3)
        {
          packet = (struct md2_glcmd_t *)pglcmds;
          pframe = &mdl->frames[n];
          pvert = &pframe->verts[packet->index];

          /* Pass texture coordinates to OpenGL */
          glTexCoord2f (packet->s, packet->t);

          /* Normal vector */
          glNormal3fv (anorms_table[pvert->normalIndex]);

          /* Calculate vertex real position */
          v[0] = (pframe->scale[0] * pvert->v[0]) + pframe->translate[0];
          v[1] = (pframe->scale[1] * pvert->v[1]) + pframe->translate[1];
          v[2] = (pframe->scale[2] * pvert->v[2]) + pframe->translate[2];

          glVertex3fv (v);
        }

      glEnd ();
    }
}

/**
 * Render the model with interpolation between frame n and n+1
 * using model's GL command list.
 * interp is the interpolation percent. (from 0.0 to 1.0)
 */
void RenderFrameItpWithGLCmds(int n, float interp, const struct md2_model_t *mdl)
{
    int i, *pglcmds;
    vec3_t v_curr, v_next, v, norm;
    float *n_curr, *n_next;
    struct md2_frame_t *pframe1, *pframe2;
    struct md2_vertex_t *pvert1, *pvert2;
    struct md2_glcmd_t *packet;

    /* Check if n is in a valid range */
    if((n < 0) || (n > mdl->header.num_frames - 1))
    return;

    /* Enable model's texture */
    glBindTexture (GL_TEXTURE_2D, mdl->tex_id);

    /* pglcmds points at the start of the command list */
    pglcmds = mdl->glcmds;

    /* Draw the model */
    while((i = *(pglcmds++)) != 0)
    {
        if(i < 0)
        {
            glBegin (GL_TRIANGLE_FAN);
            i = -i;
        }
        else
        {
            glBegin (GL_TRIANGLE_STRIP);
        }

        /* Draw each vertex of this group */
        for (/* Nothing */; i > 0; --i, pglcmds += 3)
        {
            packet = (struct md2_glcmd_t *)pglcmds;
            pframe1 = &mdl->frames[n];
            pframe2 = &mdl->frames[n + 1];
            pvert1 = &pframe1->verts[packet->index];
            pvert2 = &pframe2->verts[packet->index];

            /* Pass texture coordinates to OpenGL */
            glTexCoord2f (packet->s, packet->t);

            /* Interpolate normals */
            n_curr = anorms_table[pvert1->normalIndex];
            n_next = anorms_table[pvert2->normalIndex];

            norm[0] = n_curr[0] + interp * (n_next[0] - n_curr[0]);
            norm[1] = n_curr[1] + interp * (n_next[1] - n_curr[1]);
            norm[2] = n_curr[2] + interp * (n_next[2] - n_curr[2]);

            glNormal3fv (norm);

            /* Interpolate vertices */
            v_curr[0] = pframe1->scale[0] * pvert1->v[0] + pframe1->translate[0];
            v_curr[1] = pframe1->scale[1] * pvert1->v[1] + pframe1->translate[1];
            v_curr[2] = pframe1->scale[2] * pvert1->v[2] + pframe1->translate[2];

            v_next[0] = pframe2->scale[0] * pvert2->v[0] + pframe2->translate[0];
            v_next[1] = pframe2->scale[1] * pvert2->v[1] + pframe2->translate[1];
            v_next[2] = pframe2->scale[2] * pvert2->v[2] + pframe2->translate[2];

            v[0] = v_curr[0] + interp * (v_next[0] - v_curr[0]);
            v[1] = v_curr[1] + interp * (v_next[1] - v_curr[1]);
            v[2] = v_curr[2] + interp * (v_next[2] - v_curr[2]);

            glVertex3fv (v);
        }

        glEnd ();
    }
}

/**
 * Calculate the current frame in animation beginning at frame
 * 'start' and ending at frame 'end', given interpolation percent.
 * interp will be reseted to 0.0 if the next frame is reached.
 */
void Animate(int start, int end, int *frame, float *interp)
{
    if((*frame < start) || (*frame > end))
        *frame = start;

    if(*interp >= 1.0f)
    {
        /* Move to next frame */
        *interp = 0.0f;
        (*frame)++;

        if(*frame >= end)
            *frame = start;
    }
}


/// BRAVE HEART EDITED FUNCTION ///
Mesh* load_MD2(const char *filename)
{
    Mesh* nova_mesh;
    nova_mesh = new Mesh;
    ReadMD2Model(filename, nova_mesh);

    return nova_mesh;
}

