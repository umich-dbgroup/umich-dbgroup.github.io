###########################################################
#  Count 'n Log 1.0 Program 				  #
#  Written by Jason W. Maloney - January 24, 1998         #
#                      Updated - February 22, 2001        #
#							  #
#  This script is very easy to set-up, even for those     #
#  just starting out with CGI.  It shouldn't take longer  #
#  than 10 minutes to get it up and running. It has been  #
#  tested on UNIX & NT and no problems were discovered.	  #
#							  #
#  MAKE SURE THAT YOU READ OVER THE TERMS OF AGREEMENT    #
#  BEFORE USING THIS SCRIPT.  BY USING THIS SCRIPT,       #
#  YOU ARE AGREEING TO ABIDE BY THEM.  HOWEVER, IF YOU    #
#  DON'T AGREE WITH IT, THEN DON'T USE MY SCRIPTS.  ALSO, #
#  PLEASE READ THE 'README.TXT' FILE BEFORE INSTALLING.   #
#  KEEP IN MIND THAT JASON'S SCRIPTS & THE AESTHETIC      #
#  SURGERY CENTER SHALL NOT BE HELD LIABLE FOR ANY        #
#  DAMAGES THAT MAY OCCUR FROM DOWNLOADING AND/OR         #
#  INSTALLING MY PROGRAMS. IN SHORT, DOWNLOAD AND USE MY  #
#  PROGRAMS AT YOUR OWN RISK! IF YOU DO NOT AGREE WITH    #
#  THIS, THEN DO NOT USE ANY OF MY PROGRAMS.              #
#							  #
###########################################################


THIS SCRIPT WILL NOT WORK UNLESS YOU CHANGE IT TO UNIX FORMAT
because when you edit it, it adds hidden ^M to the end of each line and you
need to get rid of them.  Here's how I do it.

  1.) Change the script and then upload the three files by 'FTP.'
  2.) 'Telnet' to your website and locate the directory where you are
      storing the files, usually 'cd <filename>'.  In my case, I keep them in the
      directory called scripts, so i would type 'cd scripts'. 
  3.) Then I change the script from dos to unix by the command 'dos2unix count.cgi > count2.cgi'.
      and hit enter.  
  4.) At the next prompt type 'mv count2.cgi > count.cgi' and enter. This moves the script from count2.cgi
      back to the name count.cgi
  5.) Then make it (chmod) by typing 'chmod 755 count.cgi' and then enter.
  6.) The remaining two files only need to be 'chmod 766 counter.dat' and
      and 'chmod 766 log.dat'.

Three of the four files enclosed need special read/write/excute properties:
count.cgi   	-  chmod 755
log.dat		-  chmod 766
counter.dat	-  chmod 766

################################


######################
#Change the following#
######################

#This excludes YOUR computer from affecting the 'counter.dat' & 
#the 'log.dat' files from being updated when you call the page.
#If so, enter your IP address. Otherwise, enter "0" 

$your_ip = "000.000.000.000";  

#This is the directory where your 'counter.dat' and 'log.dat'
#files will be kept.  For instance, this counter is found on
#the page 'http://www.aestheticsurgerycenter.com/script/index.shtml'. 
#You MUST have the complete directory or else it won't work.  
#If you don't know it, ask your service provider.  This 
#directory will only work at www.wideworldmart.com - so change it!

$directory = "/mnt/web/guide/aestheticsurgerycenter/";

#If you want the counter to display on the 'shtml' page,
#let $print = '1', or if you prefer to keep it hidden let
#$print = '0'.

$print = '1';

#The 'counter.dat' file will only count the number of hits,
#and 'log.dat' file stores the date, what previous page the person
#came from, their internet access provider, and the brower they
#use.  Both files are hidden and need to be in the same directory 
#as 'count.cgi', also they need to be 'chmod 766'.
 
$count = "counter.dat";
$log = "log.dat";

###########################################

Also, you need to add the following line to your '.html' page, 
and change the extension from '.html' to '.shtml'.


<!--#exec cgi="http://www.yourdoamin.com/count.cgi"-->
                 -or-
<!--#exec cgi="/count.cgi"-->

################################
################################
################################
In opening up the script, keep in mind, it is very easy to use. 
As you can tell the script isn't very long and doesn't take much
for it to work. However, if you should encounter any problems
please feel free to e-mail me at 'malonejr@bc.edu'

All three files need to be in the same file, else it won't
work. Remember to change the directory!

Thank you,
Jason Maloney