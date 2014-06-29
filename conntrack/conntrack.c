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
#include <linux/conntrack.h>
#include <linux/netdevice.h>

#define DEBUG 0


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

static struct nf_hook_ops conntrack_ops[] __read_mostly = {
	{
		.hook		= conntrack_basic,
		.owner		= THIS_MODULE,
		.pf	    	= NFPROTO_IPV4,
		.hooknum	= NF_INET_PRE_ROUTING,
		.priority	= NF_IP_PRI_FIRST,
	},
};

unsigned int
my_conntrack_basic(struct net *net, u_int8_t pf, unsigned int hooknum,
		   struct sk_buff *skb) {
#if 0
	struct sk_buff *sock_buf = NULL;
	struct iphdr *ip_header = NULL;
	struct tcphdr *tcp_header = NULL;
	struct udphdr *udp_header = NULL;

	sock_buf = skb;
	if (sock_buf == NULL) {
		return NF_ACCEPT;
	} else {
		ip_header = (struct iphdr *)skb_network_header(sock_buf);
		if (ip_header == NULL) {
			return NF_ACCEPT;	
		} else {
			switch (ip_header->protocol) {
		
#endif
    return 0;
}
EXPORT_SYMBOL_GPL(my_conntrack_basic);

static unsigned int conntrack_basic(unsigned int hooknum,
				    struct sk_buff *skb,
				    const struct net_device *in,
				    const struct net_device *out,
				    int (*okfn)(struct sk_buff *)) {
	return my_conntrack_basic(dev_net(in), PF_INET, hooknum, skb);
}

MODULE_ALIAS("conntrack-" __stringify(AF_INET));
MODULE_ALIAS("conntrack");
MODULE_LICENSE("GPL");

static int __init conntrack_init(void) {
	int ret = 0;

	ret = nf_register_hooks(conntrack_ops,
				ARRAY_SIZE(conntrack_ops));

	if (ret < 0) {
		pr_err("%d:%s:conntrack: can't register hooks.\n", __LINE__, __FILE__);
		goto cleanup_hooks;
	}

	pr_info("%d:%s:conntrack: can't register hooks.\n", __LINE__, __FILE__);

	return ret;

cleanup_hooks:
	nf_unregister_hooks(conntrack_ops, ARRAY_SIZE(conntrack_ops));
	return ret;
}

static void __exit conntrack_fini(void) {
	nf_unregister_hooks(conntrack_ops, ARRAY_SIZE(conntrack_ops));
}

module_init(conntrack_init);
module_exit(conntrack_fini);

MODULE_AUTHOR("Ashutosh Shanker <ashutoshshanker22@gmail.com>");
MODULE_DESCRIPTION("Connection Tracking for network traffic");
