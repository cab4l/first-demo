CPP_FILES := $(wildcard src/*.cpp) $(wildcard src/effects/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o))) 

LD_FLAGS := -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -ldumb -lGL
CPP_FLAGS := -Wall -g -Iinclude -std=c++0x -Os

bin/demo: $(OBJ_FILES)
	g++ $(LD_FLAGS) -o $@ $^
	cp -R resources/* bin/

obj/%.o: src/%.cpp 
	g++ $(CPP_FLAGS) -c -o $@ $<

clean:
	rm -rf bin/* obj/*
