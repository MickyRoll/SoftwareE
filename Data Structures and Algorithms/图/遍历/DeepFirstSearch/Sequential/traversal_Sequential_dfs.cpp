#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define  VERTEX_NUM  8

bool visited[VERTEX_NUM] = {false};
int graph[VERTEX_NUM][VERTEX_NUM] = {
	{ 0,   1,   1,   0,   0,   0,   0,   0 },
	{ 1,   0,   0,   1,   1,   0,   0,   0 },
	{ 1,   0,   0,   0,   0,   1,   1,   0 },
	{ 0,   1,   0,   0,   0,   0,   0,   1 },
	{ 0,   1,   0,   0,   0,   0,   0,   1 },
	{ 0,   0,   1,   0,   0,   0,   0,   0 },
	{ 0,   0,   1,   0,   0,   0,   0,   0 },
	{ 0,   0,   0,   1,   1,   0,   0,   0 },
};


int getfirstadj(int v){
	int i;
	for (i = v+1; i < VERTEX_NUM; i++) {
		if (graph[v][i]) {
			return i;
		}
	}
	return 0;
}

int getotheradj(int v) {
	int i;
	bool isFirst = true;
	for (i = v + 1; i < VERTEX_NUM; i++) {
		if (graph[v][i]==1) {
			if (isFirst) {
				isFirst = false;
				continue;
			}
			graph[v][i] += 1;
			return i;
		}
	}
	return 0;
}

void dfs(int v) {
	int i, w;
	i = v;
	visited[i] = true;
	printf("V%d, ", i+1);
	w = getfirstadj(i);
	while (w!=0) {
		if (visited[w]) {
			w = getotheradj(i);
		}
		else
		{
			visited[w] = true;
			dfs(w);
		}
	}
}

void main()
{
	int i = 0;
	dfs(0);
	/*for (i = 0; i < VERTEX_NUM; i++) {
		printf("%d, ", visited[i]);
	}*/
}
