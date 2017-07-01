#!/usr/bin/perl
# Adapted from the script provided by Laura Falk.

print "Content-type: text/html\n\n";

$workdir = "/w/web/db/mbench/testcgi/cgi-bin";
$filename = "$workdir/logininfo";

my $haveLocked = false;

read (STDIN, $submission, $ENV{'CONTENT_LENGTH'});
umask(022);

#print "Received from Web page: ", $submission, "\n";

%entries = &url_decode(split(/[&=]/, $submission));

#print $entries;

chdir $workdir;

my $info;

$info[0] = $entries{'email'};

open(FILES, "$filename") or &error;
while(<FILES>) 
{
    my @u;
    @u = split(/::/,$_);
    shift (@u);

    # print "\"$info[0]\" ,  \"$u[0]\" <br>";

    #Check to see if the user has an entry already
    if ( $info[0] eq $u[0] )
    {
      print "It appears you have already registered the email address <b> $info[0].</b> <br>";
      print "If you don't remember your password, please send an email to <a href=\"mailto:jignesh\@umich.edu\">Jignesh M. Patel</a> to reset your password. </b>";
      exit;
    }

}

&LOCK($filename);
open(LIST,">>$filename") or &error;
$now = `date`;
chop ($now);
$now =~ s/:/-/g;
print LIST $now;
for ($i=0; $i<1; $i++)
{
   print LIST "::$info[$i]";
}

print LIST "::\n";
close(LIST);

&UNLOCK($filename);

print "You will be receiving an email at the address \"$info[0]\" with your password shortly. Please use your email address and password to download the software from the <a href=\"http://www.eecs.umich.edu/db/mbench/downloads.html\">
download site</a>. \n <BR>";

# print "\"$submission\"";

sub url_decode
{
# Decode a URL encoded string or array of strings
#    + -> space
#    %xx -> character xx

    foreach (@_) {
        tr/+/ /;
        s/%(..)/pack("c",hex($1))/ge;
    }
    @_;
}

sub error 
{
    print "Error incurred, please contact jignesh\@eecs.umich.edu \n";
    if ($haveLocked)
    {
       &UNLOCK($filename);
    }
    exit;
}

sub LOCK
{
    my($file_to_lock) = @_;

    $flock = join('',$file_to_lock,'.lock');

    $lock_flag=0;
    do {
        if (-r $flock) {
            sleep(1);
        }
        else {
             `/bin/ln $file_to_lock $flock`;
            $lock_flag=1;
        }
    } until ($lock_flag == 1);
    $haveLocked = true;
}

sub UNLOCK
{
    my($file_to_lock) = @_;

    $flock = join('',$file_to_lock,'.lock');
    `rm $flock`;
}
