#include<stdio.h>
#include<string.h>
#define I 9999
int n, g[10][10];
int i,j;
char loc[10][50];
int dist[10],visit[10],par[10],source=-1;
void enterGraph(){
    int edges,w,p,q;
    char u[50], v[50];
    printf("Enter no. of locations: ");
    scanf("%d",&n);
    printf("Enter locations:\n");
    for(i=0;i<n;i++)
        scanf("%s",loc[i]);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j)
                g[i][j]=0;
            else
                g[i][j]=I;
        }
    }
    printf("Enter no. of edges: ");
    scanf("%d",&edges);
    for(i=0;i<edges;i++){
        printf("Enter from: ");
        scanf("%s",u);

        p=-1;
        for(j=0;j<n;j++){
            if(strcmp(u,loc[j])==0){
                p=j;
                break;
            }
        }
        printf("Enter to: ");
        scanf("%s",v);
        q=-1;
        for(j=0;j<n;j++){
            if(strcmp(v,loc[j])==0){
                q=j;
                break;
            }
        }
        printf("Enter distance :");
        scanf("%d",&w);
        if(p!=-1&&q!=-1){
            g[p][q]=w;
            g[q][p]=w;
        }
        else
            printf("Invalid location\n");
    }
    source=-1;
    printf("Campus graph entered successfully\n");
}
void displayMatrix(){
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(g[i][j]==I)
                printf("INF\t");
            else
                printf("%d\t",g[i][j]);
        }
        printf("\n");
    }
}
void selectSource(){
    char s[50];
    printf("Enter source location: ");
    scanf("%s",s);
    source=-1;
    for(i=0;i<n;i++){
        if(strcmp(s,loc[i])==0){
            source=i;
            break;
        }
    }
    if(source==-1)
        printf("Invalid location\n");
    else
        printf("Source selected: %s\n",loc[source]);
}
void dijkstra(){
    int z,min;
    if(source==-1){
        printf("Select source\n");
        return;
    }
    for(i=0;i<n;i++){
        dist[i]=I;
        visit[i]=0;
        par[i]=-1;
    }
    dist[source]=0;
    for(i=0;i<n-1;i++){
        min=I;
        z=-1;
        for(j=0;j<n;j++){
            if(visit[j]==0&&dist[j]<min){
                min=dist[j];
                z=j;
            }
        }
        if(z==-1)
            break;
        visit[z]=1;
        for(j=0;j<n;j++){
            if(visit[j]==0 &&g[z][j]!=I&&dist[z]+g[z][j]<dist[j]){
                dist[j]=dist[z]+g[z][j];
                par[j]=z;
            }
        }
    }
    printf("Shortest distance calculated\n");
}
void printPath(int v){
    if(v==-1)
        return;
    printPath(par[v]);
    if(v!=source)
        printf(" -> ");

    printf("%s",loc[v]);
}
void displayPaths(){
    if(source==-1){
        printf("Select source\n");
        return;
    }
    printf("Shortest paths from %s:\n",loc[source]);
    for(i=0;i<n;i++){
        if(dist[i]==I)
            printf("%s:Unreachable \n",loc[i]);
        else{
            printf("%s: ",loc[i]);
            printPath(i);
            printf("\n");
        }
    }
}
void displayDistances(){
    if(source==-1){
        printf("Select source first\n");
        return;
    }
    printf("Shortest distances from %s:\n",loc[source]);
    for(i=0;i<n;i++){
        if(dist[i]==I)
            printf("%s: Unreachable\n",loc[i]);
        else
            printf("%s: %d\n",loc[i],dist[i]);
    }
}
int main(){
    int ch;
    printf("\nMENU");
    printf("\n1-ADD CAMPUS GRAPH");
    printf("\n2-DISPLAY MATRIX");
    printf("\n3-SELECT SOURCE");
    printf("\n4-FIND SHORTEST DISTANCE");
    printf("\n5-DISPLAY SHORTEST PATHS");
    printf("\n6-DISPLAY ALL DISTANCES");
    printf("\n7-EXIT");
    while(1){
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        if(ch==7)
            break;
        switch(ch){
            case 1:{
                enterGraph();
                break;
            }
            case 2:{
                displayMatrix();
                break;
            }
            case 3:{
                selectSource();
                break;
            }
            case 4:{
                dijkstra();
                break;
            }
            case 5:{
                displayPaths();
                break;
            }
            case 6:{
                displayDistances();
                break;
            }
            default:{
                printf("Invalid choice");
                break;
            }
        }
    }
    return 0;
}
