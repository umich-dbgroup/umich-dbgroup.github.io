<?php

/*************************************************************
 * This php program checks whether the user has been registered
 * before and whether the user has a valid email address
 *
 * If the user has not been registered before and has a valid
 * email address, an email with a password is sent to the user
 *
 **************************************************************/

include("login_config.php");

/*********************************************************
* function make_password($length)
*
* This function returns a random string of length $length.
* It uses ascii values $MIN_ASCII_VAL to $MAX_ASCII_VAL inclusive,
* and will accept values of $MIN_LENGTH to $MAX_LENGTH for length.
*
* $MIN_ASCII_VAL is 34 instead of 33 because we use the ASCII 33
* as a delimiter between user and password
*
* Modified from function 'goodrandstring(int $length)' by
* Jeffrey Paul
********************************************************/
function make_password($length) 
{
  // check whether $length is a number
  if (!ereg("^[0-9]+$", $length))
    return(-1);
  
  // check whether $length value is in valid range
  if ($length < $min_passwd_len &&
      $length > $max_passwd_len)
    return(-1);

  srand((double)microtime()*1000000);

  $string = "";

  for ($i = 0; $i < $length; $i++)
  {
    $string = $string . chr(rand(34,126));
  }
  return ($string);
}

/********************************************************
 * function is_on_list($email)
 *
 * This function check whether $email has been registered
 * (in the list).
 * Return true if email address is on the list
 ********************************************************/
function is_on_list($email)         
{
  global $list_file, $field_del;
  $found = false;
  $file = fopen($list_file, "r"); 
  if (!$file)
  {
 		print "unable to open $list_file";
		exit;
  }
  while (!feof($file))
  {
    // read ends when length -1 bytes have been read, on
    // a newline or on EOF
    $line = fgets($file);
    $pos = strpos($line, $field_del);
    $addr = substr($line, 0, $pos);
    if (trim($addr) == trim($email))
    {
      $found = true;
    }
  }
  fclose($file);
  return $found;
}

/********************************************************
 * function is_valid_email($email)
 *
 * This function checks whether $email is a valid email.  
 * If the email is invalid, it returns false.
 *******************************************************/
function is_valid_email($email)
{
  // returns true if email address has a valid form

  // the first portion of the email needs to contain at least one but
  // likely more {alnum } alphanumeric (a-z or 0-9) character or the dash
  // symbol then there must be the @ symbol followed by at least one
  // but likely more alphanumeric characters and at least one period
  // mixed in there.

  if (strlen($email) == 0)
    return false;
  
  if (ereg("([[:alnum:]\.\-]+)(\@[[:alnum:]\.\-]+\.+)", $email))
    return true;
  else
    return false;
  
}
/*******************************************************
 * function send_passwd($recipient)
 *
 * This function sends a password to $recipient
 ******************************************************/
function send_passwd($recipient, $passwd)
{
  // declare the variables for sending mail
  global $admin_email, $download_site;
  $from = $admin_email;
  $subject = "MBench Registration Confirmation";
  $message =
    "Thank you for registering for downloading Mbench codes.
     Your password is $passwd \n Please download software at $download_site";

  //main() function sends the amil
  mail($recipient,$subject,$message,$mail,$from);
}

/*******************************************************
 * function add_to_list($email)
 *
 * This function adds the email of the user to the list
 * to record who has been registered
 ******************************************************/
function add_to_list($email, $passwd)
{
  global $list_file, $field_del;
  $fd = fopen($list_file,"a") or
    die("<center><b>The list file could not be opened</b></center>");
  $line = "$email$field_del$passwd\n";
  fputs($fd, $line);
  fclose($fd);
}

$email = strtolower($_POST["email"]);

if (is_valid_email($email))
{
  $passwd = make_password(8);
  if (!is_on_list($email))
  {
    add_to_list($email, crypt($passwd));
    send_passwd($email, $passwd);
    print "<center><b>Your password will be sent to $email";
    print " shortly. Your login username is the email address that you provided. Please use your login and password to <a href=\"$download_site\">download</a> the software.</b></center>";
  }
  else
  {
    print "<center><b>$email has already been registered.<br>
         Please send email to <a href=\"mailto:$admin_email\">administrator</a> if you want to register again.</center></b>";
  }
}
else
{
  print "<center><b>Your email address, $email, is invalid!</b></center>";
}


?>







