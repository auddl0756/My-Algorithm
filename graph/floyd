const int MAX=101;
int graph[MAX][MAX];
int V, E;

void floyd() {
	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				if (k == i || k == j || i == j) continue;
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
}
