#Makefile for domletters

CPP = g++
CPPFLAGS = -Wall -Werror -g
TARGET = domletters
SRCS = domletters.cpp

$(TARGET): $(SRCS)
	$(CPP) $(CPPFLAGS) -o $(TARGET) $(SRCS)

clean:
	-rm -f $(TARGET)