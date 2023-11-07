bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp ListArray.h

clean:
	rm -r *.o *.gch bin

Point2D.o: Point2D.h Point2D.cpp
        g++ -c Point2D.cpp
