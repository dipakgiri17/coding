

/**
 * @brief Breath First Search algorithm
 * 
 * Complexity: 
 * 
 * Time Complexity: O(V+E) where v is number of nodes and E is the number of  edges.
 * 
 * Space complexity: O(V)
 * 
 * Used in Minimum spapanning tree and GPS
 * 
 */

#include <stdio.h>
#include <malloc.h>

#define SIZE 40

struct queue
{
    int items[SIZE];
    int front;
    int rear;
};

struct node
{
    int vertex;
    struct node *next;
};

struct node *createNode(int v)
{
    struct node *newNode = malloc(sizeof(struct node));

    newNode->vertex = v;
    newNode->next = NULL;
}

struct Graph
{
    int numVertices;
    struct node **adjLists;
    int *visited;
};

struct Graph *createGraph(int vertices)
{
    struct Graph *graph = malloc(sizeof(struct Graph));

    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node *));
    graph->visited = malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

struct queue *createQueue();
void enqueue(struct queue *q, int);
int dequeue(struct queue *q);
void display(struct queue *q);
int isEmpty(struct queue *q);
void printQueue(struct queue *q);

struct queue *createQueue()
{

    struct queue *q = malloc(sizeof(struct queue));

    q->front = -1;
    q->rear = -1;

    return q;
}

void enqueue(struct queue *q, int value)
{
    if (q->rear == SIZE - 1)
    {
        printf("\nQueue is Full!");
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct queue *q)
{
    int item;
    if (isEmpty(q))
    {
        printf("Queue is empty");
        item = -1;
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            printf("Ressetting queue");
            q->front = q->rear - 1;
        }
    }

    return item;
}

// Print the queue
void printQueue(struct queue *q)
{
    int i = q->front;

    if (isEmpty(q))
    {
        printf("Queue is empty");
    }
    else
    {
        printf("\nQueue contains \n");
        for (i = q->front; i < q->rear + 1; i++)
        {
            printf("%d ", q->items[i]);
        }
    }
}

void addEdge(struct Graph *graph, int src, int dest)
{
    struct node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

int isEmpty(struct queue *q)
{
    if (q->rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void bfs(struct Graph *graph, int startVertex)
{
    struct queue *q = createQueue();

    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);


    while(!isEmpty(q)){
        printQueue(q);

        int currentVertex = dequeue(q);
        printf("Visited %d\n", currentVertex);

        struct node* temp = graph->adjLists[currentVertex];

        while(temp) {
            int adjVertex = temp->vertex;

            if(graph->visited[adjVertex] == 0){
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp->next;
        }

    }
}

int main()
{

    struct Graph *graph = createGraph(5);
    addEdge(graph, 0, 1);

    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    bfs(graph, 0);



    return 0;
}

