
# Default student ID
ID = 2016-11111
NAME = Student

CXX_OPTS=-O0 -g

%.o: %.c
	$(CXX) $(CXX_OPTS) -Wall -c -o $@ $<

all: hdd.o driver.o
	$(CXX) $(CXX_OPTS) -Wall -o disklab $^

handin:
	mkdir -p $(ID)
	touch $(ID)/STUDENT.INFO
	echo "Created by: $(NAME) ($(ID))" > $(ID)/STUDENT.INFO
	date >> $(ID)/STUDENT.INFO
	cp disk.h driver.cpp hdd.h hdd.cpp $(ID)
	tar cvzf $(ID).tgz $(ID)

clean:
	rm -f *.o disklab

