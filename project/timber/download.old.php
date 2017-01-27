<HTML>
<HEAD>
    <TITLE>TIMBER</TITLE>
    <META HTTP-EQUIV = "Content-Type" CONTENT = "text/html; CHARSET = ISO-8859-1">
    <SCRIPT language = "JavaScript">
        function validateForm()
        {
            if (document.downloadForm.name.value == "")
            {
                alert("Please enter your name");
                document.downloadForm.name.focus();
            }
            else if (checkEmail(document.downloadForm.email.value) == false)
            {
                return false;
            }
            else if (document.downloadForm.designation.value == "")
            {
                alert("Please enter your designation");
                document.downloadForm.designation.focus();
            }
            else if (document.downloadForm.institution.value == "")
            {
                alert("Please enter your institution");
                document.downloadForm.institution.focus();
            }
            else
            {
                document.downloadForm.submit();
                return true;
            }
        }
        function checkEmail(e)
        {
            var at = "@";
            var dot = ".";
            var idxAt = e.indexOf(at);
            var len = e.length;
            if ((e.indexOf(at) == -1 || e.indexOf(at) == 0 || e.indexOf(at) == len)
                || (e.indexOf(dot) == -1 || e.indexOf(dot) == 0 || e.indexOf(dot) == len)
                || (e.indexOf(at,(idxAt + 1)) != -1)
                || (e.substring(idxAt - 1,idxAt) == dot || e.substring(idxAt + 1,idxAt + 2) == dot)
                || (e.indexOf(dot,(idxAt + 2)) == -1)
                || (e.indexOf(" ") != -1))
            {
                alert("Please enter a valid e-mail address");
                document.downloadForm.email.focus();
                return false;
            }
            return true;                    
        }
        </SCRIPT>
</HEAD>
<BODY BGCOLOR = "#FFFFFF">
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
            <H2>Download</H2>
