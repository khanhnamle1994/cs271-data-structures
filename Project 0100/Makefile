# Makefile for set
#****************************************************************

CPPOPTIONS = -std=c++11 -g
LDOPTIONS =

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: test_huffman

test_huffman: huffman.cpp node.h pq.h pq.cpp 
	g++ $(CPPOPTIONS) -o huffman huffman.cpp



# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean: tidy
	rm -f *.o
