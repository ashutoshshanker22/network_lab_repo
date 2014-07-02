#include <traceroute.h>

extern int optind;
extern int opterr;
extern char *optarg;



char *device = NULL;
int max_ttl = 64;
char proto[100] = {0};
int debug = 0;
int options = 0; // socket options

#if 0
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

void print_arg(void) {
    printf("\t-d %d\n", options);
    printf("\t-I %s\n", proto);
    printf("\t-V %d\n", debug);
    printf("\t-i %s\n", device);
    printf("\t-m %d\n", max_ttl);
    printf("\t-P %s\n", proto);
    return;
}
#endif

int main(int argc, char *argv) {
    int op = -1;
    struct argument *arg = NULL;

    arg = (struct argument *)malloc(sizeof(struct argument));
    if (arg == NULL) {
        log_error("%s:%d : main() Malloc error\n", __FILE__, __LINE__);
    }
    
    opterr = 0;
    while ((op = getopt(argc, (char * const *)argv, "dIVi:m:P:")) != EOF) {
        switch (op) {
            case 'd':
                options = 10;
                arg->options = options;
                break;

            case 'I':
                strncpy(proto, "ICMP", strlen("ICMP") + 1);
                strncpy(arg->proto, "ICMP", strlen("ICMP") + 1);
                break;

            case 'i':
                device = optarg;
                arg->device = optarg;
                break;

            case 'V':
                debug = 1;
                arg->debug = 1;
                break;

            case 'm':
                max_ttl = atoi(optarg);
                arg->max_ttl = max_ttl;
                break;

            case 'P':
                strncpy(proto, optarg, strlen(optarg) + 1);
                strncpy(arg->proto, optarg, strlen(optarg) + 1);
                break;

            default:
                usage();
                break;
        }
    }
    if (debug) {
        print_arg(arg);
    }
    free(arg);
	return 0;
}
