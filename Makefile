build:
	g++ -fdiagnostics-color=always -Wall ./src/*.cpp ./lib/rlImGui-main/objects/*.o -o main.exe -lraylib