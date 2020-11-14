* Here, mobile.c is my project without unit testing. On compiling and running this file, it will ask for login credentials for a step. Enter "akshaysai" and "akshay" for name and password respectively.
* databook.txt is a must required file to run this project successfully. It contains all the data required for the project. So, please be careful when changing the contents of file.
* main_project.c contains the main function of this unit testing.

On running the Makefile:
1. make all: It compiles all the files related to the Project
2. make test: It runs all the test cases and returns PASS/FAIL 
3. make run: It executes the mobile.c project file
4. make doc: It runs Doxyfile & Makefile under documentation folder
5. make clean: It deletes all the files created on running the above make commands
