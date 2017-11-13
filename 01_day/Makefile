obj-m  = module_2.o
KERNEL = /root/tegra
PWD    = $(shell pwd) 

default : 
	$(MAKE) -C $(KERNEL)  SUBDIRS=$(PWD) modules

clean : 
	$(MAKE) -C $(KERNEL)  SUBDIRS=$(PWD) clean
