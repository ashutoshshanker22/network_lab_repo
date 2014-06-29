#
# Name : Ashutosh Shanker
# Email : ashutoshshanker22@gmail.com
# Copyright(c) 2014-15
#

obj-m	:= conntrack.o

ifeq (,$(BUILD_KERNEL))
BUILD_KERNEL=$(shell uname -r)
endif

EXTRA_CFLAGS += -I$(PWD)

HERE=$(PWD)

#set the install path
INSTDIR	:= $(DESTDIR)/lib/modules/$(BUILD_KERNEL)/kernel/net/conntrack
TARGETDIR	:= $(DESTDIR)/usr/src/$(BUILD_KERNEL)/include/linux/

all:	Makefile conntrack.c linux/conntrack.h
		@if test "$(USER)" = "root"; then \
			echo "********** WARNING WARNING WARNING **********"; \
			echo "*"; \
        	echo "* Compiling CONNTRACK as root might lead you to compile errors"; \
        	echo "* Please compile CONNTRACK  as unpriviliged user"; \
        	echo "*"; \
        	echo "*********************************************"; \
        fi
		make -C /lib/modules/$(BUILD_KERNEL)/build SUBDIRS=$(HERE) EXTRA_CFLAGS='$(EXTRA_CFLAGS)' modules

clean:
		make -C /lib/modules/$(BUILD_KERNEL)/build SUBDIRS=$(HERE) clean
		\rm -f *~ Module.symvers  Module.markers  modules.order *#

install:
		mkdir -p $(INSTDIR)
		cp *.ko $(INSTDIR)
		cp linux/conntrack.h $(DESTDIR)/usr/include/linux
		@if test -d ${TARGETDIR}; then \
    		cp linux/conntrack.h ${TARGETDIR}; \
		fi
ifeq (,$(DESTDIR))
		/sbin/depmod $(BUILD_KERNEL)
endif

