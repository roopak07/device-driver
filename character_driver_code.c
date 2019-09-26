#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/cdev.h>
#include <linux/fs.h>
#include <linux/poll.h>
#include <linux/ioport.h>
#include <linux/errno.h>

MODULE_AUTHOR("Roopak");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Sample charcter driver");


typedef struct //insted we can write "struct mydev_t" and can define mydev as "struct mydev_t mydev"
{
int nchar;
char buf[1024];
struct cdev mycdev; //mycdev is of type struct cdev
}mydev_t;
mydev_t mydev; // mydev is a variable of type struct mydev_t

static struct file_operations mycdev_ops =
{
.open	=	mydev_open,
.release=	mydev_close,
.write	=	mydev_write,
.read	=	mydev_read,
};


int mydev_init(void)
{
int ret=0,res=0;
dev_t devno = 0; // devno is of type dev_t
devno=MKDEV(42,0);
ret=register_chrdev_region(devno,10,"mychardev");
printk("ret=%d\n",ret);
if(ret<0)
{
 printk("Register char dev region Error %d\n",ret);
return 1; // driver gets off loaded form kernal space of RAM
}
else
 printk("Register char dev region success %d\n",ret);

cdev_init(&mydev.mycdev,&mycdev_ops); //mycdev.fops = &mycdev_ops
mydev.mycdev.owner=THIS_MODULE;
res = cdev_add(&mydev.mycdev,devno,1);// registering cdev object with kernel

if(res) // if res = non zero value then its a fail ,so dergister cdev object
{
unregister_chrdev_region(devno,10);
return 1;
}
else
{
printk("cdev added sucessfully :%d \n",res);
}
mydev.nchar = 0;
return 0;
}
