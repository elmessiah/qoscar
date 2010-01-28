<?php
include("reg_settings.ini");

$log="log.txt";

$regged="regged.txt";

$proxyfile1="proxy1.txt";

$cookdir="./cookies";

$good_proxy_file="good_proxy.txt";

$good_proxy_file1="good_tmp.txt";

$bad_proxy_file="bad_proxy.txt";

$bad_proxy_file1="bad_tmp.txt";

error_reporting(0);
set_time_limit(0);
ini_set("max_execution_time","0");
ini_set("memory_limit","9999M");
ini_set("output_buffering","0");
set_magic_quotes_runtime(0);
ignore_user_abort(1);
for ($w=1;$w<=$restarttimes;$w++) {
flush();

if (!@mkdir("$cookdir")) { $logprin4 = "[$today] COOK:  Folder exist: OK \r\n"; } else {
$logprin5 = "[$today] COOK: Folder doesn't not exist \r\n";
if (!@mkdir("$cookdir")) {
$logprin6 = "[$today] COOK: Folder successfully created \r\n"; } else { $logprin7 = "[$today] COOK: Can't create folder, Access denied!? FIX IT [CONSOLE ONLY]\r\n";$fp = fopen ( "$log" , "a+" );
 fwrite ( $fp , "$logprin7");
 fclose ( $fp ); sleep(100); die; }

 }
 $fp = fopen ( "$cookdir/test.txt" , "w+" );
 fwrite ( $fp , "test" );
 fclose ( $fp );
if (file_exists("$cookdir/test.txt")) { $logprin8 = "[$today] COOK:  Write test: OK \r\n"; } else { $logprin9 = "[$today] COOK: Can't create file, Access denied!? FIX IT [CONSOLE ONLY]\r\n";
$fp = fopen ( "$log" , "a+" );
 fwrite ( $fp , "$logprin9");
 fclose ( $fp );
  sleep(100); die; }

foreach (glob("$cookdir/*.txt") as $filename) {
   unlink($filename);
}

$acc=file("$accfile");
if (!file_exists("$accfile"))
{
$logprin10 = "!!! ERROR !!!!     ACC: ACCOUNTS LIST IS MISSING [$accfile]!!!! \r\n!!! ERROR !!!!     PROGRAM WILL BE CLOSED AFTER 10 sec";
$fp = fopen ( "$log" , "a+" );
 fwrite ( $fp , "$logprin10");
 fclose ( $fp );
 sleep(10);
die; }
foreach ($acc as $i => $acc) {  }
$u="$i";
$uinz=$u+1;
if($uinz<=2)
{
$logprin11 = "!!! ERROR !!!!     ACC: ACCOUNTS LIST IS NOT ENOUGH: ACCs:$uinz <= 2 [$accfile]!!!! \r\n!!! ERROR !!!!     PROGRAM WILL BE CLOSED AFTER 10 sec";
$fp = fopen ( "$log" , "a+" );
 fwrite ( $fp , "$logprin11");
 fclose ( $fp );
 sleep(10); die;
}
$fname   = "$accfile";
$handle  = fopen($fname, 'r');
$content = fread($handle, filesize($fname));
fclose($handle);
$handle  = fopen($fname, 'w');
$content = trim($content);
fwrite($handle, $content);
fclose($handle);
$today = date("H:i:s");
if($acc_delete=="1") { $g='ON'; } else { $g='OFF'; }
if($save_proxy_good=="1") { $l='YES'; } else { $l='NO'; }
$logprin12 = "[$today] REGG:  Attempt = $w of $restarttimes\r\n";
$logprin13 = "[$today] MAIL:  Total e-mails = $uinz\r\n";
$logprin14 = "[$today] MAIL:  Delete used e-mails = $g\r\n";
$logprin15 = "[$today] PROXY: TimeOut = $timeout\r\n";
$logprin16 = "[$today] PROXY: Save Good = $l\r\n";
$logprin17 = "__________________________________________________\r\n\r\n";
$acc=file("$accfile");
if (file_exists("$proxyfile1")) { if (file_exists("$proxyfile")) { unlink("$proxyfile"); } rename("$proxyfile1", "$proxyfile"); }
if("$update_proxyz"=="1") {
$logprin18 = "[$today] PROXY: Downloadind NEW.\r\n";
if (file_exists("$proxyfile")) {
 $fp = fopen ( "$proxyfile" , "a+" );
 fwrite ( $fp , "\r\n" );
 fclose ( $fp );}
 $proxies = file("$proxyurl");
 $size = count($proxies);
 $openfile = fopen("$proxyfile","a+");
  for($x=0;$x<$size;$x++){
    $line =trim($proxies[$x]);
    fwrite($openfile, $line);
     if($x!=$size-1){
      fwrite($openfile, "\r\n");
     }
  }
 fclose($openfile);
$logprin19 = "[$today] PROXY: Download completed.\r\n";
}

$text = file_get_contents("$proxyfile");
$text2 = str_replace("\r\n\r\n","\r\n","$text");
//$c=$c+1;
$fp = fopen ( "$proxyfile" , "w" );
fwrite ( $fp , "$text2" );
fclose ( $fp );

$fname   = "$proxyfile";
$handle  = fopen($fname, 'r');
$content = fread($handle, filesize($fname));
fclose($handle);
$handle  = fopen($fname, 'w');
$content = trim($content);
fwrite($handle, $content);
fclose($handle);

$proxz=file("$proxyfile");
if (!file_exists("$proxyfile")) { $logprin20 = "!!! ERROR !!!!     PROXY: LIST IS MISSING [$proxyfile]!!!! \r\n!!! ERROR !!!!     PROGRAM WILL BE CLOSED AFTER 10 sec"; $fp = fopen ( "$log" , "a+" );
 fwrite ( $fp , "$logprin20");
 fclose ( $fp );
 sleep(10); die; }
if(empty($proxz)) { $logprin21 = "!!! ERROR !!!!     PROXY: LIST IS EMPTY [$proxyfile]!!!! \r\n!!! ERROR !!!!     PROGRAM WILL BE CLOSED AFTER 10 sec";$fp = fopen ( "$log" , "a+" );
 fwrite ( $fp , "$logprin21");
 fclose ( $fp ); sleep(10); die; }
if("$duplicate_delete"=="1") {
foreach ($proxz as $i => $proxz) { }
$u="$i";
$proxzz=$u+1;
$foundprox = file("$proxyfile");
$foundprox = array_unique($foundprox);
foreach ($foundprox as $line) {
$f=fopen("$proxyfile1",'a+');
flock ($f,2);
fwrite($f,"$line");
fclose($f);}

$proxz=file("$proxyfile1");
foreach ($proxz as $i => $proxz) { }
$u="$i";
$proxzz2=$u+1;
$p=$proxzz-$proxzz2;
$logprin22 = "[$today] PROXY: Deleted duplicates: $p\r\n";
$logprin23 = "[$today] PROXY: Total before = $proxzz | Total after = $proxzz2\r\n";
if (file_exists("$proxyfile")) { unlink("$proxyfile"); }
rename("$proxyfile1", "$proxyfile");
}

if("$check_proxyz1"=="1") {
$today = date("H:i:s");
$logprin24 = "[$today] PROXY: Starting to checking [Method 1]. \r\n";

$url="http://profil.atlas.cz/ajaxvalidator.ashx";
$proxyes=file("$proxyfile");
 $mh = curl_multi_init();

 foreach ($proxyes as $i => $proxy) {
       $conn[$i]=curl_init($url);
       curl_setopt($conn[$i],CURLOPT_RETURNTRANSFER,1);
       curl_setopt($conn[$i],CURLOPT_PROXY,$proxy);
       curl_setopt($conn[$i],CURLOPT_TIMEOUT,$timeout);
       curl_multi_add_handle ($mh,$conn[$i]);
 }

 do { $n=curl_multi_exec($mh,$active); } while ($active);
 $p=0;
 $j=0;
 foreach ($proxyes as $i => $proxy) {
       $res[$i]=curl_multi_getcontent($conn[$i]);
       $bytez[$i]=strlen($res[$i]);
       if($bytez[$i]=="44")
{
 $fp = fopen ( "$proxyfile1" , "a+" );
 fwrite ( $fp , "$proxy" );
 fclose ( $fp );
 $p=$p+1;
} else { $j=$j+1; }
       curl_multi_remove_handle($mh,$conn[$i]);
       curl_close($conn[$i]);
 }
curl_multi_close($mh);
if (file_exists("$proxyfile")) { unlink("$proxyfile"); }
rename("$proxyfile1", "$proxyfile");
$today = date("H:i:s");
$logprin25 = "[$today] PROXY: TOTAL GOOD: $p | TOTAL BAD: $j\r\n";
}

if("$check_proxyz2"=="1") {

$logprin26 = "[$today] PROXY: Starting to checking [Method 2]. \r\n";
$proxyes=file("$proxyfile");
$url="http://profil.atlas.cz/reset.aspx?REFAPP=";
$mh = curl_multi_init();
if (file_exists("$proxyfile1")) { unlink("$proxyfile1"); }
 foreach ($proxyes as $i => $proxy) {
       $conn[$i]=curl_init($url);
  	curl_setopt($conn[$i], CURLOPT_RETURNTRANSFER, 1);
  	curl_setopt($conn[$i], CURLOPT_HEADER, 0);
  	curl_setopt($conn[$i], CURLOPT_POST , 1 );
  	curl_setopt($conn[$i], CURLOPT_PROXY , "$proxy");
  	curl_setopt($conn[$i], CURLOPT_FOLLOWLOCATION, 1);
  	curl_setopt($conn[$i], CURLOPT_USERAGENT, "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; .NET CLR 1.1.4322)");
  	curl_setopt($conn[$i], CURLOPT_REFERER, "http://profil.atlas.cz");
  	curl_setopt($conn[$i], CURLOPT_TIMEOUT, $timeout);
  	curl_multi_add_handle ($mh,$conn[$i]);
 }
 do { $n=curl_multi_exec($mh,$active); } while ($active);
$a=0;
$b=0;

 foreach ($proxyes as $i => $proxy) {
$res[$i]=curl_multi_getcontent($conn[$i]);
if (preg_match('/<!-- STATUS:OK -->/', $res[$i]))
{
 $fp = fopen ( "$proxyfile1" , "a+" );
 fwrite ( $fp , "$proxy" );
 fclose ( $fp );
$a=$a+1; } else
{ $b=$b+1; }
       curl_multi_remove_handle($mh,$conn[$i]);
       curl_close($conn[$i]);
 }
 if (file_exists("$proxyfile")) { unlink("$proxyfile"); }
 rename("$proxyfile1", "$proxyfile");
$today = date("H:i:s");
$logprin27 = "[$today] PROXY: TOTAL GOOD: $a | TOTAL BAD: $b\r\n";
 curl_multi_close($mh);
$today = date("H:i:s");
if($a=="0") { $logprin28 = "!!! ERROR !!!!     PROXY: GOOD PROXY NOT FOUND UPDATE PROXY LIST OR DISABLE PROXY CHECK FUNCTION!\r\n!!! ERROR !!!!     PROGRAM WILL BE CLOSED AFTER 10 sec!!!!"; $fp = fopen ( "$log" , "a+" );
 fwrite ( $fp , "$logprin28");
 fclose ( $fp );sleep(10); die; }
}
$today = date("H:i:s");
$proxyes=file("$proxyfile");

if(empty($proxyes)) { $logprin29 = "!!! ERROR !!!!     PROXY: LIST IS EMPTY [$proxyfile]!!!! \r\n!!! ERROR !!!!     PROGRAM WILL BE CLOSED AFTER 10 sec"; $fp = fopen ( "$log" , "a+" );
 fwrite ( $fp , "$logprin29");
 fclose ( $fp );
 sleep(10); die; }
foreach ($proxyes as $i => $proxy) {
if (file_exists("$cookdir/$i.txt")) { unlink("$cookdir/$i.txt"); }
}

$today = date("H:i:s");


$mh = curl_multi_init();

foreach ($proxyes as $i => $proxy) {
$today = date("H:i:s");
$z=rand(1, $uinz);
list($account[$i],$password[$i])=explode(";",$acc[$z]);
$password[$i]=str_replace ("\r\n", "", $password[$i]);
$password[$i]=str_replace ("\r", "", $password[$i]);
$proxy=trim($proxy);
$request1[$i]="username=$account[$i]&password=$password[$i]";
$url = "http://profil.atlas.cz/verify.aspx?REFAPP=";
  $conn[$i] = curl_init($url);
  curl_setopt($conn[$i], CURLOPT_RETURNTRANSFER, 1);
  curl_setopt($conn[$i], CURLOPT_HEADER, 0);
  curl_setopt($conn[$i], CURLOPT_POST , 1 );
  curl_setopt($conn[$i], CURLOPT_PROXY , "$proxy");
  curl_setopt($conn[$i], CURLOPT_FOLLOWLOCATION, 1);
  curl_setopt($conn[$i], CURLOPT_USERAGENT, "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; .NET CLR 1.1.4322)");
  curl_setopt($conn[$i], CURLOPT_REFERER, "http://profil.atlas.cz/login.aspx?REFAPP=%2fprofile.aspx");
  curl_setopt($conn[$i], CURLOPT_TIMEOUT, $timeout);
  curl_setopt($conn[$i], CURLOPT_POSTFIELDS , "$request1[$i]" );
  curl_setopt($conn[$i], CURLOPT_COOKIEJAR, "$cookdir/$i.txt");
  curl_setopt($conn[$i], CURLOPT_COOKIEFILE, "$cookdir/$i.txt");
  curl_multi_add_handle ($mh,$conn[$i]);
  $tr=$i;
}
$tr=$tr+1;
$logprin30 = "[$today] TOTAL TREADS: $tr\r\n";
$fp = fopen ( "$log" , "a+" );
 fwrite ( $fp , "$logprin2$logprin4$logprin5$logprin6$logprin8$logprin12$logprin13$logprin14$logprin15$logprin16$logprin17$logprin18$logprin19$logprin22$logprin23$logprin24$logprin25$logprin26$logprin27$logprin30");
 fclose ( $fp );
do {  $mrc = curl_multi_exec($mh, $active); } while($active > 0);

foreach ($proxyes as $i => $proxy) {
curl_multi_remove_handle($mh,$conn[$i]);
curl_close($conn[$i]);
}
curl_multi_close($mh);
$today2 = date("H:i:s");
$logprin40 = "---------------------------\r\n";
$logprin41 = "[$today2] REGGING STAGE: 1\r\n";
$logprin42 = "---------------------------\r\n";
$logprin43 = "[$today2] Saving cookies: DONE\r\n";
$fp = fopen ( "$log" , "a+" );
 fwrite ( $fp , "$logprin40$logprin41$logprin42$logprin43");
 fclose ( $fp );
$m2h = curl_multi_init();

foreach ($proxyes as $i => $proxy) {
$today = date("H:i:s");
$url2 = "http://profil.atlas.cz/icq.aspx";
  $conn2[$i] = curl_init();
  curl_setopt($conn2[$i], CURLOPT_RETURNTRANSFER, 1);
  curl_setopt($conn2[$i], CURLOPT_HEADER, 0);
  curl_setopt($conn2[$i], CURLOPT_COOKIEFILE, "$cookdir/$i.txt");
  curl_setopt($conn2[$i], CURLOPT_POST , 1 );
  curl_setopt($conn2[$i], CURLOPT_PROXY , "$proxy");
  curl_setopt($conn2[$i], CURLOPT_FOLLOWLOCATION, 1);
  curl_setopt($conn2[$i], CURLOPT_USERAGENT, "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; .NET CLR 1.1.4322)");
  curl_setopt($conn2[$i], CURLOPT_REFERER, "http://profil.atlas.cz/login.aspx?REFAPP=%2fprofile.aspx");
  curl_setopt($conn2[$i], CURLOPT_TIMEOUT, $timeout);
  curl_setopt($conn2[$i], CURLOPT_URL, $url2);
  curl_multi_add_handle ($m2h,$conn2[$i]);
}
do {  $mrc = curl_multi_exec($m2h, $active); } while($active > 0);



foreach ($proxyes as $i => $proxy) {
$res[$i]=curl_multi_getcontent($conn2[$i]);

$blst[$i]=explode("\r\n",$res[$i]);
for ($v=0;$v<=count($blst[$i]);$v++) {
if(strstr($blst[$i][$v],'<input type="hidden" name="__VIEWSTATE" id="__VIEWSTATE" value="')){
$viewstate[$i]=str_replace('<input type="hidden" name="__VIEWSTATE" id="__VIEWSTATE" value="',"",$blst[$i][$v]);
$viewstate[$i]=str_replace('" />',"",$viewstate[$i]);
$viewstate[$i]=urlencode(trim($viewstate[$i]));
}
if(strstr($blst[$i][$v],'<input type="hidden" name="__EVENTVALIDATION" id="__EVENTVALIDATION" value="')){
$eventvalid[$i]=str_replace('<input type="hidden" name="__EVENTVALIDATION" id="__EVENTVALIDATION" value="',"",$blst[$i][$v]);
$eventvalid[$i]=str_replace('" />',"",$eventvalid[$i]);
$eventvalid[$i]=urlencode(trim($eventvalid[$i]));
}}
$request1[$i]="__EVENTTARGET=&__EVENTARGUMENT=&__VIEWSTATE=".$viewstate[$i]."&ua_icqstatus=1&ua_icq=&icqpassword=&passwordset=0&btnconnect=Propojit+%C3%BA%C4%8Dty&__EVENTVALIDATION=".$eventvalid[$i];
curl_multi_remove_handle($m2h,$conn2[$i]);
curl_close($conn2[$i]);
}

curl_multi_close($m2h);
$today = date("H:i:s");
$logprin44 = "[$today] Authorization: DONE\r\n";
$fp = fopen ( "$log" , "a+" );
 fwrite ( $fp , "$logprin44");
 fclose ( $fp );


$m3h = curl_multi_init();

foreach ($proxyes as $i => $proxy) {
 if($save_proxy_bad=="1") {
  $fp = fopen ( "$bad_proxy_file" , "a+" );
 fwrite ( $fp , "$proxy" );
 fclose ( $fp );
  }
$today = date("H:i:s");
$url2 = "http://profil.atlas.cz/icq.aspx";
  $conn3[$i] = curl_init();
  curl_setopt($conn3[$i], CURLOPT_RETURNTRANSFER, 1);
  curl_setopt($conn3[$i], CURLOPT_HEADER, 0);
  curl_setopt($conn3[$i], CURLOPT_COOKIEFILE, "$cookdir/$i.txt");
  curl_setopt($conn3[$i], CURLOPT_POST , 1 );
  curl_setopt($conn3[$i], CURLOPT_PROXY , "$proxy");
  curl_setopt($conn3[$i], CURLOPT_FOLLOWLOCATION, 1);
  curl_setopt($conn3[$i], CURLOPT_USERAGENT, "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; .NET CLR 1.1.4322)");
  curl_setopt($conn3[$i], CURLOPT_REFERER, "http://profil.atlas.cz/login.aspx?REFAPP=%2fprofile.aspx");
  curl_setopt($conn3[$i], CURLOPT_TIMEOUT, $timeout);
  curl_setopt($conn3[$i], CURLOPT_URL, $url2);
  curl_setopt($conn3[$i], CURLOPT_POSTFIELDS , "$request1[$i]" );
  curl_multi_add_handle ($m3h,$conn3[$i]);
}
do {  $mrc = curl_multi_exec($m3h, $active); } while($active > 0);
$a=0;
$b=0;
$c=0;

foreach ($proxyes as $i => $proxy) {

$res2[$i]=curl_multi_getcontent($conn3[$i]);


$str[$i]=explode("<strong>www.icq.atlas.cz</strong></a></p>",$res2[$i]);
               	      $str[$i]=str_replace($symb,"",$str[$i][1]);
		eregi( "(ICQ )([^.]*)([^\r\n]*)(.*)", $str[$i], $string[$i] );
            $icq[$i]= trim($string[$i][2]);
if (preg_match("/Atlasem/", "$icq[$i]")) { $icq[$i]=""; }
$uns = file_get_contents("$regged");
if (preg_match("/$icq[$i]/", "$uns")) { $icq[$i]=""; }
if($icq[$i]=="") { $b=$b+1; if($bans=="1") {$ban[$i]="1";} else {  $ban[$i]="0"; }
 } else {
 $ban[$i]="0";
 $fp = fopen ( "$log" , "a+" );
 fwrite ( $fp , "[$today2] REGEED UIN:  $icq[$i];$password[$i]\r\n");
 fclose ( $fp );
 $fp = fopen ( "$regged" , "a+" );
 fwrite ( $fp , "$icq[$i];$password[$i]   $account[$i]\r\n" );
 fclose ( $fp );
 $a=$a+1;

 if($save_proxy_bad=="1") {
$text = file_get_contents("$bad_proxy_file");
$text2 = str_replace("$proxy","","$text");
$fp = fopen ( "$bad_proxy_file" , "w" );
fwrite ( $fp , "$text2" );
fclose ( $fp );
}
if($save_proxy_good=="1") {

	   if($save_proxy_update=="1")
        {
         if(file_exists("$proxyfile"))
		  {
          unlink("$proxyfile");
		  }
        $good_proxy_file="$proxyfile";
        }

$fp = fopen ( "$good_proxy_file" , "a+" );
fwrite ( $fp , "$proxy" );
fclose ( $fp );
}

 if($acc_delete=="1") {
$text = file_get_contents("$accfile");
$text2 = str_replace("$account[$i];$password[$i]\r\n","","$text");
$c=$c+1;
$fp = fopen ( "$accfile" , "w" );
fwrite ( $fp , "$text2" );
fclose ( $fp );
}
}
curl_multi_remove_handle($m3h,$conn3[$i]);
curl_close($conn3[$i]);
}
if($acc_delete=="1") { $z=" | Deleted mails: $c"; } else { $z=""; }
$today = date("H:i:s");
$logprin46 = "[$today] Regger UINs: $a | Failed UINs: $b$z\r\n";
$fp = fopen ( "$log" , "a+" );
 fwrite ( $fp , "$logprin46");
 fclose ( $fp );

if($save_proxy_good=="1") {
if (file_exists("$good_proxy_file")) {
$foundprox = file("$good_proxy_file");
$foundprox = array_unique($foundprox);
foreach ($foundprox as $line) {
$f=fopen("$good_proxy_file1",'a');
flock ($f,2);
fwrite($f,"$line");
fclose($f);}
$fp = fopen ( "$good_proxy_file1" , "a+" );
 fwrite ( $fp , "\r\n" );
 fclose ( $fp );
if (file_exists("$good_proxy_file")) { unlink("$good_proxy_file"); }
rename("$good_proxy_file1", "$good_proxy_file");

}}

if($save_proxy_bad=="1") {
if (file_exists("$bad_proxy_file")) {
$foundprox = file("$bad_proxy_file");
$foundprox = array_unique($foundprox);
foreach ($foundprox as $line) {
$f=fopen("$bad_proxy_file1",'a');
flock ($f,2);
fwrite($f,"$line");
fclose($f);}
$fp = fopen ( "$bad_proxy_file1" , "a+" );
fwrite ( $fp , "\r\n" );
fclose ( $fp );
if (file_exists("$bad_proxy_file")) { unlink("$bad_proxy_file"); }
rename("$bad_proxy_file1", "$bad_proxy_file");

}}

curl_multi_close($m3h);

for($j=2;$j<5;$j++){


$mh = curl_multi_init();

$today = date("H:i:s");
$logprin47 = "---------------------------\r\n";
$logprin48 = "[$today] REGGING STAGE: $j\r\n";
$logprin49 = "---------------------------\r\n";
$today = date("H:i:s");
$logprin50 = "[$today] Getting cookies: DONE\r\n";
$fp = fopen ( "$log" , "a+" );
 fwrite ( $fp , "$logprin47$logprin48$logprin49$logprin50");
 fclose ( $fp );
$m2h = curl_multi_init();

foreach ($proxyes as $i => $proxy) {
$today = date("H:i:s");
if($ban[$i]=="1") { } else {
$url2 = "http://profil.atlas.cz/icq.aspx";
  $conn2[$i] = curl_init();
  curl_setopt($conn2[$i], CURLOPT_RETURNTRANSFER, 1);
  curl_setopt($conn2[$i], CURLOPT_HEADER, 0);
  curl_setopt($conn2[$i], CURLOPT_COOKIEFILE, "$cookdir/$i.txt");
  curl_setopt($conn2[$i], CURLOPT_POST , 1 );
  curl_setopt($conn2[$i], CURLOPT_PROXY , "$proxy");
  curl_setopt($conn2[$i], CURLOPT_FOLLOWLOCATION, 1);
  curl_setopt($conn2[$i], CURLOPT_USERAGENT, "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; .NET CLR 1.1.4322)");
  curl_setopt($conn2[$i], CURLOPT_REFERER, "http://profil.atlas.cz/login.aspx?REFAPP=%2fprofile.aspx");
  curl_setopt($conn2[$i], CURLOPT_TIMEOUT, $timeout);
  curl_setopt($conn2[$i], CURLOPT_URL, $url2);
  curl_multi_add_handle ($m2h,$conn2[$i]);}
}
do {  $mrc = curl_multi_exec($m2h, $active); } while($active > 0);



foreach ($proxyes as $i => $proxy) {
if($ban[$i]=="1") { } else {
$res[$i]=curl_multi_getcontent($conn2[$i]);
$blst[$i]=explode("\r\n",$res[$i]);
for ($v=0;$v<=count($blst[$i]);$v++) {
if(strstr($blst[$i][$v],'<input type="hidden" name="__VIEWSTATE" id="__VIEWSTATE" value="')){
$viewstate[$i]=str_replace('<input type="hidden" name="__VIEWSTATE" id="__VIEWSTATE" value="',"",$blst[$i][$v]);
$viewstate[$i]=str_replace('" />',"",$viewstate[$i]);
$viewstate[$i]=urlencode(trim($viewstate[$i]));
}
if(strstr($blst[$i][$v],'<input type="hidden" name="__EVENTVALIDATION" id="__EVENTVALIDATION" value="')){
$eventvalid[$i]=str_replace('<input type="hidden" name="__EVENTVALIDATION" id="__EVENTVALIDATION" value="',"",$blst[$i][$v]);
$eventvalid[$i]=str_replace('" />',"",$eventvalid[$i]);
$eventvalid[$i]=urlencode(trim($eventvalid[$i]));
}}
$request1[$i]="__EVENTTARGET=&__EVENTARGUMENT=&__VIEWSTATE=".$viewstate[$i]."&ua_icqstatus=1&ua_icq=&icqpassword=&passwordset=0&btndisconnect=Propojit+%C3%BA%C4%8Dty&__EVENTVALIDATION=".$eventvalid[$i];
curl_multi_remove_handle($m2h,$conn2[$i]);
curl_close($conn2[$i]);
}}

curl_multi_close($m2h);
$today = date("H:i:s");
$logprin51 = "[$today] Disconnect UINs: DONE\r\n";
$fp = fopen ( "$log" , "a+" );
 fwrite ( $fp , "$logprin51");
 fclose ( $fp );

$m3h = curl_multi_init();

foreach ($proxyes as $i => $proxy) {
if($ban[$i]=="1") { } else {
$today = date("H:i:s");
$url2 = "http://profil.atlas.cz/icq.aspx";
  $conn3[$i] = curl_init();
  curl_setopt($conn3[$i], CURLOPT_RETURNTRANSFER, 1);
  curl_setopt($conn3[$i], CURLOPT_HEADER, 0);
  curl_setopt($conn3[$i], CURLOPT_COOKIEFILE, "$cookdir/$i.txt");
  curl_setopt($conn3[$i], CURLOPT_POST , 1 );
  curl_setopt($conn3[$i], CURLOPT_PROXY , "$proxy");
  curl_setopt($conn3[$i], CURLOPT_FOLLOWLOCATION, 1);
  curl_setopt($conn3[$i], CURLOPT_USERAGENT, "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; .NET CLR 1.1.4322)");
  curl_setopt($conn3[$i], CURLOPT_REFERER, "http://profil.atlas.cz/login.aspx?REFAPP=%2fprofile.aspx");
  curl_setopt($conn3[$i], CURLOPT_TIMEOUT, $timeout);
  curl_setopt($conn3[$i], CURLOPT_URL, $url2);
  curl_setopt($conn3[$i], CURLOPT_POSTFIELDS , "$request1[$i]" );
  curl_multi_add_handle ($m3h,$conn3[$i]);
}}
do {  $mrc = curl_multi_exec($m3h, $active); } while($active > 0);


foreach ($proxyes as $i => $proxy) {
if($ban[$i]=="1") { } else {
$res[$i]=curl_multi_getcontent($conn3[$i]);
curl_multi_remove_handle($m3h,$conn3[$i]);
curl_close($conn3[$i]);
$blst[$i]=explode("\r\n",$res[$i]);
for ($v=0;$v<=count($blst[$i]);$v++) {
if(strstr($blst[$i][$v],'<input type="hidden" name="__VIEWSTATE" id="__VIEWSTATE" value="')){
$viewstate[$i]=str_replace('<input type="hidden" name="__VIEWSTATE" id="__VIEWSTATE" value="',"",$blst[$i][$v]);
$viewstate[$i]=str_replace('" />',"",$viewstate[$i]);
$viewstate[$i]=urlencode(trim($viewstate[$i]));
}
if(strstr($blst[$i][$v],'<input type="hidden" name="__EVENTVALIDATION" id="__EVENTVALIDATION" value="')){
$eventvalid[$i]=str_replace('<input type="hidden" name="__EVENTVALIDATION" id="__EVENTVALIDATION" value="',"",$blst[$i][$v]);
$eventvalid[$i]=str_replace('" />',"",$eventvalid[$i]);
$eventvalid[$i]=urlencode(trim($eventvalid[$i]));
}}
$request1[$i]="__EVENTTARGET=&__EVENTARGUMENT=&__VIEWSTATE=".$viewstate[$i]."&ua_icqstatus=1&ua_icq=&icqpassword=&passwordset=0&btnconnect=Propojit+%C3%BA%C4%8Dty&__EVENTVALIDATION=".$eventvalid[$i];
}}

curl_multi_close($m3h);
$today = date("H:i:s");
$logprin52 = "[$today] Authorization: DONE\r\n";
$fp = fopen ( "$log" , "a+" );
 fwrite ( $fp , "$logprin52");
 fclose ( $fp );
 
 
 
$m3h = curl_multi_init();

foreach ($proxyes as $i => $proxy) {
if($ban[$i]=="1") { } else {
$today = date("H:i:s");
$url2 = "http://profil.atlas.cz/icq.aspx";
  $conn3[$i] = curl_init();
  curl_setopt($conn3[$i], CURLOPT_RETURNTRANSFER, 1);
  curl_setopt($conn3[$i], CURLOPT_HEADER, 0);
  curl_setopt($conn3[$i], CURLOPT_COOKIEFILE, "$cookdir/$i.txt");
  curl_setopt($conn3[$i], CURLOPT_POST , 1 );
  curl_setopt($conn3[$i], CURLOPT_PROXY , "$proxy");
  curl_setopt($conn3[$i], CURLOPT_FOLLOWLOCATION, 1);
  curl_setopt($conn3[$i], CURLOPT_USERAGENT, "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; .NET CLR 1.1.4322)");
  curl_setopt($conn3[$i], CURLOPT_REFERER, "http://profil.atlas.cz/login.aspx?REFAPP=%2fprofile.aspx");
  curl_setopt($conn3[$i], CURLOPT_TIMEOUT, $timeout);
  curl_setopt($conn3[$i], CURLOPT_URL, $url2);
  curl_setopt($conn3[$i], CURLOPT_POSTFIELDS , "$request1[$i]" );
  curl_multi_add_handle ($m3h,$conn3[$i]);
}}
do {  $mrc = curl_multi_exec($m3h, $active); } while($active > 0);
$a=0;
$b=0;
$c=0;

foreach ($proxyes as $i => $proxy) {
if($ban[$i]=="1") { } else {
$res2[$i]=curl_multi_getcontent($conn3[$i]);


$str[$i]=explode("<strong>www.icq.atlas.cz</strong></a></p>",$res2[$i]);
               	      $str[$i]=str_replace($symb,"",$str[$i][1]);
		eregi( "(ICQ )([^.]*)([^\r\n]*)(.*)", $str[$i], $string[$i] );
            $icq[$i]= trim($string[$i][2]);
if (preg_match("/Atlasem/", "$icq[$i]")) { $icq[$i]=""; }
$uns = file_get_contents("$regged");
if (preg_match("/$icq[$i]/", "$uns")) { $icq[$i]=""; }
if($icq[$i]=="") { $b=$b+1;
 } else {
 $fp = fopen ( "$log" , "a+" );
 fwrite ( $fp , "[$today] REGEED UIN:  $icq[$i];$password[$i]\r\n");
 fclose ( $fp );
  $fp = fopen ( "$regged" , "a+" );
 fwrite ( $fp , "$icq[$i];$password[$i]   $account[$i]\r\n" );
 fclose ( $fp );
 $a=$a+1;
  if($save_proxy_bad=="1") {
$text = file_get_contents("$bad_proxy_file");
$text2 = str_replace("$proxy","","$text");
$fp = fopen ( "$bad_proxy_file" , "w" );
fwrite ( $fp , "$text2" );
fclose ( $fp );
}
if($save_proxy_good=="1") {

	   if($save_proxy_update=="1")
        {
         if(file_exists("$proxyfile"))
		  {
          unlink("$proxyfile");
		  }
        $good_proxy_file="$proxyfile";
        }

$fp = fopen ( "$good_proxy_file" , "a+" );
fwrite ( $fp , "$proxy" );
fclose ( $fp );
}


if($acc_delete=="1") {
$text = file_get_contents("$accfile");
if (preg_match("/$account[$i];$password[$i]\r\n/", "$text")) { $c=$c+1;
$text2 = str_replace("$account[$i];$password[$i]\r\n","","$text");
$text2 = str_replace("\r\n\r\n","\r\n","$text2");
$fp = fopen ( "$accfile" , "w" );
fwrite ( $fp , "$text2" );
fclose ( $fp ); }
}
}
curl_multi_remove_handle($m3h,$conn3[$i]);
curl_close($conn3[$i]);
}}

if($acc_delete=="1") { $z=" | Deleted mails: $c"; } else { $z=""; }
$today = date("H:i:s");
$logprin54 = "[$today] Regger UINs: $a | Failed UINs: $b$z\r\n";
$fp = fopen ( "$log" , "a+" );
 fwrite ( $fp , "$logprin54");
 fclose ( $fp );

if($save_proxy_good=="1") {
if (file_exists("$good_proxy_file")) {
$foundprox = file("$good_proxy_file");
$foundprox = array_unique($foundprox);
foreach ($foundprox as $line) {
$f=fopen("$good_proxy_file1",'a');
flock ($f,2);
fwrite($f,"$line");
fclose($f);}
$fp = fopen ( "$good_proxy_file1" , "a+" );
 fwrite ( $fp , "\r\n" );
 fclose ( $fp );

if (file_exists("$good_proxy_file")) { unlink("$good_proxy_file"); }
rename("$good_proxy_file1", "$good_proxy_file");


}}

if($save_proxy_bad=="1") {
if (file_exists("$bad_proxy_file")) {
$foundprox = file("$bad_proxy_file");
$foundprox = array_unique($foundprox);
foreach ($foundprox as $line) {
$f=fopen("$bad_proxy_file1",'a');
flock ($f,2);
fwrite($f,"$line");
fclose($f);}
if (file_exists("$bad_proxy_file")) { unlink("$bad_proxy_file"); }
rename("$bad_proxy_file1", "$bad_proxy_file");
}

curl_multi_close($m3h);
}}
$today = date("H:i:s");
$logprin55 = "\r\n\r\n";
$logprin56 = "[$today] RESTARTING REGGER FOR $restime sec";
sleep("$restime");
$logprin57 = "\r\n\r\n";
$fp = fopen ( "$log" , "a+" );
 fwrite ( $fp , "$logprin55$logprin56$logprin57");
 fclose ( $fp );

}
?>
