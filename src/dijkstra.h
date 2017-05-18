#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"

void shortest_path_dijkstra(graph *g, int src, int *d, int *prev);

void search_shortest_path(int *prev, int src, int dst, int *pathlen, int *path);

#endif