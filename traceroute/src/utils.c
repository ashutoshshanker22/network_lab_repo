#ifndef _TRACEROUTE_H
#define _TRACEROUTE_H
#include <traceroute.h>
#endif

void usage(void) {
    printf("Usage: traceroute-ts [OPTIONS]\n\n");
    printf("\t-d,  set debug flag in socket options.\n");
    printf("\t-I,  use ICMP protocol to do traceroute.\n");
    printf("\t-V,  enable debug or verbose mode.\n");
    printf("\t-i <ifname>,  provide interface name on which you want to");
    printf("perform traceroute.\n");
    printf("\t-m <max_ttl>,  provide max_ttl value\n");
    printf("\t-P <proto>,  provide protocol (tcp,icmp,udp..) value\n");

    return;
}

void print_arg(struct argument *arg) {
    printf("\t-d %d\n", arg->options);
    printf("\t-I %s\n", arg->proto);
    printf("\t-V %d\n", arg->debug);
    printf("\t-i %s\n", arg->device);
    printf("\t-m %d\n", arg->max_ttl);
    printf("\t-P %s\n", arg->proto);
    return;
}

