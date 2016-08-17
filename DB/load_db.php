<?php
	$sql_connect = mysql_connect("localhost","root","eldkfvk22") or die ("no DB Connection");
	
	mysql_select_db("WhatTheHealth") or die ("DB not found");

	$id = $_POST['newId'];
	
	$query = "SELECT date,type,sets,rap,mm,ss FROM db_test where id=$id ORDER BY dd DESC LIMIT 15";

	$result = mysql_query($query);

	$num_results = mysql_num_rows($result);

	for($i = 0; $i < $num_results; $i++){
		$row = mysql_fetch_array($result);
		
		if($row['type']==1) $str="shoulder";
		if($row['type']==2) $str="      arm     ";
		if($row['type']==3) $str="        leg       ";

		//if($row['rap']<10) $num="0"+$row['rap'];

		echo $row['date']."\t".$str."\t\t".$row['sets']."\t".$row['rap']."\t\t".$row['mm'].":".$row['ss']."\n";
	}

	mysql_close($sql_connect);
?>
