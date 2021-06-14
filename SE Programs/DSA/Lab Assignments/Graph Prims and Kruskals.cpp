 #include<iostream>
using namespace std;

// class for performing Prim's Algorithm
class Prims 
{
    public:
    int V;
    void display(int[20][20]);
    int min_Key(int[20], bool[20]);
    void find_MST(int[20][20]);
    int print_MST(int[20], int[20][20]);
};

// Function to display the adjecency matrix
void Prims :: display(int cost[20][20])
{
    cout<<"\nAdjecency Matrix: "<<endl;
    for (int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
			cout<<cost[i][j]<<"  ";
        }
        cout<<endl;
    }
}
 
int Prims :: min_Key(int key[20], bool visited[20])  
{ 
    int min = 999, min_index;

    for (int v = 0; v < V; v++) 
    {   
        if (visited[v] == false && key[v] < min) 
        {	
            min = key[v];
			min_index = v;  
        }
    }    
    return min_index;  
}  

// Function to print the MST
int Prims :: print_MST(int parent[20], int cost[20][20])  
{  
    int minCost=0;
	cout<<"Edge \t  Cost\n";  
    for (int i = 1; i< V; i++)
	{
	    cout<<parent[i]<<" - "<<i<<" \t"<<cost[i][parent[i]]<<" \n";  
		minCost += cost[i][parent[i]];
    }
	cout<<"Minimum cost of MST by Prim's Algorithm is "<<minCost;
}  

// Function to find the MST using Prim's Algorithm
void Prims :: find_MST(int cost[20][20])  
{  
    int parent[20], key[20];
    bool visited[20];

    // Initialize all the arrays 
    for (int i = 0; i< V; i++) { 
        key[i] = 999;
        visited[i] = false;
        parent[i]=-1;
    }    

    key[0] = 0;   
    parent[0] = -1;  

    for (int x = 0; x < V - 1; x++) 
    {  
        int u = min_Key(key, visited);  
        visited[u] = true;
        for (int v = 0; v < V; v++)  
        {
            if (cost[u][v]!=0 && visited[v] == false && cost[u][v] < key[v])
            {  
                parent[v] = u;
                key[v] = cost[u][v];  
            }        
        }
    }

    // print the final MST  
	print_MST(parent, cost);  
} 

//class for performing Kruskal's Algorithm
class Kruskals
{
    public:
    int V;
    int parent(int, int[20]);
    void update_parent(int, int, int[20]);
    void find_MST(int[20][20]);
};

int Kruskals :: parent(int v,int p[20])
	{
    	if(v==p[v])
    	{
    		return v;
    	}
		return parent(p[v],p);
    }
    
void Kruskals :: update_parent(int v2,int v1,int p[20])
{
	while(1)
	{
  		if(p[v2]==v2)
  		{
			p[v2]=v1;
			break;
  		}
		else
		{
  			v2=p[v2];
		}
    }
}

// Function to find the MST using Kruskal's Algorithm
void Kruskals :: find_MST(int G[20][20])
{
  	int i,j,R[20][20],p[20];
  	int v1,v2,cost,min,count=1;
  	int total=0;
  	
	for(i=0;i<V;i++)
	{
	    p[i]=i;
	}

	for(i=0;i<V;i++)
  	{
  		for(j=0;j<V;j++)
  		{
			if(G[i][j]==0)
  			{
  				R[i][j]=999;
  			}
  			else
  			{
  				R[i][j]=G[i][j];
  			}
  		}
  	}

    cout<<"Edge \t  Cost\n";
	while(count<V)
	{
		min=999;
		for(i=0;i<V;i++)
		{
			for(j=0;j<V;j++)
			{
				if(min>R[i][j])
				{
					min=R[i][j];
  					v1=i;
  					v2=j;
				}
			}
		}

		if(parent(v1,p)!=parent(v2,p))
		{	
			cout<<v1<<" - "<<v2<<" \t"<<min<<endl;
  			total=total+min;
  			update_parent(v2,v1,p);
			R[v1][v2]=999;
			R[v2][v1]=999;
			count++;	
		}
		else
		{
			R[v1][v2]=999;
			R[v2][v1]=999;
		}
	}
  	cout<<"\nMinimum cost of MST by Kruskal's Algorithm is "<<total<<"\n";
}

int main()  
{  
    Prims P;
    Kruskals K;
    int V, v1, v2, c, e;
    int ch = 1;
    do
    {
        cout<<"Enter number of vertices: ";
        cin>>V;
        int cost[20][20];
        P.V = V;
        K.V = V;
        cout<<"Enter number of edges: ";
        cin>>e;
        for(int i=0; i<V; i++)
        {
            for(int j=0; j<V; j++)
            {
                cost[i][j] = 0;     //Initialize cost matrix
            }
        }
        for(int i=0; i<e; i++)
        {
            cout<<"Enter source, destination and cost respectively: ";
            cin>>v1>>v2>>c;
            
            cost[v1][v2] = c;
            cost[v2][v1] = c;
        }
        P.display(cost);
        cout<<"\nUsing Prim's Algorithm: "<<endl;
    	P.find_MST(cost);  
    	cout<<"\n\nUsing Kruskal's Algorithm: "<<endl;
    	K.find_MST(cost);
    	
    	cout<<"Do you want to continue? (0/1) ";
    	cin>>ch;
    	
    }while(ch != 0);

    return 0;  
}  
