#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pcap.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <net/ethernet.h>
#define ETHER_ADDR_LEN 6
struct sniff_ethernet {
	u_char ether_dhost[ETHER_ADDR_LEN]; /* Destination host address */
	u_char ether_shost[ETHER_ADDR_LEN]; /* Source host address */
	u_short ether_type; /* IP? ARP? RARP? etc */
};
/* IP header */
struct sniff_ip {
	u_char ip_vhl;		/* version << 4 | header length >> 2 */
	u_char ip_tos;		/* type of service */
	u_short ip_len;		/* total length */
	u_short ip_id;		/* identification */
	u_short ip_off;		/* fragment offset field */
#define IP_RF 0x8000		/* reserved fragment flag */
#define IP_DF 0x4000		/* don't fragment flag */
#define IP_MF 0x2000		/* more fragments flag */
#define IP_OFFMASK 0x1fff	/* mask for fragmenting bits */
	u_char ip_ttl;		/* time to live */
	u_char ip_p;		/* protocol */
	u_short ip_sum;		/* checksum */
	struct in_addr ip_src,ip_dst; /* source and dest address */
};
#define IP_HL(ip)		(((ip)->ip_vhl) & 0x0f)
#define IP_V(ip)		(((ip)->ip_vhl) >> 4)

/* TCP header */
typedef u_int tcp_seq;

struct sniff_tcp {
	u_short th_sport;	/* source port */
	u_short th_dport;	/* destination port */
	tcp_seq th_seq;		/* sequence number */
	tcp_seq th_ack;		/* acknowledgement number */
	u_char th_offx2;	/* data offset, rsvd */
#define TH_OFF(th)	(((th)->th_offx2 & 0xf0) > 4)
	u_char th_flags;
#define TH_FIN 0x01
#define TH_SYN 0x02
#define TH_RST 0x04
#define TH_PUSH 0x08
#define TH_ACK 0x10
#define TH_URG 0x20
#define TH_ECE 0x40
#define TH_CWR 0x80
#define TH_FLAGS (TH_FIN|TH_SYN|TH_RST|TH_ACK|TH_URG|TH_ECE|TH_CWR)
	u_short th_win;		/* window */
	u_short th_sum;		/* checksum */
	u_short th_urp;		/* urgent pointer */
};
typedef struct rules{
    char source_ip[100];
    char source_port[100];
    char destination_port[100];
    char destination_ip[100];
    char rules[100];
} rul;

void my_packet_handler(u_char *args, const struct pcap_pkthdr *header,const u_char *packet);
int main(){
    // file opened
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_offline("smallFlows.pcap",error_buffer);
    FILE *rules; 
    char *buffer;
    rul rules_list[100];
    int rul_count = 0;
    int i =1;
    rules = fopen("rules.txt", "r");
    if (rules == NULL)
    {
        printf("No rules are created \n");
        return 1;
    }
    buffer = malloc(100 * sizeof(char));
    while (fscanf(rules, "%s %s %s %s %[^\n]",rules_list[rul_count].source_ip, rules_list[rul_count].source_port, rules_list[rul_count].destination_port, rules_list[rul_count].destination_ip, rules_list[rul_count].rules) != EOF)
    {   
        rul_count ++;
    }
    
    fscanf(rules, "%[^EOF]",buffer);
    printf("Rules Are: \n");
    for(i = 0; i < rul_count; i++){
        printf("%d)", i+1);
        printf("%s %s %s %s %s \n",rules_list[i].source_ip, rules_list[i].source_port, rules_list[i].destination_port, rules_list[i].destination_ip, rules_list[i].rules );
    }
    //CIDR NOTATION 1.0 = 1.0/24 for src ip
    //print info of the packet
    pcap_loop(handle,0,my_packet_handler,NULL);
    return 0;

    
}
void my_packet_handler(u_char *args,
 const struct pcap_pkthdr *header,const u_char *packet){
    struct ether_header *eth_header;
    const struct sniff_ethernet *eth;
    const struct sniff_ip *ip;
    const struct sniff_tcp *tcp;
    u_int size_ip;
    u_int size_tcp;

    printf("Header: length: %d \n",header->caplen);
    printf("Total-Length: %u \n",header->len);
    eth_header = (struct ether_header *) packet;
    eth = (struct sniff_ethernet*) (packet);
    ip = (struct sniff_ip*)(packet+14);
    size_ip = IP_HL(ip)*4;
    tcp = (struct sniff_tcp*)(packet+14+size_ip);
    size_tcp = TH_OFF(tcp)*4;
    printf("Source: %s Port: %d \n",inet_ntoa(ip->ip_src), ntohs(tcp->th_sport));
    printf(" Destination: %s Port: %d \n", inet_ntoa(ip->ip_dst),ntohs(tcp->th_dport) );
    
    
}