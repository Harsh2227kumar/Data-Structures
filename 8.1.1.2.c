#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct node{
	int vertex;
struct node *next;
}*GNODE;

GNODE graph[MAX];
void insertVertex(int *N);
void insertEdge(int *N);
void deleteVertex(int *N);
void deleteEdge(int *N);
void print(int *N);

void insertVertex(int *N){
	(*N)++;
	graph[*N]=NULL;
	printf("Vertex inserted: %d\n", *N);
}

void insertEdge(int *N){
	int s,d;
	GNODE q,p;
	printf("Enter the source vertex of the edge : ");
	scanf("%d",&s);
	printf("Enter the destination vertex of the edge : ");
	scanf("%d",&d);
	if(s> *N||d>*N||s<=0||d<=0){
		printf("Invalid vertex.\n");
		return;
	}
	q=(GNODE)malloc(sizeof(struct node));
	q->vertex=d;
	q->next=NULL;
	if(graph[s]==NULL){
		graph[s]=q;
	}else{
		p=graph[s];
		while(p->next!=NULL)
			p=p->next;
		p->next=q;
	}
	printf("After inserting edge the adjacency list is : \n");
	print(N);
}

void deleteVertex(int *N){
	int v,i;
	GNODE temp,prev,p;
	printf("Enter the vertex to be deleted : ");
	scanf("%d",&v);
	if(v>*N||v<=0){
		printf("Invalid vertex.\n");
		return;
	}
	temp=graph[v];
	while(temp!=NULL){
		p=temp;
		temp=temp->next;
		free(p);
	}
	graph[v]=NULL;

	for(i=1;i<=*N;i++){
		if(graph[i]!=NULL){
			p=graph[i];
			prev=NULL;
			while(p!=NULL){
				if(p->vertex==v)
				{
					if(prev==NULL){
					graph[i]=p->next;
				}else{
					prev->next=p->next;
				}
				free(p);
				break;
				}
				prev=p;
				p=p->next;
			}
		}
	}
	printf("After deleting vertex the adjacency list is : \n");
	print(N);
}

void deleteEdge(int *N){
	int s,d;
	GNODE p,prev;
	printf("Enter the source vertex of the edge : ");
	scanf("%d",&s);
	printf("Enter the destination vertex of the edge : ");
	scanf("%d",&d);
if(s>*N||d>*N||s<=0||d<=0||graph[s]==NULL){
		printf("Invalid edge.\n");
		return;
	}
	p=graph[s];
	prev=NULL;
	while(p!=NULL&&p->vertex!=d){
		prev=p;
		p=p->next;
	}
	if(p==NULL){
		printf("Edge not found.\n");
		return;
	}
	if(prev==NULL){
		graph[s]=p->next;
	}else{
		prev->next=p->next;
	}
	free(p);
	printf("After deleting edge the adjacency list is : \n");
	print(N);
}

void print(int *N){
	for(int i=1;i<=*N;i++){
		if(graph[i]!=NULL){
			printf("%d=>",i);
			GNODE temp=graph[i];
			while(temp!=NULL){
				printf("%d\t",temp->vertex);
				temp=temp->next;
			}
			printf("\n");
		}
	}
}
