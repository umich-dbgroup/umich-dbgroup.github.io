<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="content-type" content="text/html; charset=utf-8" />
<title>THINK Back :: KNowledge-based Interpretation of High Throughput data</title>
<meta name="keywords" content="" />
<meta name="description" content="" />
<link href="css/think.css" rel="stylesheet" type="text/css" />
<!--[if lte IE 7]>     
<style type="text/css" media="all">     
@import "css/think-ie.css";     
</style>    
<![endif]-->
<script type="text/javascript">

  var _gaq = _gaq || [];
  _gaq.push(['_setAccount', 'UA-18763305-1']);
  _gaq.push(['_trackPageview']);

  (function() {
    var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
    ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
  })();

</script>
</head>
<body>
<div id="wrapper">
<!-- start header -->
<div id="header">
	<div id="logo">
		<h1><a href="http://www.eecs.umich.edu/db/think/">THINK Back</a></h1>
		<h2>KNowledge-based Interpretation of High Throughput data</h2>
	</div>
	<div id="menu">
		<ul>
			<li><a href="http://eecs.umich.edu/db/think/">Home</a></li>
			<li><a href="http://eecs.umich.edu/db/think/research.html">Research</a></li>
			<li><a href="http://eecs.umich.edu/db/think/software.html">Software</a></li>
			<li><a href="http://eecs.umich.edu/db/think/people.html">People</a></li>
			<li class="last current_page_item"><a href="http://eecs.umich.edu/db/think/contact.php">Contact</a></li>
		</ul>
	</div>
</div>
<!-- end header -->
<!-- start page -->
<div id="page">
<?php 
	if(isset($_POST['email'])) {
		// Send email
		$crlf = "\r\n";
		$to = 'ffarfan@eecs.umich.edu';
		$from = $_POST['email'];
		
		$subject = 'THINK Website :: Message';
		// Put all the information together in the message
		$message = 'Hello, there is a new message sent from the THINK Website. ' . $crlf . $crlf . 
				'From: ' . $_POST['name'] . $crlf .
				'Email: ' . $from . $crlf .
				'Affiliation: ' . $_POST['affiliation'] . $crlf . $crlf .
				'Message: [[ ' . wordwrap($_POST['comment'], 70) . ' ]]';
				
		if(mail($to, $subject, $message, 'From: think@umich.edu')) {
			echo '<div id="notifications">Email sent successfully.</div>' . $crlf;
		} else {
			echo '<div id="notifications">The Email delivery failed. Please try again.</div>' . $crlf;
		}
	}
?>
	<!-- start content -->
	<div id="content">
		<div class="post">
			<h1 class="title">Contact Us</h1>
			<div class="entry">
				<p>The THINK Back project is developed at the <a href="http://www.cse.umich.edu/">Computer Science and Engineering Department</a> at the <a href="http://www.umich.edu">University of Michigan</a>.</p>
				<p>If you have questions, comments or suggestions, please send us an <a href="mailto:ffarfan@eecs.umich.edu">email</a>, or use the Contact Form.</p>
				
				<form action="contact.php" method="post">
					<fieldset>
						<legend><span>Contact Form</span></legend>
						<ol>
							<li>
								<label for="name">Name: <em><img src="images/required-star.gif" alt="required" /></em></label>
								<input type="text" id="name" name="name" size="40" maxlength="40" />
							</li>
							<li>
								<label for="email">Email: <em><img src="images/required-star.gif" alt="required" /></em></label>
								<input type="text" id="email" name="email" size="40" maxlength="40" />
							</li>
							<li>
								<label for="affiliation">Affiliation: </label>
								<input type="text" id="affiliation" name="affiliation" size="40" maxlength="40" />
							</li>
							<li>
								<label for="comment">Comment: </label>
								<textarea id="comment" name="comment" rows="3" cols="32"></textarea>
							</li>
						</ol>
					</fieldset>
					<fieldset class="submit">
						<input type="submit" id="submit" value="Submit" />
					</fieldset>
				</form>
			</div>
		</div>
	</div>
	<!-- end content -->
	<div style="clear: both;">&nbsp;</div>
</div>
<!-- end page -->
</div>
<!-- start footer -->
<div id="footer">
	<p id="legal">Copyright &copy; 2010. All Rights Reserved <a href="http://eecs.umich.edu">University of Michigan</a>.<br />
	CSS template from <a href="http://www.freecsstemplates.org/">Free CSS Templates</a>.</p>
</div>
<!-- end footer -->
</body>
</html>
