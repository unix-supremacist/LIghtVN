default: test

all:
	cmake -S . -B build/
	cmake --build "build/"

test: all
	./build/LightVN