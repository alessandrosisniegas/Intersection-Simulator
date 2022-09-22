# Alessandro Sisniegas
# 04-11-22
build: intersection.o Road.o
	g++ intersection.cpp Road.o -o build

intersection.o: intersection.cpp Road.h
	g++ -c intersection.cpp -Wuninitialized -std=c++17
 
Road.o: Road.cpp Road.h
	g++ -c Road.cpp -Wuninitialized -std=c++17

clean:
	rm *.o	
	rm build

# target: dependencies
# command
# rm *.o (removes everything after the asterik in this case any file with .o)
# rm draw (removes the draw executable)