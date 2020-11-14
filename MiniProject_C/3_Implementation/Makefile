PROJECT_NAME = MOBILEPHONE

BUILD=build

SRC = unity/unity.c\
src/my_project.c\
test/test_project.c\
main_project.c

TEST_SRC = src/my_project.c\
test/test_project.c

INC = -Iunity\
-Iinc\
-Itest

PROJECT_NAME1 = MOBILEPHONE.out

all: $(SRC)
	gcc $(SRC) $(INC) -o $(PROJECT_NAME).out
	
run:	
	gcc mobile.c -o mobile
	./mobile

test:$(PROJECT_NAME1)
	./${PROJECT_NAME1}
	
doc:
	make -C ./documentation
	
clean:
	rm -rf $(PROJECT_NAME).out documentation/html mobile

