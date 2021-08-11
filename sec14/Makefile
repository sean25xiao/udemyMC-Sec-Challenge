CXX=g++
CXXFLAGS=-Werror -std=c++17

DEPS=Movie.h Movies.h
OBJECTS=main.o Mystring.o
TARGET=sec14run

all: $(TARGET)

$(TARGET): $(OBJECTS)
        $(CXX) $(CXXFLAGS) -o $@ $^

#%.o: %.cpp $(DEPS)                                                             
#       $(CXX) $(CXXFLAGS) -o $@ $<                                             

clean:
        rm -rf *.o sec14run