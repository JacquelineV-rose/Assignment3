in2post.x: in2post.cpp
	g++ -std=c++11 -Wall -o in2post.x in2post.cpp

proj3.x: test_stack1.cpp
	g++ -std=c++11 -Wall -o proj3.x test_stack1.cpp

clean:
	rm -f *.o *.x
