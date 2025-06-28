#include <linux/module.h>   ///< Required for all kernel modules
#include <linux/kernel.h>   ///< Contains printk() and other kernel helpers
#include <linux/init.h>     ///< Required for __init and __exit macros
#include <linux/timer.h>    ///< Kernel timer API

/**
 * @file heartbeat_module.c
 * @brief A basic kernel module that logs a message every 2 seconds using a timer.
 */

/** @brief License for the module (GPL = safe for kernel use) */
MODULE_LICENSE("GPL");

/** @brief Module author name */
MODULE_AUTHOR("Amir");

/** @brief Short description of the module */
MODULE_DESCRIPTION("Module to Study the Linux Timer");

/**
 * @brief Timer structure used to manage scheduling.
 */
static struct timer_list mytimer;

/**
 * @brief Counter to track how many times the timer fired.
 */
static int count = 0;

/**
 * @brief Timer callback function.
 * 
 * This function runs every time the timer fires.
 * It logs a message, increments the count, and restarts the timer.
 * 
 * @param list Pointer to the timer that triggered the callback.
 */
static void timer_callback(struct timer_list* list)
{
    count++;
    printk(KERN_INFO "[Amir Heartbeat Module] Timer triggered %d times\n", count);

    // Re-arm the timer to fire again after 2 seconds
    mod_timer(&mytimer, jiffies + msecs_to_jiffies(2000));
}

/**
 * @brief Initialization function for the module.
 * 
 * Sets up and starts the kernel timer.
 * 
 * @return Always returns 0 (success)
 */
static int __init heartbeat_init(void)
{
    printk(KERN_INFO "[Heartbeat] Module loaded\n");

    // Initialize the timer and link it to the callback function
    timer_setup(&mytimer, &timer_callback, 0);

    // Schedule the first timer event 2 seconds from now
    mod_timer(&mytimer, jiffies + msecs_to_jiffies(2000));

    return 0;
}

/**
 * @brief Cleanup function when the module is removed.
 * 
 * Deletes the timer to avoid it running after module is gone.
 */
static void __exit heartbeat_exit(void)
{
    del_timer(&mytimer);
    printk(KERN_INFO "[Amir Module 3] Exit Heartbeat module");
}

// Register the init and exit functions with the kernel
module_init(heartbeat_init);
module_exit(heartbeat_exit);
