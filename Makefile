bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp ListArray.h

Point2d.o: Point2d.h Point2d.cpp
	g++ -c Point2d.cpp

clean:
	rm -r *.o *.gch bin

