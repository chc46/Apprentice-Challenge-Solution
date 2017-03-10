MovieTheaterSchedule: main.o DailySchedule.o Movie.o Time.o
	g++ main.o DailySchedule.o Movie.o Time.o -o MovieTheaterSchedule
	rm *.o

main.o: main.cpp
	g++ -c main.cpp

DailySchedule.o: DailySchedule.cpp
	g++ -c DailySchedule.cpp

Movie.o: Movie.cpp
	g++ -c Movie.cpp

Time.o: Time.cpp
	g++ -c Time.cpp

clean:
	rm MovieTheaterSchedule
