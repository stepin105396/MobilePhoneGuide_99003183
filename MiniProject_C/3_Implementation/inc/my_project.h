/**
* @file my_project.h
*
*/
#ifndef __MY_PPROJECT_H__
#define __MY_PPROJECT_H__

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/**
* Checks if the entered login credentials are correct
* @param[in] nm
* @param[in] pswrd
* @return 1 if correct and 0 if either of them are wrong
*/
int admin();

/**
* Checks if there is any mobile with a particular processor p
* @param[in] p
* @return Mobile name if found
*/
char *a_mobiledetails(int p);

/**
* Checks if there are any mobiles from the brand
* @param[in] brand
* @return number of mobiles from the brand
*/
int showdeviceno(char brand[10]);

/**
* Check the number of mobiles having battery capacity >= b
* @param[in] b
* @return number of mobiles with battery capacity >= b
*/
int devicebattery(int b);

#endif /* #ifndef __MY_PPROJECT_H__ */
