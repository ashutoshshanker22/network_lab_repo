# Copyright(c) 2014
# Name: Ashutosh Shanker
# Email: ashutoshshanker22@gmail.com
#


all: traceroute-ts

#####################

traceroute-ts:
	cd traceroute; make

#####################

clean: traceroute-ts_clean

traceroute-ts_clean:
	cd traceroute; make clean
