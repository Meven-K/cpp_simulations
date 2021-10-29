test:
	g++ -Wall -o build/test test/test.cpp test/glad.c -lglfw -lGL -lX11 -lpthread -lXrandr -ldl -I include

point:
	g++ -Wall -o build/point test/point.cpp -lpthread -lSDL -lSDLmain -lglfw -lGL -lX11 -lXrandr -ldl

main:
	g++ -Wall -o build/galaxies src/* -lpthread -lSDL -lSDLmain -lglfw -lGL -lX11 -lXrandr -ldl -I include
