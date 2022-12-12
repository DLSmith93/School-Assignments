CC = g++
CPPFLAGS = -Wall -g -std=c++11
 
app:	app.o bst.o
 
bst.o:	bst.h

.PHONY: clean
clean:      # clean the directory
			$(info -- cleaning the directory -- )
			rm -f *.o
			rm -f app
