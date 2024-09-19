# Makefile pour TP2.
# Adaptez ce fichier au besoin (si vous ajouter des fichiers).


# Choisir l'une des deux configurations (-g: Debug | -O2: Release)
#OPTIONS = -g -O0 -Wall
OPTIONS = -O2 -Wall

all : tp2 testdate

date.o : date.cpp date.h
	g++ ${OPTIONS} -c -o date.o date.cpp
	
lot_medicament.o : lot_medicament.cpp lot_medicament.h date.h
	g++ ${OPTIONS} -c -o lot_medicament.o lot_medicament.cpp

medicament.o : medicament.cpp medicament.h date.h lot_medicament.h
	g++ ${OPTIONS} -c -o medicament.o medicament.cpp

prescription.o : prescription.cpp prescription.h date.h file.h
	g++ ${OPTIONS} -c -o prescription.o prescription.cpp

stock.o : stock.cpp stock.h arbreavl.h lot_medicament.h prescription.h
	g++ ${OPTIONS} -c -o stock.o stock.cpp

	
tp2 : tp2.cpp date.o stock.o lot_medicament.o prescription.o medicament.o
	g++ ${OPTIONS} -o tp2 tp2.cpp  date.o stock.o lot_medicament.o prescription.o medicament.o

testdate : testdate.cpp date.o
	g++ $(OPTIONS) -o testdate testdate.cpp date.o

clean:
	rm -rf tp2 testdate *~ *.o

