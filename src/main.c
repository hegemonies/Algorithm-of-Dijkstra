#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "dijkstra.h"
#include "heap.h"

int main(void)
{
	FILE *in = fopen("test.txt", "r");

	int pathlen;
	int vertex;
	int edge;
	int src = 1;

	fscanf(in, "%d", &vertex);
	fscanf(in, "%d", &edge);

	graph *g = graph_create(vertex);

	int weight;
	int v1;
	int v2;

	for (int i = 0; i < edge; i++) {
		fscanf(in, "%d %d %d", &v1, &v2, &weight);
		graph_set_edge(g, v1, v2, weight);
	}

	int *array_min_weight = malloc((g->nvert + 1) * sizeof(int));
	int *array_short_way = malloc((g->nvert + 1) * sizeof(int));

	shortest_path_dijkstra(g, src, array_min_weight, array_short_way);

	int path[g->nvert];

	for (int i = 1; i <= g->nvert; i++) {
		if (i != src) {
			search_shortest_path(array_short_way, src, i, &pathlen, path);

			printf("Min path from /%d/ -> /%d/ : ", src, i);

			for (int j = 1; j <= pathlen; j++) {
				if (j == pathlen) {
					printf("%d\n", path[j]);
				} else {
					printf("%d-> ", path[j]);
				}
			}
		}
	}

	graph_free(g);
	free(array_min_weight);
	free(array_short_way);
}