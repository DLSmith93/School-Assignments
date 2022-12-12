CC = g++
CPPFLAGS = -Wall -g -std=c++11

app:    app.o stack.o queue.o

stack.o:    queue.h stack.h

queue.o:    queue.h stack.h

.PHONY: clean
clean:      # clean the directory
	        $(info -- cleaning the directory -- )
	        rm -f *.o
	        rm -f app

