# @name     core
# @file:    makefile
# @date:    Sun Sep 28 02:16:58 CDT 2025
# @version: version 0.0.1

# g++ warnings
#-Wall -Wextra -Wpedantic -Wshadow -Wconversion -Werror -Wundef
#-fsanitize=undefined,address -Wfloat-equal -Wformat-nonliteral
#-Wformat-security -Wformat-y2k -Wformat=2 -Wimport -Winvalid-pch
#-Wlogical-op -Wmissing-declarations -Wmissing-field-initializers
#-Wmissing-format-attribute -Wmissing-include-dirs -Wmissing-noreturn
#-Wnested-externs -Wpacked -Wpointer-arith -Wredundant-decls
#-Wstack-protector -Wstrict-null-sentinel -Wswitch-enum -Wwrite-strings

SHELL:=bash

APP=core
CXX=g++
CXXFLAGS=-Wall -std=c++20 -fPIC -DNDEBUG
CXXEXTRA=-Wno-template-body
CXXCPP?=
LDFLAGS?=
LIBS?=

SRC?=src
BLD?=build
OBJ?=build

# lib settings
LIBS=-L/usr/lib -L/usr/lib64 -L/usr/local/lib -L/usr/local/lib64
INCLUDES=-I/usr/local/include/cppunit/
LDFLAGS=$(INCLUDES) $(LIBS)

ifndef RELEASE
	CXXFLAGS +=-g -DDEBUG
endif

ifdef CYGWIN
	CXXFLAGS +=-DCYGWIN
	LDFLAGS += -lfmt -lcppunit.dll
else
	LDFLAGS += -lfmt -lcppunit
endif

all: $(BLD)/core $(BLD)/libcore.so $(BLD)/libcore.a

$(BLD)/core: $(OBJ)/main.o $(OBJ)/core.o
	 $(CXX) $(CXXFLAGS) $(OBJ)/main.o $(OBJ)/core.o -o $(BLD)/core
$(BLD)/libcore.so: $(OBJ)/main.o $(BLD)/core.o
	$(CXX) $(CXXFLAGS) $(CXXEXTRA) --shared $(OBJ)/main.o $(BLD)/core.o -o $(BLD)/libcore.so
	-chmod 755 $(BLD)/libcore.so

$(BLD)/libcore.a: $(OBJ)/main.o $(BLD)/core.o
	-ar rvs $(BLD)/libcore.a $(OBJ)/main.o $(BLD)/core.o
	-chmod 755 $(BLD)/libcore.a

$(OBJ)/core.o: $(SRC)/core.cpp
	$(CXX) $(CXXFLAGS) $(CXXEXTRA) -c $(SRC)/core.cpp -o $(OBJ)/core.o

# rules <?php echo "\nTEST\n ?>
$(OBJ)/%.o: ./$(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

#CCSK_RULE#

.PHONY: all clean install unintsall rebuild help

rebuild: clean all

install:
	cp ./$(BLD)/core ./$(prefix)/bin/core
uninstall:
	-rm ./$(prefix)/bin/core
clean:
	@ECHO "removing files ..."
	-rm -f $(OBJ)/*
	-rm -f $(BLD)/*

help:
	@echo
	@echo  'Project: core; : version 0.0.1 : Sun Sep 28 02:16:58 CDT 2025 simple "core" framework.'
	@echo
	@echo  '    make [-f] [target]'
	@echo
	@echo  '   -Make Targets ...'
	@echo
	@echo  '*        all                                     - build all'
	@echo  '*        $(BLD)/core:         - re/build core'
	@echo  '*        $(BLD)/core_utest:   - re/build core_utest, unit testing'
	@echo  '*        clean                                   - remove most generated files but keep the config'
