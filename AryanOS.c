#include<stdio.h>    
#include<string.h>  //for strcpy
#include<conio.h>  //for getch()

void main()
{
  char p[10][5],swap[5];
  int i,j,n;
  int p_time[10],w_time[10],priority[10],swap1;
  int Total_wt=0;
  float Average_wt;
  printf("                          PROGRAM FOR PRIORITY BASED ROUND ROBIN SCHEDULING ALGORITHM\n");
  printf("                          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
  
  printf("Enter Total Number Of Processes  =>  ");
  scanf("%d",&n);
  printf("\n\n");
  
  for(i=0;i<n;i++)
  {
	printf("Enter Details Of Process %d :-\n",i+1);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Enter Process %d Name     => ",i+1);
    scanf("%s",&p[i]);
    printf("Enter Process %d Time     => ",i+1);
    scanf("%d",&p_time[i]);
    printf("Enter Process %d Priority => ",i+1);
    scanf("%d",&priority[i]);
    printf("\n\n");
  }
  
 for(i=0;i<n-1;i++)
 {
 for(j=i+1;j<n;j++)
 {
   if(priority[i]>priority[j])
 {
   //Swaping priority of process such that higher priority process comes befor lower priority process
   swap1=priority[i];
   priority[i]=priority[j];
   priority[j]=swap1;
   
   //Swapping process time
   swap1=p_time[i];
   p_time[i]=p_time[j];
   p_time[j]=swap1;
   
   //Swapping process name
   strcpy(swap,p[i]);
   strcpy(p[i],p[j]);
   strcpy(p[j],swap);
  }
  }
  }
  
  //we have already swapped the highest priority process to first so first waiting time will be zero
  w_time[0]=0;
  for(i=1;i<n;i++)
  {
   w_time[i] = w_time[i-1] + p_time[i-1];
   Total_wt = Total_wt + w_time[i];
  }  
  
Average_wt=(float)Total_wt/n;
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
printf("|   p_name   |\t p_time   |\t priority   |\t w_time   |\n");

for(i=0;i<n;i++)  
{
   printf("|   %s        |\t %d        |\t %d          |\t %d        |\n" ,p[i],p_time[i],priority[i],w_time[i]);
}
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("\n");
  printf("Total Waiting Time      =>  %d\n",Total_wt);
  printf("Average Waiting Time    =>  %f",Average_wt);
  getch();
}
