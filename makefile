objects = main.o Cabin.o Car.o ioutil.o Location.o Junkpile.o Garden.o \
          Forest.o Cliffwall.o Shed.o Lakeshore.o Boat.o Player.o map.o

escape : $(objects)
	g++ -o escape $(objects)

main.o: main.cpp
	g++ -c -Wextra -Wall -pedantic -std=c++11 main.cpp

Cabin.o: Cabin.cpp Location.hpp
	g++ -c -Wextra -Wall -pedantic -std=c++11 Cabin.cpp

Car.o: Car.cpp Location.hpp
	g++ -c -Wextra -Wall -pedantic -std=c++11 Car.cpp

ioutil.o: ioutil.cpp ioutil.hpp
	g++ -c -Wextra -Wall -pedantic -std=c++11 ioutil.cpp

Location.o: Location.cpp Location.hpp
	g++ -c -Wextra -Wall -pedantic -std=c++11 Location.cpp

Junkpile.o: Junkpile.cpp Location.hpp
	g++ -c -Wextra -Wall -pedantic -std=c++11 Junkpile.cpp

Garden.o: Garden.cpp Location.hpp
	g++ -c -Wextra -Wall -pedantic -std=c++11 Garden.cpp

Forest.o: Forest.cpp Location.hpp
	g++ -c -Wextra -Wall -pedantic -std=c++11 Forest.cpp

Cliffwall.o: Cliffwall.cpp Location.hpp
	g++ -c -Wextra -Wall -pedantic -std=c++11 Cliffwall.cpp

Shed.o: Shed.cpp Location.hpp
	g++ -c -Wextra -Wall -pedantic -std=c++11 Shed.cpp

Lakeshore.o: Shed.cpp Location.hpp
	g++ -c -Wextra -Wall -pedantic -std=c++11 Lakeshore.cpp

Boat.o: Boat.cpp Location.hpp
	g++ -c -Wextra -Wall -pedantic -std=c++11 Boat.cpp

Player.o: Player.cpp Location.hpp ioutil.hpp Player.hpp
	g++ -c -Wextra -Wall -pedantic -std=c++11 Player.cpp

map.o: map.cpp map.hpp
	g++ -c -Wextra -Wall -pedantic -std=c++11 map.cpp

clean:
	rm escape *.o