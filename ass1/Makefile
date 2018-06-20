
Search: Search.o CardCatalog.o Media.o Film.o Book.o Periodic.o Video.o
	g++ -o Search Search.o CardCatalog.o Media.o Film.o Book.o Periodic.o Video.o


Search.o: Search.cpp CardCatalog.h Media.h
	g++ -c Search.cpp

CardCatalog.o: CardCatalog.cpp CardCatalog.h Media.h Book.h Film.h Video.h Periodic.h
	g++ -c -g CardCatalog.cpp

Media.o: Media.cpp Media.h
	g++ -c -g Media.cpp

Book.o: Book.cpp Book.h Media.h
	g++ -c -g Book.cpp

Film.o: Film.cpp Film.h Media.h
	g++ -c -g Film.cpp

Periodic.o: Periodic.cpp Periodic.h Media.h
	g++ -c -g Periodic.cpp

Video.o: Video.cpp Video.h Media.h
	g++ -c -g Video.cpp


clean:
	rm -f Search.o CardCatalog.o Media.o Book.o Film.o Periodic.o Video.o Search
