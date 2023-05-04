
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11


TARGET = saper
OBJFILES = main.o minesweeper.o


all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f $(OBJFILES) $(TARGET)