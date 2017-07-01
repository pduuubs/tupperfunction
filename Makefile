CC     = g++
CFLAGS = -std=c++11 -Wall -pedantic -s -O2 -I.. -DTTMATH_DONT_USE_WCHAR

all :
	$(CC) tupper.cpp $(CFLAGS) -o tupper
