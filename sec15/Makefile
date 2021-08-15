CXX=g++
CXXFLAGS=-Werror -std=c++17

DEPS=Account_Util.h Account.h Savings_Account.h
OBJECTS=main.o Account.o Savings_Account.o Account_Util.o
TARGET=sec15run

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf *.o sec15run 