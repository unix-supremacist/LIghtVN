default: all

ifeq (, $(shell which ninja))
MAKEIT = cmake . -B build/
else
MAKEIT = cmake . -B build/ -GNinja
endif


all:
	@$(MAKEIT)
	@cmake --build "build/"

test: all
	@./build/LightVN