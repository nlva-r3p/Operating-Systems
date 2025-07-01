#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/init.h>

int simple_init(void)
{
	struct task_struct *task;

	printk(KERN_INFO "Loading Task Lister Module\n");
	for_each_process(task) {
		printk(KERN_INFO "PID=%d | STATE - %ld | COMM=%s\n", task->pid, task->state, task->comm);
	}

	return 0;
}

void simple_exit(void)
{
	printk(KERN_INFO "Removing Task Lister Module\n");
}

module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Task Lister");
MODULE_AUTHOR("Nguyen Mai, Zaniab Nadeem, Idil Hassan");

