
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
