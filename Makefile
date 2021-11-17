CXX := g++
TARGET := visulization
CXXFLAGS := -std=c++11 -O3
WARNINGFLAGS := -Wall -Wextra
INCLUDE := src
SRC_DIRS := src
SRCS := $(wildcard $(SRC_DIRS:=/*.cpp))
OBJS := $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ -lpthread

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(WARNINGFLAGS) -I $(INCLUDE) -isystem -MMD -c $< -o $@

clean:
	rm -rf $(TARGET) $(OBJS) $(DEPS)

.PHONY: all clean test
-include $(DEPS)