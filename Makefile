main_print: main.o OfflineBin.o OnlineBin.o OptimalBin.o
	g++ -O3 -Wall -o $@ $^

main.o: main.cpp
	g++ -O3 -Wall -c $^

OfflineBin.o: OfflineBin.cpp
	g++ -O3 -Wall -c $^

OnlineBin.o: OnlineBin.cpp
	g++ -O3 -Wall -c $^

OptimalBin.o: OptimalBin.cpp
	g++ -O3 -Wall -c $^

clean:
	rm -f *.o main_print