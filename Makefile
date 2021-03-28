CXXFLAGS := -std=c++17 -O0 -g

CXXFLAGS += -fsanitize=address -fsanitize=undefined # sanitizers
CXXFLAGS += -Wall -pedantic -Werror -Wextra
CXXFLAGS += -Wno-unused-but-set-variable -Wno-unused-variable -Wno-unused-parameter

SOURCES = $(wildcard *.cpp)
BINS = $(SOURCES:.cpp=)

all: $(BINS)

%: %.cpp Makefile
	$(CXX) -o $@ $(CXXFLAGS) $*.cpp

clean:
	rm -rf $(BINS)

.PHONY: clean help all
