#include <stdio.h>
#include <stdlib.h>
void print(int t[], int n)
{
int trm = 0;
printf("\n");
for (int i = 0; i < n; i++)
{
if (i != 0)
{
printf("->%d", t[i]);
trm = trm + abs(t[i] - t[i - 1]);
}
else
{
printf("%d", t[i]);
}
}
printf("\nTotal number of track movements : %d", trm);
printf("\nAverage seek time : %d\n\n", trm/n);
}
void fcfs(int q[], int tn, int h, int n)
{
int th = 0, trm[100], j = 0;
trm[j++] = h;
for (int i = 0; i < n; i++)
{
trm[j++] = q[i];
}
print(trm, j);
}
int visited(int a[], int n)
{
int c=0;
for(int i=0;i<n;i++)
{
if(a[i]==1)
{
    c=c+1;
}
}
if(c==n)
{
    return 1;
}
else
{
    return 0;
}
}
void sstf(int q[], int tn, int h, int n, int vis[])
{
int j=0, res[100],pos;
res[j++]=h;
while(visited(vis,n)==0)
{
int min = 999999999,temp;
for(int i=0;i<n;i++)
{
if(abs((q[i])-h)<min && vis[i]==0)
{
min = abs((q[i])-h);
pos=i;
temp=q[i];
}
}
h=temp;
vis[pos]=1;
res[j++]=temp;
}
print(res,j);
}
void scan(int q[], int tn, int h, int n)
{
int trm[200], j = 0, tb[200], b = 0;
trm[j++] = h;
for (int i = 0; i < n; i++)
{
if (q[i] >= h)
{
trm[j++] = q[i];
}
else
{
tb[b++] = q[i];
}
}
trm[j++] = tn - 1;
for (int i = b - 1; i >= 0; i--)
{
trm[j++] = tb[i];
}
print(trm, j);
}
void look(int q[], int tn, int h, int n)
{
int trm[200], j = 0, tb[200], b = 0;
trm[j++] = h;
for (int i = 0; i < n; i++)
{
if (q[i] >= h)
{
trm[j++] = q[i];
}
else
{
tb[b++] = q[i];
}
}
for (int i = b - 1; i >= 0; i--)
{
trm[j++] = tb[i];
}
print(trm, j);
}
void cscan(int q[], int tn, int h, int n)
{
int trm[200], j = 0, tb[200], b = 0;
trm[j++] = h;
for (int i = 0; i < n; i++)
{
if (q[i] >= h)
{
trm[j++] = q[i];
}
else
{
tb[b++] = q[i];
}
}
trm[j++] = tn - 1;
trm[j++] = 0;
for (int i = 0; i < b; i++)
{
trm[j++] = tb[i];
}
print(trm, j);
}
void main()
{
int n,queue[50];
printf("Enter the number of Requests:");
scanf("%d",&n);    
printf("Enter Requests:");
for(int i=0;i<n;i++)
{
    scanf("%d",&queue[i]);
}
int vis[100];
for (int i=0;i<n;i++)
{
    vis[i]=0;
}
int trackno;
printf("Enter the total tracks:");
scanf("%d",&trackno);
int head , t;
printf("Enter Head:");
scanf("%d",&head);
printf("Request : ");
for(int i =0;i<n;i++)
{
    printf("%d, ",queue[i]);
}
printf("\nHead : %d\nTotal Tracks : %d \nScheduling algorithms ->\n",head,trackno);
printf("FCFS : ");
fcfs(queue, trackno, head, n);
for (int i = 0; i < n - 1; i++)
{
for (int j = 0; j < n - 1; j++)
{
if (queue[j] > queue[j + 1])
{
t = queue[j];
queue[j] = queue[j + 1];
queue[j + 1] = t;
}
}
}
printf("SSTF : ");
sstf(queue, trackno, head, n, vis);
printf("SCAN : ");
scan(queue, trackno, head, n);
printf("CSCAN :");
cscan(queue, trackno, head, n);
printf("LOOK :");
look(queue, trackno, head, n);
}
