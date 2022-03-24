BEGIN{
tcp_pkts_n0 = 0;
udp_pkts_n1 = 0;
}
{
# 1,   2,    3,    4
#type, time, from, to, pkt type, pkt size, flags, FID
if($1=="r" && $4=="2" && $5=="tcp" && $6=="1540"){tcp_pkts_n0++;}
if($1=="r" && $4=="2" && $5=="cbr" && $6=="1000"){udp_pkts_n1++;}

}
END{
printf("tcp packets sent by n0: %d\n", tcp_pkts_n0);
printf("udp packets sent by n1: %d\n", udp_pkts_n1);
}

