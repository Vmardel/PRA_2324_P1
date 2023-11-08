bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp ListArray.h

Point2d.o: Point2d.h Point2d.cpp
	g++ -c Point2d.cpp

bin/testPoint2d: testPoint2d.cpp Point2d.o
	g++ -c testPoint2d.cpp
	mkdir -p bin
	g++ -o bin/testPoint2d testPoint2d.o Point2d.o

clean:
	rm -r *.o *.gch bin

