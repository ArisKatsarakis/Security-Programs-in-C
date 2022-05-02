#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pcap.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <net/ethernet.h>

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
    pcap_t *handle = pcap_open_offline("dhcp.pcapng",error_buffer);
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
    printf("Header: length: %d \n ",header->caplen);
    printf("Total-Length: %u\n",header->len);
    eth_header = (struct ether_header *) packet;
    for ( int i = 0; i < 6; i++)
    {
     printf("%d \n",eth_header->ether_shost[i]);

        /* code */
    }
    
    
}