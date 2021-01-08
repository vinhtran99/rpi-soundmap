<?php
$log_file = 'testcurl.txt';
$name = $_POST['name'];
$email = $_POST['email'];
date_default_timezone_set("UTC");
$str = gmdate("M d Y H:i:s", time()).' '.$name.' '.$email."\n";
echo "This is from the server";
// now we open the file
if(file_exists($log_file)){
	$fp=fopen($log_file,a); // the file is opened as append mode
	fwrite($fp, $str);
	fclose($fp);
}else{	// the file doesn't exist, so open a new one.
	$fp = fopen($log_file,w);
	fwrite($fp, $str);
	fclose($fp);

}
?>
