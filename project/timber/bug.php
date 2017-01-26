<HTML>
<HEAD>
	<TITLE>TIMBER</TITLE>
	<META HTTP-EQUIV = "Content-Type" CONTENT = "text/html; CHARSET = ISO-8859-1">
	<SCRIPT language = "JavaScript">
		function validateForm()
		{
			if (document.bugForm.description.value == "Please explain in as much detail as possible")
			{
				document.bugForm.description.value = "";
			}

			if (document.bugForm.description.value == "")
			{
				alert("Please describe the error");
				document.bugForm.description.focus();
			}
			else
			{
				document.bugForm.submit();
				return true;
			}
		}
		function initializeForm()
		{
			document.bugForm.description.value = 'Please explain in as much detail as possible';
		}
		function offset_dialog_winxp()
		{
			window.open('offset_dialog_winxp.html','offset_dialog_winxp','height = 700, width = 600,resizable = yes, scrollbars = yes');
		}
		function location_dialog_win2k()
		{
			window.open('location_dialog_win2k.html','location_dialog_win2k','height = 200, width = 700,resizable = yes, scrollbars = yes');
		}
		function exception_dialog_winxp()
		{
			window.open('exception_dialog_winxp.html','exception_dialog_winxp','width = 600,resizable = yes, scrollbars = yes');
		}
		function exception_dialog_win2k()
		{
			window.open('exception_dialog_win2k.html','exception_dialog_win2k','height = 200, width = 700,resizable = yes, scrollbars = yes');
		}
		</SCRIPT>
</HEAD>
<BODY BGCOLOR = "#FFFFFF" onLoad = "initializeForm()">
	<TABLE WIDTH = 600 BORDER = 0 CELLSPACING = 0 CELLPADDING = 10 ALIGN = "CENTER" BORDERCOLORLIGHT = "#FFFFFF" BORDERCOLORDARK = "#CCFFFF">
		<TR ALIGN = "CENTER" VALIGN = "BOTTOM" BGCOLOR = "#6666FF"> 
			<TD COLSPAN = 2 HEIGHT = 100><DIV ALIGN = \"CENTER\"><IMG SRC = "timber2.gif" WIDTH = 477 HEIGHT = 128></DIV></TD>
		</TR>
		<TR> 
			<TD WIDTH = 100 VALIGN = "TOP" BGCOLOR = "#CCFFCC"> 
				<P>&nbsp;</P>
				<P><A HREF = "introduction.html">Introduction</A></P>
				<P><A HREF = "overview.html">Overview</A></P>
				<P><A HREF = "support.html">Support</A></P>
				<P><A HREF = "people.html">People</A></P>
				<P><A HREF = "publications.html">Publications</A></P>
				<P><A HREF = "download.php">Download</A></P>
				<P><A HREF = "usermanual/index.htm">User manual</A></P>
				<P><A HREF = "bug.php">Report bugs</A></P>
				<P><A HREF = "links.html">Useful links</A></P>
			</TD>
			<TD BGCOLOR = "#CCCCFF" VALIGN = "TOP" ALIGN = "LEFT " WIDTH = 454> 
			<H2>Error Report</H2>
