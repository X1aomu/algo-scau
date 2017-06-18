CC = gcc
CXX = g++
CFLAGS = -Og -Wall -Wextra -ggdb -lm
CXXFLAGS = $(CFLAGS)

C_SRCS = $(wildcard *.c)
CXX_SRCS = $(wildcard *.cc)
C_BINS = $(patsubst %.c, %, $(C_SRCS))
CXX_BINS = $(patsubst %.cc, %, $(CXX_SRCS))

.PHONY: all bin

all: bin

bin: $(C_BINS) $(CXX_BINS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

%: %.cc
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(C_BINS) $(CXX_BINS)

