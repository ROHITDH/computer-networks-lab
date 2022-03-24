BEGIN{ pkt = 0; time = 0;}

{
#event, time, from, to, pkt type, pkt size, flags, FID 
if($1=="r" && $3=="3" && $4=="4")
{
pkt = pkt + $6;
time = $2;
printf("Packet: %f\t Time: %f\n",pkt,time);
}
}

END{
printf("throughput: %f Mbps\n",(pkt/time)*(8/1024));
}
