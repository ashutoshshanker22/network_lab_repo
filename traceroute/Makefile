# Copyright(c) 2014
# Name: Ashutosh Shanker
# Email: ashutoshshanker22@gmail.com
#

MKDIR = mkdir -p
REMOVE   = rm -rf

all: traceroute-ts

#####################

traceroute-ts:
	${MKDIR} bin
	${MKDIR} obj
	cd src; make

#####################

clean: traceroute-ts_clean

traceroute-ts_clean:
	cd src; make clean
	${REMOVE} bin obj
