#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Amir");
MODULE_DESCRIPTION("A simple Hello World kernel module");

static int __init hello_init(void) {
    printk(KERN_INFO "[Amir Module] Hello, Kernel!\n");
    return 0;
}

static void __exit hello_exit(void) {
    printk(KERN_INFO "[Amir Module] Goodbye, Kernel!\n");
}

module_init(hello_init);
module_exit(hello_exit);

