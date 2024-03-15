/*
 *	This include file is intended for oplus display panel that to notify and receive
 *	blank/unblank event.
 *
 */
#ifndef _OPLUS_TP_PANEL_NOTIFIER_H_
#define _OPLUS_TP_PANEL_NOTIFIER_H_

#include <linux/notifier.h>

#define		OPLUS_PANEL_EARLY_EVENT_BLANK   0x01
#define		OPLUS_PANEL_EVENT_BLANK         0x02
#define		OPLUS_TOUCH_EARLY_EVENT_BLANK   0x03
#define		OPLUS_TOUCH_EVENT_BLANK         0x04


enum {
	/* panel: power on */
	OPLUS_PANEL_POWER_ON,
	/* panel: power off */
	OPLUS_PANEL_POWER_OFF,
	/* touch: gesture on*/
	OPLUS_TOUCH_GESTURE_ON,
	/* touch: gesture off*/
	OPLUS_TOUCH_GESTURE_OFF,
	/* touch: black_test on*/
	OPLUS_TOUCH_BLACK_TEST_ON,
	/* touch: black_test off*/
	OPLUS_TOUCH_BLACK_TEST_OFF,
	/*touch: cs power on*/
	OPLUS_PANEL_CS_POWER_ON,
	/*touch: cs power off */
	OPLUS_PANEL_CS_POWER_OFF,
};

struct oplus_panel_notify_data {
	int blank;
	int gesture_flag;
	int black_test_flag;
	void *data; //not use, reserved
};

extern int oplus_tp_panel_notifier_register_client(struct notifier_block *nb);
extern int oplus_tp_panel_notifier_unregister_client(struct notifier_block *nb);
extern int oplus_tp_panel_notifier_call_chain(unsigned long val, void *v);
#endif