#include <linux/module.h>   ///< Core header for loading LKMs into the kernel
#include <linux/kernel.h>   ///< Kernel types and functions (printk, etc.)
#include <linux/init.h>     ///< __init and __exit macros

/**
 * @file param_module.c
 * @brief A simple Linux kernel module that accepts parameters.
 *
 * This module takes two parameters (`username` and `repeat`) and logs greetings
 * to the kernel log when loaded. It also logs a message when unloaded.
 */

/** @brief Module license declaration */
MODULE_LICENSE("GPL");

/** @brief Author of the module */
MODULE_AUTHOR("Amir");

/** @brief Description of the module */
MODULE_DESCRIPTION("This is my Second Module that takes a param");

/**
 * @brief A username string to greet.
 * @details Default: "default"
 */
static char *username = "default";

/**
 * @brief Number of times to repeat the greeting.
 * @details Default: 1
 */
static int repeat = 1;

/** @brief Register `username` as a module parameter */
module_param(username, charp, 0000);
/** @brief Description of `username` parameter */
MODULE_PARM_DESC(username, "username string");

/** @brief Register `repeat` as a module parameter */
module_param(repeat, int, 0000);
/** @brief Description of `repeat` parameter */
MODULE_PARM_DESC(repeat, "Number of greetings");

/**
 * @brief Initialization function that runs on module load
 *
 * Logs "Hello <username>" <repeat> times using `printk()`.
 *
 * @return Always returns 0 (success)
 */
static int __init param_init(void)
{
    for (int i = 0; i < repeat; i++)
    {
        printk(KERN_INFO "Hello %s number (%d)\n", username, i + 1);
    }
    return 0;
}

/**
 * @brief Cleanup function that runs on module unload
 *
 * Logs a goodbye message to the kernel log.
 */
static void __exit param_exit(void)
{
    printk(KERN_INFO "[Amir Module 2] Exit Amir Second Module\n");
}

/** @brief Register module init function */
module_init(param_init);

/** @brief Register module exit function */
module_exit(param_exit);
