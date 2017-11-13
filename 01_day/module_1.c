#include <linux/module.h> // init_module, cleanup_module
#include <linux/kernel.h> // printk
#include <linux/gpio.h>   // gpio_get_value

int init_module(void)
{
	int ret;
	printk("init_module\n");
	ret = gpio_get_value( 170 );
	printk("ret=%d\n", ret );
	return 0;
}

void cleanup_module(void)
{
	printk("cleanup_module\n");
}
