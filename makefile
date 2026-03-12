Sort:Sort.cpp
	g++ -D QuickSort -o $@ $^ -std=c++11
.PHONY:clean
clean:
	rm -f Sort