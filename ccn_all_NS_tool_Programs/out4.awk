BEGIN{}
{
#event, time, from, to, pkt type, pkt size, Flags, FID
if($6=="cwnd_"){
printf("%f \t %f\n",$1,$7);
}
}
END{}
