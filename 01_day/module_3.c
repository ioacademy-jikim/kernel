#include <linux/module.h> // init_module, cleanup_module
#include <linux/kernel.h> // printk

int my_init(void)
{
	printk("my_init\n");
	return 0;
}

void my_exit(void)
{
	printk("my_exit\n");
}
module_init( my_init );
module_exit( my_exit );

MODULE_LICENSE("GPL");
