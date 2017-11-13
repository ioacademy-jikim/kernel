obj-m  = my_timer.o
KERNEL = /root/tegra
PWD    = $(shell pwd) 

default : 
	$(MAKE) -C $(KERNEL)  SUBDIRS=$(PWD) modules

clean : 
	$(MAKE) -C $(KERNEL)  SUBDIRS=$(PWD) clean
