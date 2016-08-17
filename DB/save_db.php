<?php
	$sql_connect = mysql_connect("localhost","root","eldkfvk22") or die ("no DB Connection");

	mysql_select_db("WhatTheHealth") or die ("DB not found");

	$id = $_POST['newId'];
	$date = $_POST['newDate'];
	$type = $_POST['newType'];
	$sets = $_POST['newSets'];
	$rap = $_POST['newRap'];
	$mm = $_POST['newMm'];
	$ss = $_POST['newSs'];

	mysql_query("INSERT INTO db_test values ($id,$date,$type,$sets,$rap,$mm,$ss,now());");

	mysql_close($sql_connect);
?>
