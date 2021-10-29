test:
	g++ -Wall -o build/test src/test.cpp src/glad.c -lglfw -lGL -lX11 -lpthread -lXrandr -ldl -I include

point:
	g++ -Wall -o build/point src/point.cpp -lpthread -lSDL -lSDLmain -lglfw -lGL -lX11 -lpthread -lXrandr -ldl
