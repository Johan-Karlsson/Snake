CXXFLAGS = -Wall -std=c++17

output: main.o display.o snake.o food.o
	g++ main.o display.o snake.o food.o -lncurses -o output

main.o: main.cpp
	g++ -c main.cpp

snake.o: snake.cpp snake.h
	g++ -c snake.cpp

food.o: food.cpp food.h
	g++ -c food.cpp

display.o: display.cpp display.h
	g++ -c display.cpp

clean:
	rm *.o output

run: output
	./output