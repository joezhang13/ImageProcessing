proj3.exe: proj3.o ColorImageClass.o PatternClass.o RectangleClass.o ColorClass.o RowColumnClass.o input.o chooseColor.o
	g++ proj3.o ColorImageClass.o PatternClass.o RectangleClass.o ColorClass.o RowColumnClass.o input.o chooseColor.o -o proj3.exe

proj3.o: proj3.cpp constants.h ColorImageClass.h PatternClass.h RectangleClass.h ColorClass.h RowColumnClass.h input.h chooseColor.h
	g++ -c proj3.cpp -o proj3.o

ColorImageClass.o: ColorImageClass.cpp constants.h ColorImageClass.h PatternClass.h RectangleClass.h ColorClass.h RowColumnClass.h input.h
	g++ -c ColorImageClass.cpp -o ColorImageClass.o

PatternClass.o: PatternClass.cpp constants.h RowColumnClass.h ColorClass.h PatternClass.h input.h
	g++ -c PatternClass.cpp -o PatternClass.o

RectangleClass.o: RectangleClass.cpp constants.h RowColumnClass.h ColorClass.h RectangleClass.h
	g++ -c RectangleClass.cpp -o RectangleClass.o

ColorClass.o: ColorClass.cpp constants.h ColorClass.h input.h
	g++ -c ColorClass.cpp -o ColorClass.o

RowColumnClass.o: RowColumnClass.cpp constants.h RowColumnClass.h
	g++ -c RowColumnClass.cpp -o RowColumnClass.o

input.o: input.cpp constants.h input.h
	g++ -c input.cpp -o input.o

chooseColor.o: chooseColor.cpp constants.h input.h ColorClass.h chooseColor.h
	g++ -c chooseColor.cpp -o chooseColor.o

clean:
	rm -f proj3.exe proj3.o ColorImageClass.o PatternClass.o RectangleClass.o ColorClass.o RowColumnClass.o input.o chooseColor.o
