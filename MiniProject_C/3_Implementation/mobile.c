#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Admin();
int insideAdmin();
void Customer();
void showall();
void showdevicelist();
void a_mobiledetails();

struct
{
  char mbrand[15];
  char mname[15];
  char mram[10];
  char mrom[13];
  char mprocessor[15];
  int mbattery;
  char mdisplay[10];
  float msize;
}mp;

//initializing the file used in the program
FILE *databook;

int main()
{
	int choice;
	printf("\n\t\t\t\t---Mobile Phone Guide by Akshay Sai Reddy G---\n");
    do
	{
   		printf("\n\tWho are you?");
		printf("\n 1. Admin\n 2. Customer \n 0. Exit the program\n\t Enter your choice : ");
    	scanf("%d",&choice);
    	switch(choice)
    	{
        	case 1:Admin();
            		break;
        	case 2:Customer();
            		break;
        	case 0:break;
        	default:
            	printf("\n ! Invalid Choice...Please select a valid option\n");
    	}
	}while(choice!=0);
 return 0;
}

//Only Admin can login to change mobile details
void Admin()
{
	char c, adminname[15], password[15];
	printf("\n\tEnter your login details\n");
	printf("Name	 : ");
	scanf("%s",adminname);
	printf("Password : ");
	scanf("%s",password);
	char admnm[15]="akshaysai",pass[15]="akshay";
	if((strcmp(adminname,admnm)==0)&&(strcmp(password,pass)==0))
	{
			insideAdmin();
	}
	else printf("\n\tSorry.Incorrect Login details\n");
}

//function to add a new Mobile Phone
int insideAdmin()
{
	int i,j;
	printf("\n\tWant to add a Mobile Phone?\n1. Yes\n0. No\n\tEnter your choice : ");
	scanf("%d",&i);
	if(i==1)
	{
    	//opening the databook file
    	databook = fopen("databook.txt","a+");
    	//adding a new device and it's deatils
    	printf("Enter the Brand Name : ");
       		scanf("%s",mp.mbrand);
    	printf("Model Name : ");
	   		scanf("%s",mp.mname);
   		printf("RAM : ");
	   		scanf("%s",mp.mram);
    	printf("ROM : ");
			scanf("%s",mp.mrom);
       	printf("Processor : ");
    		scanf("%s",mp.mprocessor);
       	printf("Battery	: ");
      		scanf("%d",&mp.mbattery);
    	printf("Display type : ");
     		scanf("%s",mp.mdisplay);
    	printf("Display Size : ");
       		scanf("%f",&mp.msize);
    	fprintf(databook,"\n%s\t%s\t%s\t%s\t%s\t%d\t%s\t%d",mp.mbrand,mp.mname,mp.mram,mp.mrom,mp.mprocessor,mp.mbattery,mp.mdisplay,mp.msize);
   		fclose(databook);
   		printf("\n\t\tNew Mobile Phone has been Added Successfully\n");
	}
	printf("\n\tWant to logout?\n1. Yes\n0. No\n\tEnter your choice : ");
	scanf("%d",&j);
	if(j==1) return 0;
	else insideAdmin();
}

void Customer()
{
	int s;
	printf("\n\t\tWelcome to the service\n");
	do{
		printf("\n1. List of all Mobile Phones\n2. Show details of all mobiles\n0. Back\n");
		printf("\tEnter your choice : ");
		scanf("%d",&s);
		switch(s)
		{
			case 1:showdevicelist();
					break;
			case 2:showall();
					break;
			case 0:break;
			default:printf("\n ! Invalid Choice...Please select a valid option\n");
		}
	}while(s!=0);
}

void showdevicelist()
{
	int i=0,d;
    databook = fopen("databook.txt","a+");
    printf("\nList of all Mobile Phones\n");
    while(!feof(databook))
    {
    	++i;
    	fscanf(databook,"%s%s%s%s%s%d%s%f",mp.mbrand,mp.mname,mp.mram,mp.mrom,mp.mprocessor,&mp.mbattery,mp.mdisplay,&mp.msize);
    	printf("%d.	%s %s\n",i,mp.mbrand,mp.mname);
    };
    fclose(databook);
    printf("\n1. Show details of a mobile\n0. Back\n\tEnter your choice : ");
    scanf("%d",&d);
    switch(d)
    {
    	case 1:a_mobiledetails();
    			break;
    	case 0:break;
    	default:
    		printf("\n ! Invalid Choice...Please select a valid option\n");
	}
}

void showall()
{
	int i=0;
    databook = fopen("databook.txt","a+");
    printf("\nList of all Mobile Phones\n");
    printf("Sl.No\tMobile name\tRAM(GB)\tROM(GB)\tProcessor\tBattery(mAh)\tDisplay type\tDisplay Size\n");
    while(!feof(databook))
    {
    	++i;
    	fscanf(databook,"%s%s%s%s%s%d%s%f",mp.mbrand,mp.mname,mp.mram,mp.mrom,mp.mprocessor,&mp.mbattery,mp.mdisplay,&mp.msize);
    	printf("%d.\t%s\t%s\t%s\t%s\t%s\t\t%d\t\t%s\t\t%.2f inches\n",i,mp.mbrand,mp.mname,mp.mram,mp.mrom,mp.mprocessor,mp.mbattery,mp.mdisplay,mp.msize);
    }
    printf("\n\tNote:\n\tSd means Snapdragon\n\tExy means Exynos\n");
    fclose(databook);

}

void a_mobiledetails()
{
    int i;char a[15],b[15];
	printf("\nEnter the Mobile name : ");
    scanf("%s%s",a,b);
    databook = fopen("databook.txt","a+");
    while(!feof(databook))
    {
    	fscanf(databook,"%s%s%s%s%s%d%s%f",mp.mbrand,mp.mname,mp.mram,mp.mrom,mp.mprocessor,&mp.mbattery,mp.mdisplay,&mp.msize);
    	if((strcmp(a,mp.mbrand)==0)&&(strcmp(b,mp.mname)==0))
    	{

    		printf("\n\tMobile name\tRAM(GB)\tROM(GB)\tProcessor\tBattery(mAh)\tDisplay type\tDisplay Size\n");
    		printf("\t%s\t%s\t%s\t%s\t%s\t\t%d\t\t%s\t\t%.2f inches\n",mp.mbrand,mp.mname,mp.mram,mp.mrom,mp.mprocessor,mp.mbattery,mp.mdisplay,mp.msize);

	}	}
	fclose(databook);
	printf("\n1. Show details of another mobile\n0. Back\n\tEnter your choice : ");
	scanf("%d",&i);
	switch(i)
    {
    	case 1:a_mobiledetails();
    			break;
    	case 0:break;
    	default:
    		printf("\n ! Invalid Choice...Please select a valid option\n");
	}
}
