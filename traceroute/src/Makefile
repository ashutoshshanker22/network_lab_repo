# Copyright(c) 2014
# Name: Ashutosh Shanker
# Email: ashutoshshanker22@gmail.com

COPY	= cp
MOVE	= mv
REMOVE	= rm

OBJ_DIR	= ../obj
BIN_DIR	= ../bin
O_FLAG	= -O2
#
# Include
#
INCLUDE_DIR	= ../include
INCLUDE	= -I${INCLUDE_DIR}

#
# C compiler and flags
#
CC	= ${CROSS_COMPILE}gcc #--platform=native
CFLAGS	= ${O_FLAG} -Wall ${INCLUDE} # -g
# LDFLAGS	=

# To make object file
#
%.o: %.c
	${CC} ${CFlAGS} -c $< -o $@
	${COPY} *.o ${OBJ_DIR}

#
# Main targets
#
TRPROGS	= traceroute-ts

OBJ	= main.o

TARGETS	= ${TRPROGS}

all:	traceroute-ts
traceroute-ts: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o $@
	${MOVE} traceroute-ts ${BIN_DIR}
	
clean:
	${REMOVE} -f *.o ${BIN_DIR}/* ${OBJ_DIR}/*

