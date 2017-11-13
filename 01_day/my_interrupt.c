#if 1
#include <linux/module.h>     // init_module, cleanup_module
#include <linux/kernel.h>     // printk
#include <linux/interrupt.h>  // interrupt 계열

irqreturn_t my_irq_handler(int irq, void *id)
{
	printk("my_irq_handler(%d, %p)\n", irq, id );
	return IRQ_HANDLED;
}

static void *dev = (void*)0x1234;

int my_init(void)
{
	int ret;
	unsigned long flags = 0x83;
	printk("my_init\n");
	ret = request_irq(379,  my_irq_handler, flags, "MY INT", dev);
	return 0;
}

void my_exit(void)
{
	free_irq( 379, dev );
	printk("my_exit\n");
}
module_init( my_init );
module_exit( my_exit );

MODULE_LICENSE("GPL");
#endif
