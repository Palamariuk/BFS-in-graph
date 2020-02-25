/*Пошук вшир на С*/

#include <stdio.h>
#include <stdlib.h>
#define nodes 8

typedef struct queue {
	int num;
	struct queue* next;
} queue;

void push(queue** graph, int number) {
	queue* new = (queue*)malloc(sizeof(queue));
	new->num = number;
	new->next = NULL;

	if (!(*graph)) {
		*graph = new;
		return;
	}

	queue* cur = *graph;
	while (cur->next) {
		cur = cur->next;
	}
	cur->next = new;
}

void pop(queue** graph) {
	if ((*graph)->next) {
		queue* first = *graph;
		*graph = first->next;
		free(first);
		return;
	}
	free(*graph);
}

void BFS(int matrix[nodes][nodes], int nums[nodes], int n) {
	queue* graph = NULL;

	int count = 1;
	nums[n] = count++;
	push(&graph, n);

	while (count <= nodes) {
		for (int i = 0; i < nodes; i++) {
			if (nums[i] != 0 || matrix[graph->num][i] == 0) continue;
			push(&graph, i);
			nums[i] = count++;
		}
		pop(&graph);
	}
}

int main() {

	char names[nodes] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
	int nums[nodes] = { 0 };
	int matrix[nodes][nodes] = {
	{0,0,0,1,0,0,0,0},
	{0,0,1,1,0,0,0,0},
	{0,1,0,0,0,1,1,1},
	{1,1,0,0,0,0,0,0},
	{0,0,0,0,0,1,0,0},
	{0,0,1,0,1,0,0,0},
	{0,0,1,0,0,0,0,0},
	{0,0,1,0,0,0,0,0} };

	BFS(matrix, nums, 2);

	for (int i = 0; i < nodes; i++) printf("%c - %i\n", names[i], nums[i]);



}