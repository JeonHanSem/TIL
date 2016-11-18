
##url form 검증
	function valid_url($url) {
		if($url == NULL) return TRUE;
		$pattern = "|^http(s)?://[a-z0-9-]+(.[a-z0-9-]+)*(:[0-9]+)?(/.*)?$|i";
		if(!preg_match($pattern, $url)){
			$this->form_validation->set_message('유효하지 않은 url입니다');
			return FALSE;
		}
		return TRUE;
	}

##삼항연산자
	a가 1이면 1 아니면 0
	($a==1)?1:0

##image 미리보기
링크 = http://touchsoul.tistory.com/84 <br>
\<img id="xx"?> 로 하면 처음에 공간 차지 안함



##파일 업로드시
 view에서 form \<enctype = "multipart/form-data">를 추가해주고
controller에서 $_FILES로 받는다
업로드 경로의 디렉토리들에 쓰기권한을 준다.

버튼은 form밖에서 처리하는게 같은 submit을 안할수 있다
form 안의 내용을 form밖에서 submit 할 때는 script에서 처리한다
	
	$(document).ready(function(){
    	$("#write_btn").click(function(){
        	$("#upload_action").submit();
		});
	});
	
##보안
form 태그때문에 base_url을 변경해놓았다
서버에서도 바꿔야할 것!
###xss와 sql injection
$this->input→post('변수',TRUE); 로 방어
###csrf 방지
config.php에서 csrf_protection = TRUE로 변경 <br>
컨트롤러에서 $this→load→helper('form'); <br>
뷰에서 

	<!--<form class="form-horizontal" method="post"name="myform" action="" id="upload_action" enctype="multipart/form-data">-- > 
	폼태그 대신 php로
	<?php
		$attributes = array('class' => 'form-horizontal','name' => 'myform', 'id' => 'upload_action');
		echo form_open_multipart('/makers/modify/'.	$maker_info->acc_idx, $attributes);
	?>
form_open_multipart 사용 <br>
form_open 사용

##체크박스 id로 확인 할때
	JQuery
	$('input:checkbox[id="checkbox_id"]').is(":checked") == true
	
	script
	if(document.form_name.checkbox_name.checked==true)

##php date_format
	<?php
		$date=date_create("2013-03-15");
		echo date_format($date,"Y/m/d H:i:s");
	?>	
##DB에서 게시물 갯수 세기
	SELECT count(*) as cnt FROM `article` WHERE ~~~ 
	
##DB Insert 시에 키값 받기
	$this → db → insert_id()
table의 PK를 가져온다 (단, A.I 일때만 가능)

##JAVA script 확인창
	if(confirm("are you serious?") == true){
	}

##JAVA script redirect
	location.href="xxxxx"
	
##query 결과 반환
	$query->row() 		//값 1개 반환
	$query->result() 	//값 배열로 반환
	
##script에서 php로 값 전달
csrf 방지를 적용했을때도 될지는 의문이다

	/** script **/
	$.post("/ajax_makers/more_list/"+list_type+"/"+last_id, {except_cond:arr},
	function(data){
	}):
	
	/** php **/
	$arr = $this->input->post('except_cond',true);
##html에서 a 태그 밑줄 지우기
속성에 text-decoration:none 추가하기

##html에서 file type버튼 이미지로 변경하기
	<input type="file" id='file1' name='userfile' style='display: none;'>
	<img src="../../../include/icon/upload_btn.png" border='0' onclick='document.all.userfile.click(); '>
	

##html text값 힌트주기
placehoder 사용

##codeigniter에서 textarea사용
textarea 다음 필드에 바로 name이 와야함

##php에서 DB에 저장시에 줄바꿈
	str_replace("\r\n","<br/>",$contents);
##AJAX에서 view로 값 전달시
	//ajax controller
	echo val;
	//view
	$.post(~~~,
	function(data){
		#data가 val을 받음
	});
##facebook공유
	window.open("http://www.facebook.com/sharer.php?u="+url);
##naver band 공유
	//mobile
	bandapp://create/post?text=<문자열>&route=<밴드 공유 버튼을 사용하는 서비스의 도메인>
	//pc
	http://band.us/plugin/share?body=<문자열>&route=<밴드 공유 버튼을 사용하는 서비스의 도메인>
##kakao 공유
	<!doctype HTML>
	<html>
	<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <title>KakaoLink Demo(Web Button) - Kakao Javascript SDK</title>
    <script src="https://developers.kakao.com/sdk/js/kakao.min.js"></script>
  	</head>
  	<body>
  		<h3>카카오톡 링크는 카카오톡 앱이 설치되어 있는 모바일 기기에서만 전송 가능합니다.</h3>
    	<a id="kakao-link-btn" href="javascript:;">
      <img src="http://dn.api1.kage.kakao.co.kr/14/dn/btqa9B90G1b/GESkkYjKCwJdYOkLvIBKZ0/o.jpg" />
    	</a>

    <script>
    // 사용할 앱의 Javascript 키를 설정해 주세요.
    Kakao.init('YOUR APP KEY');

    // 카카오톡 링크 버튼을 생성합니다. 처음 한번만 호출하면 됩니다.
    Kakao.Link.createTalkLinkButton({
      container: '#kakao-link-btn',
      label: '카카오링크 샘플에 오신 것을 환영합니다.',
      image: {
        src: 'http://dn.api1.kage.kakao.co.kr/14/dn/btqaWmFftyx/tBbQPH764Maw2R6IBhXd6K/o.jpg',
        width: '300',
        height: '200'
      },
      webButton: {
        text: '카카오 디벨로퍼스',
        url: 'https://dev.kakao.com/docs/js' // 앱 설정의 웹 플랫폼에 등록한 도메인의 URL이어야 합니다.
      }
    });
    </script>
  	</body>
	</html>

출처 : https://developers.kakao.com/docs/js 