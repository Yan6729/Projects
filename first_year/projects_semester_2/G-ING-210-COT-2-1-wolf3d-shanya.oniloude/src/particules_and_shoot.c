/*
** EPITECH PROJECT, 2025
** particule
** File description:
** shoot
*/

#include "../include/wolf3d_2.h"

particlesystem_t *create_particle_system(void)
{
    particlesystem_t *ps = malloc(sizeof(particlesystem_t));

    ps->count = 0;
    ps->vertices = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(ps->vertices, sfPoints);
    return ps;
}

void spawn_particles(particlesystem_t *ps, sfVector2f pos,
    int count, sfColor color)
{
    particle_t *p = NULL;
    float angle = 0.0f;
    float speed = 0.0f;

    for (int i = 0; i < count && ps->count < 1000; i++) {
        p = &ps->particles[ps->count];
        p->position = pos;
        angle = ((float)(rand() % 360)) * M_PI / 180.0f;
        speed = ((float)(rand() % 100)) / 50.0f + 1;
        p->velocity = (sfVector2f){cosf(angle) * speed, sinf(angle) * speed};
        p->color = color;
        p->life = ((float)(rand() % 100)) / 100.0f + 0.3f;
        p->size = 1.0f;
        ps->count++;
    }
}

void update_particles(particlesystem_t *ps, float delta_time)
{
    int i = 0;
    particle_t *p = NULL;

    while (i < ps->count) {
        p = &ps->particles[i];
        p->life -= delta_time;
        if (p->life <= 0) {
            ps->particles[i] = ps->particles[ps->count];
            ps->count--;
            continue;
        }
        p->position.x += p->velocity.x * delta_time * 100;
        p->position.y += p->velocity.y * delta_time * 100;
        i++;
    }
}

void draw_particles(sfRenderWindow *window, particlesystem_t *ps)
{
    sfVertex v;

    sfVertexArray_clear(ps->vertices);
    for (int i = 0; i < ps->count; i++) {
        v.position = ps->particles[i].position;
        v.color = ps->particles[i].color;
        sfVertexArray_append(ps->vertices, v);
    }
    sfRenderWindow_drawVertexArray(window, ps->vertices, NULL);
}
