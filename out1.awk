BEGIN{ dropped_n2 = 0; received_n3 = 0;}
{
# type, time, from node, to node, pkt type, pkt size, flags, FID
if($1=="r" && $4=="3" && $5=="tcp" && $6=="1540"){ received_n3++; }
if($1=="d" && $3=="2" && $5=="tcp" && $6=="1540"){ dropped_n2++; }
}
END{
printf("Dropped at n2: %d\n",dropped_n2);
printf("Received at n3: %d\n",received_n3);
}
