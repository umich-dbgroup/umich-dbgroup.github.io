#!/usr/local/bin/perl

$your_ip = "141.212.98.47";  
$directory = "/w/web/db/MiMI/";
$print = '0';
$count = "counter.dat";
$log = "log.dat";

##############
#Script Begins

$shortdate = `date +"%D %T %Z"`; 
chop ($shortdate);

if ($ENV{'REMOTE_ADDR'} eq $your_ip) {               
} 
  
else {
    open (COUNT, "$directory$count");
    $counter = <COUNT>;
    close (COUNT);
    open (COUNT, "> $directory$count");
    $counter += 1;
    print COUNT "$counter";
    close (COUNT);

    open (LOG, ">>$log");
    print "Content-type: text/plain\n\n ";
    print LOG "Time: $shortdate\n";
    print LOG "Host: $ENV{'REMOTE_HOST'}\n";
    print LOG "With: $ENV{'HTTP_USER_AGENT'}\n";
    print LOG "From: $ENV{'HTTP_REFERER'}\n\n";
    close (LOG);  

      if ($print eq '1') {               
    print "$counter"; 
      }
}
exit;
