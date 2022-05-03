#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pcap.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <net/ethernet.h>
#include "ids.h"
rul rules_list[100];
int rul_count = 0;
void my_packet_handler(u_char *args, const struct pcap_pkthdr *header,const u_char *packet);
int main(){
    // file opened
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_offline("smallFlows.pcap",error_buffer);
    FILE *rules; 
    char *buffer;
    int i =1;
    
    rules = fopen("rules.txt", "r");
    if (rules == NULL)
    {
        printf("No rules are created \n");
        return 1;
    }
    buffer = malloc(100 * sizeof(char));
    while (fscanf(rules, "%s %s %s %s %[^\n]",rules_list[rul_count].source_ip, rules_list[rul_count].source_port, rules_list[rul_count].destination_ip, rules_list[rul_count].destination_port, rules_list[rul_count].rules) != EOF)
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
    int i = 0;
    FILE *fp = fopen("alerts.txt","a");
    //printf("Header: length: %d \n",header->caplen);
    //printf("Total-Length: %u \n",header->len);
    eth_header = (struct ether_header *) packet;
    eth = (struct sniff_ethernet*) (packet);
    ip = (struct sniff_ip*)(packet+14);
    size_ip = IP_HL(ip)*4;
    tcp = (struct sniff_tcp*)(packet+14+size_ip);
    size_tcp = TH_OFF(tcp)*4;
    //printf("Source: %s Port: %d \n",inet_ntoa(ip->ip_src), ntohs(tcp->th_sport));
    //printf(" Destination: %s Port: %d \n", inet_ntoa(ip->ip_dst),ntohs(tcp->th_dport) );
    for ( i = 0; i < rul_count; i++)
    {
        if (!strcmp(rules_list[i].source_ip,inet_ntoa(ip->ip_src)))
        {
            if (atoi(rules_list[i].source_port ) == ntohs(tcp->th_sport))
            {
                if(!strcmp(rules_list[i].destination_ip,inet_ntoa(ip->ip_dst))){
                    
                    if (atoi(rules_list[i].destination_port ) == ntohs(tcp->th_dport))
                    {
                        fprintf(fp,"%s \n",rules_list[i].rules); 
                    }
                    
                }
                
                
            }
            
        }
        
        
    }

    fclose(fp);
    
}