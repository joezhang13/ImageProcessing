proj3.exe: proj3.o ColorImageClass.o PatternClass.o RectangleClass.o ColorClass.o RowColumnClass.o input.o
	g++ proj3.o ColorImageClass.o PatternClass.o RectangleClass.o ColorClass.o RowColumnClass.o input.o -o proj3.exe

proj3.o: proj3.cpp Constants.h ColorImageClass.h PatternClass.h RectangleClass.h ColorClass.h RowColumnClass.h input.h
	g++ -c proj3.cpp -o proj3.o

ColorImageClass.o: ColorImageClass.cpp Constants.h ColorImageClass.h PatternClass.h RectangleClass.h ColorClass.h RowColumnClass.h input.h
	g++ -c ColorImageClass.cpp -o ColorImageClass.o

PatternClass.o: PatternClass.cpp Constants.h RowColumnClass.h ColorClass.h PatternClass.h input.h
	g++ -c PatternClass.cpp -o PatternClass.o

RectangleClass.o: RectangleClass.cpp Constants.h RowColumnClass.h ColorClass.h RectangleClass.h
	g++ -c RectangleClass.cpp -o RectangleClass.o

ColorClass.o: ColorClass.cpp Constants.h ColorClass.h input.h
	g++ -c ColorClass.cpp -o ColorClass.o

RowColumnClass.o: RowColumnClass.cpp Constants.h RowColumnClass.h
	g++ -c RowColumnClass.cpp -o RowColumnClass.o

input.o: input.cpp Constants.h input.h
	g++ -c input.cpp -o input.o

clean:
	rm -f proj3.exe proj3.o ColorImageClass.o PatternClass.o RectangleClass.o ColorClass.o RowColumnClass.o input.o
