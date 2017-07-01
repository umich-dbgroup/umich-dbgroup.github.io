# 
#  Author: Jignesh M. Patel
#          EECS Department, University of Michigan
#  Date:   August 2000
# 

SRCS = DataGen.cpp DocGen.cpp Random.cpp StrGen.cpp ErrorHandlers.cpp
OBJS = DataGen.o DocGen.o Random.o StrGen.o ErrorHandlers.o
TARGET = mbgen

.SUFFIXES: 
.SUFFIXES: .o .cpp

CPP = g++
CPPFLAGS = -g -O3 -Wall 

# PURIFY = purify -collector=/usr/ccs/bin/ld -g++
PURIFY = purify -collector=/usr/um/gnu/bin/ld -g++

TAGS = etags --c++

MAKE_DEPEND_FILE = .depend
MAKE_DEPEND_CMD = $(CPP) $(CPPFLAGS) $(INCLUDES) -M $(SRCS) > $(MAKE_DEPEND_FILE)
TOUCH = /bin/touch 

.cpp.o:
	$(CPP) $(CPPFLAGS) $(INCLUDES) -c $< -o $@
    
all:	$(TARGET)

tags:
	$(TAGS) *.h *.cpp

depend:
	$(TOUCH) $(MAKE_DEPEND_FILE)
	$(MAKE_DEPEND_CMD)

clean:
	rm -rf $(OBJS) $(TARGET)

$(TARGET): $(OBJS)
	$(CPP) $(INCLUDES) $(CPPFLAGS) -o $@ $(OBJS)

$(TARGET).pure: $(OBJS)
	$(PURIFY) $(CPP) $(CPPFLAGS) -o $@ $(OBJS) 

include ./$(MAKE_DEPEND_FILE)

