#Jesus Minjares
CC = g++
MAIN = assignment_one
FUNC = function
RESULT = main 

$(RESULT):	$(FUNC).o $(MAIN).o 
	$(CC) $(FUNC).o $(MAIN).o -o $(RESULT)
$(FUNC).o:	$(FUNC).cpp
	$(CC)	-c $(FUNC).cpp
$(MAIN).o:	$(MAIN).cpp
	$(CC) -c $(MAIN).cpp 
clean:
	rm *.o *.txt $(RESULT)