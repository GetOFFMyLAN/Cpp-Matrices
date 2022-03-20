CXX = g++
SDIR = $(PWD)/src
ODIR = $(PWD)/build
TDIR = $(ODIR)/tests
IDIR = $(PWD)/inc
FLAGS = -std=c++17 -g -Wall -Weffc++ -fsanitize=undefined,address -I $(IDIR)

.PHONY: all
all: $(ODIR)/main

$(ODIR)/main.out: $(ODIR)/main.o
	$(CXX) $(FLAGS) $^ -o $@
$(ODIR)/main.o: $(SDIR)/main.cpp
	$(CXX) $(FLAGS) -c $^ -o $@

.PHONY: clean
clean:
	rm -rf $(ODIR)/*.o $(ODIR)/*.out $(TDIR)/* && clear
