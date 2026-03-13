Sort:Sort.cpp
	g++ -D HeapSort -o $@ $^ -std=c++11
.PHONY:clean
clean:
	rm -f Sort