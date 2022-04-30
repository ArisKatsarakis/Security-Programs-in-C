#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "pcap.h"

typedef struct rules{
    char source_ip[100];
    char source_port[100];
    char destination_port[100];
    char destination_ip[100];
    char rules[100];
} rul;
int main(){
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
    

    
}