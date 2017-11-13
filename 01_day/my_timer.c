#if 1
#include <linux/module.h> // init_module, cleanup_module
#include <linux/kernel.h> // printk
#include <linux/timer.h>  // timer 계열

static struct timer_list timer;
void my_timer_handler( unsigned long data )
{
	printk("my_timer_handler(%lu)\n", data );
	timer.data     = data+1;
	mod_timer( &timer, jiffies + 1*HZ);
}

int my_init(void)
{
	printk("my_init\n");
	init_timer(&timer);
	timer.expires  = jiffies    +        HZ;
	//              현재시간  으로부터  1 초 
	timer.function = my_timer_handler;
	timer.data     = 0;
	add_timer(&timer);
	return 0;
}

void my_exit(void)
{
	del_timer(&timer);
	printk("my_exit\n");
}
module_init( my_init );
module_exit( my_exit );

MODULE_LICENSE("GPL");
#endif
#if 0
#include <linux/module.h> // init_module, cleanup_module
#include <linux/kernel.h> // printk
#include <linux/timer.h>  // timer 계열

static struct timer_list timer;
void my_timer_handler( unsigned long data )
{
	printk("my_timer_handler(%lu)\n", data );
}
int my_init(void)
{
	printk("my_init\n");
	init_timer(&timer);
	timer.expires  = jiffies    +        3*HZ;
	//              현재시간  으로부터  3  초 
	timer.function = my_timer_handler;
	timer.data     = 0;
	add_timer(&timer);
	return 0;
}

void my_exit(void)
{
	del_timer(&timer);
	printk("my_exit\n");
}
module_init( my_init );
module_exit( my_exit );

MODULE_LICENSE("GPL");
#endif
