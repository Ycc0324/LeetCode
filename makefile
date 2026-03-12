Sort:Sort.cpp
	g++ -D MergeSort -o $@ $^ -std=c++11
.PHONY:clean
clean:
	rm -f Sort