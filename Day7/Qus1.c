#include<stdio.h>
#include<time.h>
#include<limits.h>
void dijkstra(int n,int graph[n][n],int start){
int dist[n];
int visited[n];
int parent[n];
for(int i=0;i<n;i++){
dist[i]=INT_MAX;
visited[i]=0;
parent[i]=-1;}
dist[start]=0;
for(int count=0;count<n-1;count++){
int min=INT_MAX;
int u=-1;
for(int i=0;i<n;i++){
if(visited[i]==0 && dist[i]<min){
min=dist[i];
u=i;}}
if(u==-1){
break;}
visited[u]=1;
for(int v=0;v<n;v++){
if(visited[v]==0&&graph[u][v]!=0&&dist[u]!=INT_MAX&&dist[u]+graph[u][v]<dist[v]){
dist[v]=dist[u]+graph[u][v];
parent[v]=u;}}}
printf("\nSource\tDestination\tCost\tPath\n");
for(int i=0;i<n;i++){
printf("%d\t%d\t\t",start+1,i+1);
if(dist[i]==INT_MAX){
printf("INF\tNo Path\n");}
else{
printf("%d\t",dist[i]);
int path[n];
int count=0;
int current=i;
while(current!=-1){
path[count++]=current;
current=parent[current];}
for(int j=count-1;j>=0;j--){
printf("%d",path[j]+1);
if(j!=0){
printf("->");}}
printf("\n");}}}
int main(){
clock_t start,end;
start=clock();
FILE *fp=fopen("inDiAdjMat.dat","r");
if(fp==NULL){
printf("Error: Unable to open input file\n");
return 1;}
int n;
fscanf(fp,"%d",&n);
int graph[n][n];
printf("Enter the Source Vertex: ");
int j;
scanf("%d",&j);
j--;
for(int a=0;a<n;a++){
for(int b=0;b<n;b++){
fscanf(fp,"%d",&graph[a][b]);}}
fclose(fp);
dijkstra(n,graph,j);
end=clock();
printf("\nCPU Execution Time: %.5f\n",(double)(end-start)/CLOCKS_PER_SEC);
return 0;}