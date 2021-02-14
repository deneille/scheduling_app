#finish writing this

testmain: appOpener.o tasks.o
	g++ testmain.cpp appOpener.o tasks.o

appOpener.o: appOpener.cpp appOpener.hpp
	g++ appOpener.cpp -c

tasks.o: tasks.cpp tasks.hpp
	g++ tasks.cpp -c

clean:
	rm -f *.o *.exe