CC = g++

TARGET = SolveBoxyBoy

SRCS = solver.cpp
SRCS += BoxyBoy.cpp
SRCS += Stage.cpp
SRCS += Entity.cpp

OBJS    = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBDIR) $(LIBS)
