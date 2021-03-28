CXXFLAGS := -std=c++17 -O0 -g

CXXFLAGS += -fsanitize=address -fsanitize=undefined # sanitizers
CXXFLAGS += -Wall -pedantic -Werror -Wextra
CXXFLAGS += -Wno-unused-but-set-variable -Wno-unused-variable -Wno-unused-parameter

SOURCES = $(wildcard *.cpp)
BIN_DIR = bin
BINS = $(foreach binary,$(SOURCES:.cpp=),$(BIN_DIR)/$(binary))

all: $(BINS)

$(BIN_DIR)/%: %.cpp Makefile
	@mkdir -p $(BIN_DIR)
	$(CXX) -o $@ $(CXXFLAGS) $*.cpp

clean:
	rm -rf $(BINS)

.PHONY: clean all

dbg-%:
	@echo "Value of $* = $($*)"
