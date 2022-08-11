#Use to compile program and run
all:
	make One_time_pad && make run
#Use to compile	
One_time_pad:
	gcc -Wall -ansi -pedantic -o One_time_pad One_time_pad.c
#Use to run executable	
run:
	./One_time_pad
#Use to delete executable	
clean:
	rm One_time_pad