<?
			if (!isset($_POST["description"]))
			{
				echo	"<FORM NAME = \"bugForm\" ACTION = \"bug.php\" METHOD = \"post\">
							<TABLE ALIGN = \"CENTER\">
							<TR>
								<TD COLSPAN = 4>Query</TD>
							</TR>
							<TR>
								<TD COLSPAN = 4 ALIGN = \"CENTER\"><TEXTAREA NAME = \"query\" ROWS = 5 COLS = 50></TEXTAREA></TD>
							</TR>
							<TR><TD COLSPAN = 4>&nbsp;</TD></TR>
							<TR>
								<TD ALIGN = \"CENTER\" WIDTH = \"20%\">Build Version</TD>
								<TD COLSPAN = 2  ALIGN = \"CENTER\" WIDTH = \"60%\">Module / File</TD>
								<TD ALIGN = \"CENTER\" WIDTH = \"20%\">Line number</TD>
							</TR>
							<TR>
								<TD ALIGN = \"CENTER\" WIDTH = \"20%\"><INPUT NAME = \"version\" SIZE = 10></TD>
								<TD COLSPAN = 2 ALIGN = \"CENTER\" WIDTH = \"60%\"><INPUT NAME = \"module\" SIZE = 30></TD>
								<TD ALIGN = \"CENTER\" WIDTH = \"20%\"><INPUT NAME = \"line\" SIZE = 10></TD>
							</TR>
							<TR><TD COLSPAN = 4>&nbsp;</TD></TR>
							<TR>
								<TD COLSPAN = 2 ALIGN = \"CENTER\" WIDTH = \"50%\">Location / Offset (hex)</TD>
								<TD COLSPAN = 2 ALIGN = \"CENTER\" WIDTH = \"50%\">Exception (hex)</TD>
							</TR>
							<TR>
								<TD COLSPAN = 2 ALIGN = \"CENTER\" WIDTH = \"50%\"><INPUT NAME = \"offset\"></TD>
								<TD COLSPAN = 2 ALIGN = \"CENTER\" WIDTH = \"50%\"><INPUT NAME = \"exception\"></TD>
							</TR>
							<TR>
								<TD COLSPAN = 2 ALIGN = \"CENTER\" WIDTH = \"50%\">
									<A HREF = \"javascript:offset_dialog_winxp()\">Win XP</A>
									&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
									<A HREF = \"javascript:location_dialog_win2k()\">Win 2000</A>
								</TD>
								<TD COLSPAN = 2 ALIGN = \"CENTER\" WIDTH = \"50%\">
									<A HREF = \"javascript:exception_dialog_winxp()\">Win XP</A>
									&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
									<A HREF = \"javascript:exception_dialog_win2k()\">Win 2000</A>
								</TD>
							</TR>
							<TR><TD COLSPAN = 4>&nbsp;</TD></TR>
							<TR>
								<TD COLSPAN = 4 ALIGN = \"CENTER\">Description</TD>
							</TR>
							<TR>
								<TD COLSPAN = 4 ALIGN = \"CENTER\"><TEXTAREA NAME = \"description\"  ROWS = 10 COLS = 50 onFocus = \"document.bugForm.description.value = ''\"></TEXTAREA></TD>
							</TR>
							<TR>
								<TD COLSPAN = 4>&nbsp;</TD>
							</TR>
							<TR>
								<TD WIDTH = \"10%\">&nbsp;</TD>
								<TD WIDTH = \"30%\">E-mail</TD>
								<TD WIDTH = \"60%\"><INPUT NAME = \"email\" SIZE = 30></TD>
							</TR>
							<TR>
								<TD COLSPAN = 4>&nbsp;</TD>
							</TR>
							<TR>
								<TD COLSPAN = 4 ALIGN = \"CENTER\">
									<INPUT onClick = 'validateForm()' TYPE = \"BUTTON\" VALUE = \"Submit\">
									<INPUT TYPE = \"RESET\" VALUE = \"Reset\">
								</TD>
							</TR>
						</TABLE>
					</FORM>";
			}
			else
			{
				mysql_connect("localhost","timber","zKwTtBYw") or die("Unable to connect to MySQL server"); 
				mysql_select_db("timberbugs") or die("Unable to select database");

				$rows = mysql_query("SELECT DATE_TIME FROM bugs");
				$id = mysql_num_rows($rows) + 1;

				$date_time = date('Y-m-d h:i:s');

				$insert = mysql_query("INSERT INTO bugs VALUES('" . $id . "','" . urlencode($_POST["query"]) . "','" . urlencode($_POST["version"]) . "','" . urlencode($_POST["module"]) . "','" . urlencode($_POST["line"]) . "','" . urlencode($_POST["offset"]) . "','" . urlencode($_POST["exception"]) . "','" . urlencode($_POST["description"]) . "','" . urlencode($_POST["email"]) . "','" . $date_time . "')");

				echo "<P ALIGN = \"CENTER\">Thank you for your feedback!</P>";
				echo "<P ALIGN = \"CENTER\"><A HREF = \"bug.php\">Back</A></P>";
			}
?>
				<HR />
				<P ALIGN = "RIGHT">
				 <IMG SRC = "email.gif" /><I><FONT SIZE =i 2><BR>Page last modified on 09/May/06</FONT></I>
				</P>
			</TD>
		</TR>
	</TABLE>
</BODY>
</HTML>
