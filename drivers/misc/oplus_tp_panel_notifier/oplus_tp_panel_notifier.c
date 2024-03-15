#include <linux/list.h>
#include <linux/mutex.h>
#include <linux/module.h>
#include <misc/oplus_tp_panel_notifier.h>

static BLOCKING_NOTIFIER_HEAD(oplus_tp_panel_notifier_list);

/*
 *	oplus_tp_panel_notifier_register_client - register a client notifier
 *	@nb:notifier block to callback when event happen
 */
int oplus_tp_panel_notifier_register_client(struct notifier_block *nb)
{
	return blocking_notifier_chain_register(&oplus_tp_panel_notifier_list, nb);
}
EXPORT_SYMBOL(oplus_tp_panel_notifier_register_client);

/*
 *	oplus_tp_panel_notifier_unregister_client - unregister a client notifier
 *	@nb:notifier block to callback when event happen
 */
int oplus_tp_panel_notifier_unregister_client(struct notifier_block *nb)
{
	return blocking_notifier_chain_unregister(&oplus_tp_panel_notifier_list, nb);
}
EXPORT_SYMBOL(oplus_tp_panel_notifier_unregister_client);

/*
 *	oplus_tp_panel_notifier_notifier_call_chain - notify clients of oplus_tp_panel_notifier_event
 *
 */

int oplus_tp_panel_notifier_call_chain(unsigned long val, void *v)
{
	return blocking_notifier_call_chain(&oplus_tp_panel_notifier_list, val, v);
}
EXPORT_SYMBOL(oplus_tp_panel_notifier_call_chain);


static int __init oplus_tp_panel_notifier_init(void)
{
	pr_info("%s Entry\n", __func__);

	return 0;
}

static void __exit oplus_tp_panel_notifier_exit(void)
{
	pr_info("%s Entry\n", __func__);
}

module_init(oplus_tp_panel_notifier_init);
module_exit(oplus_tp_panel_notifier_exit);

MODULE_AUTHOR("oplus display driver team");
MODULE_DESCRIPTION("oplus Panel notifier driver");
MODULE_LICENSE("GPL v2");