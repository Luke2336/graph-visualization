CXX := g++
TARGET := fruchterman_reingold.*.so
CXXFLAGS := -std=c++11 -O3
WARNINGFLAGS := -Wall -Wextra

all: $(TARGET)

$(TARGET): *.cpp *.hpp
	$(CXX) $(CXXFLAGS) $(WARNINGFLAGS) -shared -undefined dynamic_lookup `python3 -m pybind11 --includes` fruchterman_reingold.cpp -o fruchterman_reingold`python3-config --extension-suffix` 

clean:
	rm -rf $(TARGET)

.PHONY: all clean