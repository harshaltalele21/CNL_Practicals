set ns [new Simulator]

$ns color 1 Red
$ns color 2 Green

set nf [open out2.nam w]
$ns namtrace-all $nf

####################3
proc finish {} {
	global ns nf
	$ns flush-trace
	close $nf
	exec nam out2.nam &
	exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n0 $n1 1.7Mb 10ms DropTail
$ns duplex-link $n2 $n3 2Mb 10ms DropTail
$ns duplex-link $n1 $n3 2Mb 10ms DropTail

$ns duplex-link-op $n0 $n2 orient right
##################
$ns duplex-link-op $n0 $n1 orient right-down
$ns duplex-link-op $n2 $n3 orient right-down
$ns duplex-link-op $n1 $n3 orient right

#######
$ns duplex-link-op $n2 $n3 queuePos 0.5

set tcp [new Agent/TCP]
$tcp set class_ 2
$ns attach-agent $n0 $tcp

set sink [new Agent/TCPSink]
$ns attach-agent $n3 $sink
################3
$ns connect $tcp $sink

set ftp [new Application/FTP]
###############
$ftp attach-agent $tcp
$ftp set type_ FTP
$tcp set fid_ 1

set udp [new Agent/UDP]
$ns attach-agent $n2 $udp

set null [new Agent/Null]
$ns attach-agent $n3 $null
###############
$ns connect $udp $null
#############
$udp set fid_ 2

set cbr [new Application/Traffic/CBR]
#################3
$cbr attach-agent $udp
$cbr set type_ CBR
$cbr set rate_ 1mb
$cbr set packet_size_ 1000
$cbr set random_ false

$ns rtproto DV

$ns rtmodel-at 2.0 down $n0 $n2
$ns rtmodel-at 2.5 down $n1 $n3

################
$ns at 0.1 "$cbr start"
$ns at 1.0 "$ftp start"
$ns at 4.0 "$ftp stop"
$ns at 4.5 "$cbr stop"

$ns at 5.0 "finish"

$ns run