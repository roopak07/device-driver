#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
MODULE_LICENSE("GPL"); // enable license ,without license kernal will assume this module as mallware
int my_init(void)
{
printk(KERN_ALERT "hello world my_init");
return 0;
}

void my_exit(void)
{
printk(KERN_ALERT "helo world my_out");
}
module_init(my_init);
module_exit(my_exit);
