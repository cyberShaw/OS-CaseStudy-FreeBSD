#include<stdio.h>
#include<conio.h>
 
struct proc
{
 int arr_time;
 int burst_time;
 int no;
 int rem_time;
 int priority;
};
 
 
struct proc read(int i)
{
 struct proc p;
 printf("\n\n The process no.:%d.\n",i);
 p.no=i;
 printf("Enter the arrival time:");
 scanf("%d",&p.arr_time);
 printf("Enter the burst time:");
 scanf("%d",&p.burst_time);
 p.rem_time=p.burst_time;
 return p;
}
 
 
 
struct proc readp(int i)
{
 struct proc p;
 printf("\n\n The process no.:%d.\n",i);
 p.no=i;
 printf("Enter the arrival time:");
 scanf("%d",&p.arr_time);
 printf("Enter the burst time:");
 scanf("%d",&p.burst_time);
 p.rem_time=p.burst_time;
 printf("Enter the priority:");
 scanf("%d",&p.priority);
 return p;
}
 
 
 
void swap(struct proc *pi, struct proc *pj)
{
 struct proc *temp;
 temp = pi;
 pi = pj;
 pj = temp;
}
 
 
int main()
{
 int  n;        
 struct proc p[10],tmp;     
 int i,j;
 printf("Enter the number if processes you want to enter:");
 scanf("%d",&n);       
 
 
 for(i=0;i<n;i++)
  p[i]=read(i);      
 
 
 
 for(i=0;i<n-1;i++)
  for(j=0;j<n-1-i;j++)    
  {
   if(p[j].arr_time>p[j+1].arr_time)
     
   {
    tmp=p[j];
    p[j]=p[j+1];
    p[j+1]=tmp;
   }
  }
 for(i=0;i<n;i++)
  printf("%d ",p[i].no); 
    getch();    
 return 0;
}
 