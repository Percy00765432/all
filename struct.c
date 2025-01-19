#include<stdio.h>
struct student
{
char name[10]; 
int roll;
};
void main()
{
struct student s1;
 
printf("\n Enter student record"); 
printf("\n student name\t");
scanf("%s",s1.name); 
printf("\nEnter student roll\t"); 
scanf("%d",&s1.roll);
  printf("\n Student detail is \n");
  printf("\nstudent name is %s",s1.name);
   printf("\nroll is %d",s1.roll);
}

