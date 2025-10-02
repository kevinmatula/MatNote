main: main.cpp glad/glad.c
	g++ main.cpp glad/glad.c -I. -o main -lglfw -ldl -lpthread -lX11	 
