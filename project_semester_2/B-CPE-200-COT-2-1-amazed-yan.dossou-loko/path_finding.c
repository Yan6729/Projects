/*
** EPITECH PROJECT, 2025
** path_finding
** File description:
** finf the shrotest path
*/
/*
#include "amazed.h"

void init_dijkstra(item_t *queue, int *dist, int *prev, int start_index)
{
    for (int i = 0; i < nb_rooms; i++) {
        queue[i].index = i;
        queue[i].dist = INF;
        queue[i].visited = 0;
        dist[i] = INF;
        prev[i] = -1;
    }
    dist[start_index] = 0;
    queue[start_index].dist = 0;
}

int find_min_node(item_t *queue, int nb_rooms)
{
    int min_dist = INF;
    int min_index = -1;

    for (int i = 0; i < nb_rooms; i++) {
        if (!queue[i].visited && queue[i].dist < min_dist) {
            min_dist = queue[i].dist;
            min_index = i;
        }
    }
    return min_index;
}

void relax_neighbors(room_t **rooms, item_t *queue, int *prev, int u)
{
    for (int k = 0; k < rooms[u]->nb_neighbors; k++) {
        int v = rooms[u]->neighbors[k]->index;
        int alt = dist[u] + 1;

        if (queue[v].visited)
            continue;
        if (alt < dist[v]) {
            dist[v] = alt;
            prev[v] = u;
            queue[v].dist = alt;
        }
    }
}

void my_dijkstra(room_t **rooms, int start_index, int *dist, int *prev)
{
    item_t queue[nb_rooms];

    init_dijkstra(queue, dist, prev, nb_rooms, start_index);
    for (int i = 0; i < nb_rooms; i++) {
        int u = find_min_node(queue, nb_rooms);
        if (u == -1)
            break;
        queue[u].visited = 1;
        relax_neighbors(rooms, queue, dist, prev, u);
    }
}
*/
