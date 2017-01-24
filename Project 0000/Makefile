# Makefile for set
#****************************************************************

CPPOPTIONS = -std=c++11 -g
LDOPTIONS = 

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: test_set presidents

test_set: set.h set.cpp test_set.cpp
	g++ $(CPPOPTIONS) -o test_set test_set.cpp

presidents: set.h set.cpp presidents.cpp
	g++ $(CPPOPTIONS) -o presidents presidents.cpp

# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean: tidy
	rm -f *.o
