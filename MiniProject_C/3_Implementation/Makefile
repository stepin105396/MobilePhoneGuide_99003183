PROJECT_NAME = MOBILEPHONE

BUILD=build

SRC = unity/unity.c\
src/my_project.c\
test/test_project.c\
main_project.c


#PROJECT_OUTPUT=$(BUILD)/Test_$(PROJECT_NAME)

INC = -Iunity\
-Iinc\
-Itest

PROJECT_NAME1 = MOBILEPHONE.out

all=$(PROJECT_NAME)

all: $(SRC)
	gcc $(SRC) $(INC) -o $(PROJECT_NAME).out

run:$(PROJECT_NAME1)
	./${PROJECT_NAME1}

doc:
	make -C ./documentation

clean:
	rm -rf $(PROJECT_NAME) documentation/html
