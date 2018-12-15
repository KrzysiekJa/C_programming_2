drzewo.exe: drzewo_main.o drzewoBTS.o
	gcc -o drzewo.exe drzewoBTS.o drzewo_main.o -Wall

drzewoBTS.o: drzewoBTS.c drzewoBTS.h 
	gcc -c drzewoBTS.c -Wall

drzewo_main.o: drzewo_main.c drzewoBTS.h 
	gcc -c drzewo_main.c -Wall
