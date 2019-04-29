#include<stdio.h>
#include<conio.h>
#define initial 1
#define waiting 2
#define visited1 3
#define MAX 30
void DFS(int);
void BFS(int);
void socialfollowers();
void socialfriends();
int queue[MAX],front = -1,rear = -1;
void insert_queue(int);
int delete_queue();
int isEmpty_queue();
int g[MAX][MAX]={0},n;
int state[MAX];
int visited[MAX]={0};
int main()
{
    int ch,i;
    printf("\n 1) social followers");
    printf("\n 2) social friends");
    do
    {
        printf("\n enter your choice=");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            socialfollowers();
            printf("\nDFS traversal...");
            DFS(1);
            printf("\nBFS traversal...");
            BFS(1);
            break;
            case 2:
            socialfriends();
            printf("\nDFS traversal...");
            DFS(1);
            printf("\nBFS traversal...");
            BFS(1);
            break;
            default:
            printf("\n enter valid choice");
            break;
        }
    }while(ch==0);
}
void socialfollowers()
{
     FILE *f1;
    char fname[10];
    printf("Enter the name of social media graph file:");
    scanf("%s",fname);
    f1=fopen(fname,"r");
    int i,j,count1,count2[30],count,a[30],b[30];
    float ratio[30];
    printf("\n enter number of vertex=");
    scanf("%d",&n);
    //getw(f1);
    for(i=1;i<=n;i++)
                visited[i]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("\n enter g[%d][%d]=",i,j);
            scanf("%d",&g[i][j]);
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d \t",g[i][j]);
        }
        printf("\n");
    }
    for(i=1;i<=n;i++)
    {
        count1=0;
        a[i]=0;
        for(j=1;j<=n;j++)
        {
            if(g[i][j]==1)
            {
                count1++;
                a[i]++;
                printf("\n[%d] follows [%d]",i,j);

            }
        }
    }
    for(i=1;i<=n;i++)
    {
        count=0;
        b[i]=0;
        for(j=1;j<=n;j++)
        {
            if(g[j][i]==1)
            {
                count++;
                b[i]++;
                printf("\n [%d] followed by [%d]",i,j);

            }

        }
    }

    for(i=1;i<=n;i++)
    {
            ratio[i]=(float)b[i]/(float)a[i];
            // printf("\n popularity ratio of %d=%f",i,ratio[i]);
             if(ratio[i]>=2)
             {
                 printf("\n %d is popular =%f",i,ratio[i]);
             }
             else if(ratio[i]==0)
             {
                 ratio[i]=0;
                 printf("\n %d is not popular =%f",i,ratio[i]);

             }
             else
             {
                 printf("\n %d is not popular =%f",i,ratio[i]);
             }
    }
    fclose(f1);
}
void DFS(int i)
{
    int j;
	printf("\t%d",i);
    visited[i]=1;
    for(j=1;j<=n;j++)
    if(!visited[j]&&g[i][j]!=0)
        DFS(j);
}

void BFS(int v)
{
	int i;
	insert_queue(v);
	state[v] = 1;
	printf("%d ",v);
	while(!isEmpty_queue())
	{
		v = delete_queue( );

		for(i=1; i<=n; i++)
		{
			if(g[v][i] != 0 && state[i] == 0)
			{
				insert_queue(i);
				state[i] = waiting;
					printf("%d ",i);
			}
		}
	}
	printf("\n");
}
int isEmpty_queue()
{
	if(front == -1 || front > rear)
		return 1;
	else
		return 0;
}
void insert_queue(int n)
{
	if(rear == MAX-1)
		printf("Queue Overflow\n");
	else
	{
		if(front == -1)
			front = 0;
		rear = rear+1;
		queue[rear] = n;
	}
}
int delete_queue()
{
	int delete_item;
	if(front == -1 || front > rear)
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	delete_item = queue[front];
	front = front+1;
	return delete_item;
}
int FOF(int s)
{
	int friend[n],c=0,p=0,i,j,visit[50]={0};
	for(i=1;i<=n;i++)
	{
		visit[i]=0;
	}
	visit[s]=1;
	for(i=1;i<=n;i++)
	{
			if(g[s][i]!=0)
			{
				friend[p]=i;
				p++;
			}
	}
	for(i=1;i<p;i++)
	{
		for(j=1;j<n;j++)
		{
			if(g[friend[i]][j] != 0 && visit[j]==0)
			{
				visit[j]=1;
				c++;
			}
		}
	}
	return c;
}
void socialfriends()
{
    int max=0,count,count1,i,j,count2[20];
    FILE *f1;
    char fname[10];
    printf("Enter the name of social media graph file:");
    scanf("%s",fname);
    f1=fopen(fname,"r");
    printf("\n enter number of vertex=");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("\n enter g[%d][%d]=",i,j);
            scanf("%d",&g[i][j]);
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d \t",g[i][j]);
        }
        printf("\n");
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(g[i][j]==1)
            {
                printf("\n g[%d]->g[%d]",i,j);
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        count=0,count1=0;
        for(j=1;j<=n;j++)
        {
            if(g[j][i]==1)
            {
                count++;
            }
        }
        for(j=1;j<=n;j++)
        {
            if(g[i][j]==1)
            {
                count1++;
            }
        }
    }

    for(i=1;i<=n;i++)
    {
        count1=0;
        count2[i]=0;
        for(j=1;j<=n;j++)
        {
            if(g[i][j]!=0)
            {
            	if(max<g[i][j])
            		max=g[i][j];
                count1++;
                count2[i]++;
            }

        }
    	printf("\n friend of %d has %d friends  FOF= %d Oldest Friend=%d",i,count2[i],FOF(i),max);

	}
	fclose(f1);
}
