include ../makeinclude


LIBS = -lbase
CPPFLAGS += -I"../"
LDFLAGS += -L"../"
CFLAGS += -O3

ifdef _WIN32
BIN  := ../snesbrr.exe
else
BIN := ../snesbrr
endif
SRC := $(wildcard *.cpp)
OBJ := $(addsuffix .o,$(SRC))
DEP := $(addsuffix .d,$(SRC))


.PHONY : all clean distclean compress

all : $(BIN)

clean :
	-$(RM) $(OBJ) $(BIN) $(DEP)
#	-$(RM)

distclean : clean
	-$(RM) $(DEP)

compress :
	-upx --best $(BIN)

$(BIN) : $(OBJ) ../libbase.a
	@echo "Linking $(words $(OBJ)) Object Files Into $@"; $(CXX) $(OBJ) -o $@ $(LDFLAGS) $(LIBS)


ifeq ($(findstring $(MAKECMDGOALS),clean distclean compress),)
 -include $(DEP)
endif

