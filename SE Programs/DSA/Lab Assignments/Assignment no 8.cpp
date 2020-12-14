#include<iostream>
using namespace std;

class DijAlgo 
{
    public:
    void display(int[10][10], int);
    void getdata(int[10][10], int, int);
};

void DijAlgo :: display(int G[10][10], int n)
{
    cout<<"\nAdjecency Matrix: "<<endl;
    for (int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
			cout<<G[i][j]<<"  ";
        }
        cout<<endl;
    }
}

void DijAlgo :: getdata(int G[10][10], int n, int source) 
{
    int cost[10][10], dist[10], pred[10];
    int visited[10], count, min, next;
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(G[i][j] == 0)
            {
                cost[i][j] = 999;
            }
            else
            {
                cost[i][j] = G[i][j];
            }
            
        }
        
    }
    for(i=0; i<n; i++)
    {
        dist[i] = cost[source][i];
        pred[i] = source;
        visited[i] = 0;
    }
    dist[source] = 0;
    visited[source] = 1;
    count = 1;
    
    while(count<n-1) 
    {
        
        min = 999;
        for(i=0; i<n; i++)
        {
           if(dist[i]<min && !visited[i]) 
           {
                min = dist[i];
                next = i;
           }
        }
        visited[next]=1;
        
        for(i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(min + cost[next][i] < dist[i]) 
                {
                    dist[i] = min + cost[next][i];
                    pred[i] = next;
                }
            }
        }
        count++;
    }    
    for(i=0; i<n; i++)
    {
        if(i != source) 
        {
            cout<<"\nDistance of node "<<i<<" = "<<dist[i];
            cout<<"\nPath = "<<i;
            j=i;
            do 
            {
               j=pred[j];
               cout<<"<-"<<j;
               
            }while(j!=source);
        }
    }
}
    
int main() 
{
    int G[10][10];
    int n, e, v1, v2, c, choice;
    do
    {
        cout<<"Enter number of vertices: ";
        cin>>n;
        cout<<"Enter number of edges: ";
        cin>>e;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                G[i][j] = 0;
            }
        }
        for(int i=0; i<e; i++)
        {
            cout<<"Enter source, destination and distance respectively: ";
            cin>>v1>>v2>>c;
            
            G[v1][v2] = c;
            G[v2][v1] = c;
        }
        
        DijAlgo D;
        
        D.display(G, n);
        int s, ch;
        do
        {
            cout<<"\nEnter source: ";
            cin>>s;
            D.getdata(G, n, s);
            cout<<"\nInput another source? (1/0) ";
            cin>>ch;
        }while(ch != 0);
        
        cout<<"\nDo you want to continue? (1/0) ";
        cin>>choice;
    }while(choice != 0);
    
    cout<<"\nDone!!"<<endl;

    return 0;
}
