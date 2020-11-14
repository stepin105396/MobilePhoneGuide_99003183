#include "my_project.h"
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct
{
  char mbrand[25];
  char mname[15];
  char mram[10];
  char mrom[13];
  char mprocessor[15];
  int mbattery;
  char mdisplay[10];
  float msize;
}mp;
FILE *databook;
int admin(char *nm,char *pswrd)
{
    char admnm[15]="akshaysai",pass[15]="akshay";
    if((strcmp(nm,admnm)==0)&&(strcmp(pswrd,pass)==0))
        return 1;
    else
        return 0;
}

char *a_mobiledetails(int p)
{
    int d=0,i,j=0;
    databook = fopen("databook.txt","r");
    while(!feof(databook))
    {
    	fscanf(databook,"%s%s%s%s%s%d%s%f",mp.mbrand,mp.mname,mp.mram,mp.mrom,mp.mprocessor,&mp.mbattery,mp.mdisplay,&mp.msize);
    	for(i=0;i<strlen(mp.mprocessor);++i)
        {
            j=mp.mprocessor[i]-'0';
            if((j>=0)&&(j<=9))
                d=d*10+j;
		}
		if(p==d)
        {
            fclose(databook);
            return mp.mname;
		}d=0;
	}
	fclose(databook);
	return "0";
}

int showdeviceno(char brand[10])
{
	int i=0,count=0;
    databook = fopen("databook.txt","a+");
    while(!feof(databook))
    {
    	fscanf(databook,"%s%s%s%s%s%d%s%f",mp.mbrand,mp.mname,mp.mram,mp.mrom,mp.mprocessor,&mp.mbattery,mp.mdisplay,&mp.msize);
    	//strcat(mp.mbrand,mp.mname);
    	if(strcmp(brand,mp.mbrand)==0)
    		++count;
    	++i;
    };
    fclose(databook);
	return count;
}
int devicebattery(int b)
{
    int count=0;
    databook = fopen("databook.txt","a+");
    while(!feof(databook))
    {
    	fscanf(databook,"%s%s%s%s%s%d%s%f",mp.mbrand,mp.mname,mp.mram,mp.mrom,mp.mprocessor,&mp.mbattery,mp.mdisplay,&mp.msize);
    	if(mp.mbattery>=b)
    		++count;
    };
    fclose(databook);
	return count;
}

