all: calculator
clean:
	rm -rf calculator
	
calculator: calculation.h parser.h scanner.h exception.h scanner.cpp parser.cpp
	g++ -o calculator calculator.cpp scanner.cpp parser.cpp calculation.cpp
