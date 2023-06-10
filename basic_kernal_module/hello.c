#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Roopak");
int my_init(void)
{
	printk(KERN_INFO"HELLO WORLD my_init\n");
	return 0;
}

void my_exit(void)
{
	printk(KERN_INFO"HELLO WORLD my_exit\n");
}

module_init(my_init);
module_exit(my_exit);

