
memcpy:
	g++ memcpy.cc -o memcpy
quicksort:
	g++ quicksort.cc -o quicksort
clean:
	rm -f *.o
	rm memcpy
	rm quicksort
