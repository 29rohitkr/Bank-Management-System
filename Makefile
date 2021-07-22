OBJECT_FILES = ./build/error.o ./build/bank.o ./build/account.o

system: ${OBJECT_FILES}
./build/account.o: ./source/account.cpp
	g++ ./source/account.cpp -o ./build/account.o -c
./build/bank.o: ./source/bank.cpp
	g++ ./source/bank.cpp -o ./build/bank.o -c
./build/error.o: ./source/error.cpp
	g++ ./source/error.cpp -o ./build/error.o -c

all: system
	g++ ./source/main.cpp ${OBJECT_FILES} -o ./main

clean:
	rm ${OBJECT_FILES}
