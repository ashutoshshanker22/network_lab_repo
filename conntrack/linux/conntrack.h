#ifndef _CONNTRACK_H
#define _CONNTRACK_H
#endif

#include <linux/types.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/skbuff.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/ip.h>
#include <linux/udp.h>
#include <linux/tcp.h>
#include <linux/in.h>
#include <linux/netdevice.h>

#ifndef log_fmt
#define log_fmt(fmt) fmt
#endif

#define log_emerg(fmt, ...) \
    printk(KERN_EMERG log_fmt(fmt), ##__VA_ARGS__)
#define log_alert(fmt, ...) \
    printk(KERN_ALERT log_fmt(fmt), ##__VA_ARGS__)
#define log_crit(fmt, ...) \
    printk(KERN_CRIT log_fmt(fmt), ##__VA_ARGS__)
#define log_err(fmt, ...) \
    printk(KERN_ERR log_fmt(fmt), ##__VA_ARGS__)
#define log_warn(fmt, ...) \
    printk(KERN_WARNING log_fmt(fmt), ##__VA_ARGS__)
#define log_notice(fmt, ...) \
    printk(KERN_NOTICE log_fmt(fmt), ##__VA_ARGS__)
#define log_info(fmt, ...) \
    printk(KERN_INFO log_fmt(fmt), ##__VA_ARGS__)
#define log_cont(fmt, ...) \
    printk(KERN_CONT log_fmt(fmt), ##__VA_ARGS__)

#define log_warning log_warn

#ifdef DEBUG
#define log_devel(fmt, ...) \
    printk(KERN_DEBUG log_fmt(fmt), ##__VA_ARGS__)
#else
#define log_devel(fmt, ...) \
    no_printk(KERN_DEBUG log_fmt(fmt), ##__VA_ARGS__)
#endif

#if defined(DEBUG)
#define log_debug(fmt, ...) \
    printk(KERN_DEBUG log_fmt(fmt), ##__VA_ARGS__)
#elif defined(CONFIG_DYNAMIC_DEBUG)
#define log_debug(fmt, ...) \
    dynamic_pr_debug(fmt, ##__VA_ARGS__)
#else
#define log_debug(fmt, ...) \
    no_printk(KERN_DEBUG log_fmt(fmt), ##__VA_ARGS__)
#endif


static unsigned int conntrack_basic(unsigned int hooknum,
                    struct sk_buff *skb,
                    const struct net_device *in,
                    const struct net_device *out,
                    int (*okfn)(struct sk_buff *));