<?
            if (!isset($_POST["name"]))
            {

                echo    "<P>TIMBER source files are available for download upon completion of this simple registration form. (Click <A HREF = \"SampleQueries.zip\">here</A> to download sample queries that TIMBER supports).</P>
                    <BR />
                    <FORM NAME = \"downloadForm\" ACTION = \"download.php\" METHOD = \"post\">
                        <TABLE ALIGN = \"CENTER\">
                            <TR>
                                <TD COLSPAN = 3 ALIGN = \"CENTER\"><B>User Information</B></TD>
                            </TR>
                            <TR><TD COLSPAN = 3>&nbsp;</TD></TR>
                            <TR>
                                <TD WIDTH = \"10%\">&nbsp;</TD>
                                <TD WIDTH = \"30%\">Name</TD>
                                <TD WIDTH = \"60%\"><INPUT NAME = \"name\" SIZE = 30></TD>
                            </TR>
                            <TR>
                                <TD WIDTH = \"10%\">&nbsp;</TD>
                                <TD WIDTH = \"30%\">E-mail</TD>
                                <TD WIDTH = \"60%\"><INPUT NAME = \"email\" SIZE = 30></TD>
                            </TR>
                            <TR>
                                <TD WIDTH = \"10%\">&nbsp;</TD>
                                <TD WIDTH = \"30%\">Designation</TD>
                                <TD WIDTH = \"60%\"><INPUT NAME = \"designation\" SIZE = 30></TD>
                            </TR>
                            <TR>
                                <TD WIDTH = \"10%\">&nbsp;</TD>
                                <TD WIDTH = \"30%\">Institution</TD>
                                <TD WIDTH = \"60%\"><INPUT NAME = \"institution\" SIZE = 30></TD>
                            </TR>
                            <TR><TD COLSPAN = 3>&nbsp;</TD></TR>
                            <TR ALIGN = \"CENTER\">
                                <TD WIDTH = \"50%\" COLSPAN = 3>
                                    <INPUT TYPE = \"RESET\" VALUE = \"Reset\">
                                </TD>
                            </TR>
                            <TR><TD COLSPAN = 3>&nbsp;</TD></TR>
                            <TR>
                                <TD COLSPAN = 3 ALIGN = \"CENTER\"><B>License Agreement</B></TD>
                            </TR>
                            <TR><TD COLSPAN = 3>&nbsp;</TD></TR>
                            <TR>
                                <TD COLSPAN = 3 ALIGN = \"CENTER\">
<TEXTAREA ROWS = 35 COLS = 50 READONLY>COPYRIGHT  © 2000-2004 THE REGENTS OF THE UNIVERSITY OF MICHIGAN
ALL RIGHTS RESERVED

PERMISSION IS GRANTED TO USE, COPY, CREATE DERIVATIVE WORKS AND REDISTRIBUTE THIS SOFTWARE AND SUCH DERIVATIVE WORKS FOR 
NONCOMMERCIAL EDUCATION AND RESEARCH PURPOSES, SO LONG AS NO FEE IS CHARGED, AND SO LONG AS THE COPYRIGHT NOTICE ABOVE, 
THIS GRANT OF PERMISSION, AND THE DISCLAIMER BELOW APPEAR IN ALL COPIES MADE; AND SO LONG AS THE NAME OF THE UNIVERSITY 
OF MICHIGAN IS NOT USED IN ANY ADVERTISING OR PUBLICITY PERTAINING TO THE USE OR DISTRIBUTION OF THIS SOFTWARE WITHOUT 
SPECIFIC, WRITTEN PRIOR AUTHORIZATION.

THIS SOFTWARE IS PROVIDED AS IS, WITHOUT REPRESENTATION FROM THE UNIVERSITY OF MICHIGAN AS TO ITS FITNESS FOR ANY PURPOSE, 
AND WITHOUT WARRANTY BY THE UNIVERSITY OF MICHIGAN OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION THE 
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. THE REGENTS OF THE UNIVERSITY OF MICHIGAN SHALL 
NOT BE LIABLE FOR ANY DAMAGES, INCLUDING SPECIAL, INDIRECT, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, WITH RESPECT TO ANY CLAIM 
ARISING OUT OF OR IN CONNECTION WITH THE USE OF THE SOFTWARE, EVEN IF IT HAS BEEN OR IS HEREAFTER ADVISED OF THE POSSIBILITY 
OF SUCH DAMAGES.</TEXTAREA></TD>
                            </TR>
                            <TR>
                                <TD>&nbsp;</TD>
                            </TR>
                            <TR>
                                <TD COLSPAN = 3><B>I / We also agree to abide by the licensing terms of all the component pieces of software (available <A HREF = \"licenses.zip\">here</A>).</B></TD>
                            </TR>
                            <TR ALIGN = \"CENTER\">
                                <TD WIDTH = \"50%\" COLSPAN = 3>
                                    <INPUT onClick = 'validateForm()' TYPE = \"BUTTON\" VALUE = \"Agree\">
                                </TD>
                            </TR>
                        </TABLE>
                    </FORM>";
            }
            else
            {
                mysql_connect("localhost","timber","zKwTtBYw") or die("Unable to connect to MySQL server"); 
                mysql_select_db("timberbugs") or die("Unable to select database");

                $rows = mysql_query("SELECT EMAIL FROM downloads");

                $id = mysql_num_rows($rows) + 1;

                $version = "1.0";
                $date_time = date('Y-m-d h:i:s');
        
                $insert = mysql_query("INSERT INTO downloads VALUES('" . $id . "','" . $_POST["name"] . "','" . $_POST["email"] . "','" . $_POST["designation"] . "','" . $_POST["institution"] . "','" . $date_time . "','" . $version . "')");

                echo "<TABLE CELLSPACING = 1 CELLPADDING = 2 ALIGN = \"CENTER\">
                        <TR>
                            <TD COLSPAN = 2 ALIGN = \"CENTER\"><B>Source Files</B></TD>
                        </TR>
                        <TR>
                            <TD COLSPAN = 2>&nbsp;</TD>
                        </TR>
                        <TR>
                            <TD WIDTH = \"50%\">TIMBER Project</TD>
                            <TD WIDTH = \"50%\"><A HREF = \"Timber.zip\">Timber.zip</TD>
                        </TR>
                        <TR>
                            <TD WIDTH = \"50%\">XQuery Parser Project</TD>
                            <TD WIDTH = \"50%\"><A HREF = \"XQueryParser.zip\">XQueryParser.zip</TD>
                        </TR>
                        <TR>
                            <TD WIDTH = \"50%\">TIMBER Web Interface</TD>
                            <TD WIDTH = \"50%\"><A HREF = \"TimberWebInterface.zip\">TimberWebInterface.zip</TD>
                        </TR>
                        <TR>
                            <TD WIDTH = \"50%\">Help</TD>
                            <TD WIDTH = \"50%\"><A HREF = \"README.txt\">README</TD>
                        </TR>
                        <TR>
                            <TD COLSPAN = 2>&nbsp;</TD>
                        </TR>
                        <TR>
                            <TD COLSPAN = 2>&nbsp;</TD>
                        </TR>
                        <TR>
                            <TD COLSPAN = 2 ALIGN = \"CENTER\"><B>Auxiliary Components</B></TD>
                        </TR>
                        <TR>
                            <TD COLSPAN = 2 ALIGN = \"CENTER\">(to be downloaded and installed separately)</TD>
                        </TR>
                        <TR>
                            <TD COLSPAN = 2>&nbsp;</TD>
                        </TR>
                        <TR>
                            <TD WIDTH = \"50%\">Berkeley DB</TD>
                            <TD WIDTH = \"50%\"><A HREF = \"http://www.sleepycat.com/download/index.shtml\">Sleepycat Software</TD>
                        </TR>
                        <!--TR>
                            <TD WIDTH = \"50%\">Microsoft XML Parser</TD>
                            <TD WIDTH = \"50%\"><A HREF = \"http://www.microsoft.com/downloads/details.aspx?familyid=3144b72b-b4f2-46da-b4b6-c5d7485f2b42&displaylang=en\">MSXML 4.0 Service Pack 2</TD>
                        </TR-->
                        <TR>
                            <TD WIDTH = \"50%\">Axis Web Services</TD>
                            <TD WIDTH = \"50%\"><A HREF = \"http://ws.apache.org/axis/\">The Apache Axis Project</TD>
                        </TR>
                    </TABLE>
                    <BR /><BR />";

//              mail($_POST["email"],"Registration Confirmation","Thank you for downloading TIMBER!\n\nPlease contact us (timber@umich.edu) if you have any comments / questions.");
            }
?>
                <HR />
                <P ALIGN = "RIGHT">
                <A HREF = "mailto:timber@umich.edu"><FONT SIZE = 2><I>timber@umich.edu</I></FONT></A>
                <I><FONT SIZE = 2><BR />Page last modified on 26/July/04</FONT></I>
                </P>
            </TD>
        </TR>
    </TABLE>
</BODY>
</HTML>
