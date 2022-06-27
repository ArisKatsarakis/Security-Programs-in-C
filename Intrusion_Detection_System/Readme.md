## Intrusion Detection System
Our IDS actually reads rules.txt and saves them in struct rul(definition in ids.h).
After we initialized the rules in the struct 
we analyze the pcap file using pcap_loop and the my_packet_handler.

Inside my_packet_handler parsing the header through the U_char *packet
we analyze it in eth_header,ip_header,tcp_header
Each one of them contains the dest,src ip port we need and 
compare it with our rules.
If rules are matched Outcome of the rule is append at alerts.txt
Files Used:
    1) ids.c
    2) ids.h
    3)rules.txt
    4) pcap example files
    5) alerts.txt (for the outcome)
Instructions: 
    1)make exec 
        Develops IDS
    2) make run 
        Runs ids 
        And prints alerts.txt 
        
