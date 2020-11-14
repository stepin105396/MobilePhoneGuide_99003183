SRC = unity/unity.c\
src/my_project.c\
test/test_project.c\
main_project.c

INC = -Iunity\
-Iinc\
-Itest

PROJECT_NAME = MOBILEPHONE.out

$(PROJECT_NAME): $(SRC)
	gcc $(SRC) $(INC) -o $(PROJECT_NAME)

run:$(PROJECT_NAME)
	./${PROJECT_NAME}
doc:
	make -C documentation

clean:
	rm -rf $(PROJECT_NAME) documentation/html
