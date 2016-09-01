<?php

$curl = curl_init();

curl_setopt_array($curl, array(
  CURLOPT_URL => "https://language.googleapis.com/v1beta1/documents:annotateText?key=[Personal Key]",
  CURLOPT_RETURNTRANSFER => true,
  CURLOPT_ENCODING => "",
  CURLOPT_MAXREDIRS => 10,
  CURLOPT_TIMEOUT => 30,
  CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
  CURLOPT_CUSTOMREQUEST => "POST",
  CURLOPT_POSTFIELDS => "{\n    \"document\":{\n    \"type\":\"PLAIN_TEXT\",\n    \"content\":\"Today I learn\"\n    },\n    \"features\":{\n        \"extractSyntax\":true,\n        \"extractEntities\":false,\n        \"extractDocumentSentiment\":false\n    },\n    \"encodingType\":\"UTF8\"\n}",
  CURLOPT_HTTPHEADER => array(
    "cache-control: no-cache",
    "content-type: application/json",
    "postman-token: 10f6f1fc-b4ae-5073-1a0f-4d9399903a12"
  ),
));

$response = curl_exec($curl);
$err = curl_error($curl);

curl_close($curl);

if ($err) {
  echo "cURL Error #:" . $err;
} else {
  echo $response;
}
