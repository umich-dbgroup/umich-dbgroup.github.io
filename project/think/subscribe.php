<?php 
	if(isset($_POST['email'])) {
		// Send email
		$crlf = "\r\n";
		$to = 'ffarfan@eecs.umich.edu';
		$from = $_POST['email'];
		
		
		// Message to myself
		$to = 'ffarfan@eecs.umich.edu';
		$from = $_POST['email'];
		
		$subject = 'THINK Website :: email-subscription';
		// Put all the information together in the message
		$message = 'Hello, there is a new message sent from the THINK Website. ' . $crlf . $crlf . 
				'Email: ' . $from . $crlf;
		
		mail($to, $subject, $message, 'From: think@umich.edu');
		
		
		// Message to subscriber
		$from = 'ffarfan@eecs.umich.edu';
		$to = $_POST['email'];
		
		$subject = 'Thank you for subscribing to THINK-Back!';
		// Put all the information together in the message
		$message = 'Thank you for subscribing to the THINK-Back Project Mailing list! We will send email notifications regarding the availability of our Web services soon!' . $crlf;
		
		mail($to, $subject, $message, 'From: think@umich.edu');
	}
	header('location:http://eecs.umich.edu/db/think/');
?>
