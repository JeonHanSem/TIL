	<!--<script type="text/javascript" src="/bbs/include/js/httpRequest.js"></script>-->
	<script type="text/javascript">
	$(function(){
		$("#comment_add").click(function(){
			$.ajax({
				url: "/bbs/ajax_board/ajax_comment_add",
				type: "POST",
				data:{
					"comment_contents":encodeURIComponent($("#input01").val()),
					"csrf_test_name":getCookie('csrf_cookie_name'),
					"table":"<?php echo $this->uri->segment(3);?>",
					"board_id":"<?php echo $this->uri->segment(5);?>"
				},
				dataType: "html",
				complete:function(xhr, textStatus){
					if (textStatus == 'success')
					{
						if ( xhr.responseText == 1000 )
						{
							alert('댓글 내용을 입력하세요');
						}
						else if ( xhr.responseText == 2000 )
						{
							alert('다시 입력하세요');
						}
						else if ( xhr.responseText == 9000 )
						{
							alert('로그인하여야 합니다.');
						}
						else
						{
							$("#comment_area").html(xhr.responseText);
							$("#input01").val('');
						}
					}
				}
			});
		});
	});
	function getCookie( name ){
		var nameOfCookie = name + "=";
		var x = 0;

		while ( x <= document.cookie.length ){
			var y = (x+nameOfCookie.length);

			if ( document.cookie.substring( x, y ) == nameOfCookie ) {
				if ( (endOfCookie=document.cookie.indexOf( ";", y )) == -1 )
					endOfCookie = document.cookie.length;

				return unescape( document.cookie.substring( y, endOfCookie ) );
			}

			x = document.cookie.indexOf( " ", x ) + 1;

			if ( x == 0 )

			break;
		}
		return "";
	}
	</script>

	<article id="board_area">
		<header>
			<h1></h1>
		</header>
		<table cellspacing="0" cellpadding="0" class="table table-striped">
			<thead>
				<tr>
					<th scope="col"><?php echo $views->subject;?></th>
					<th scope="col">이름 : <?php echo $views->user_name;?></th>
					<th scope="col">조회수 : <?php echo $views->hits;?></th>
					<th scope="col">등록일 : <?php echo $views->reg_date;?></th>
				</tr>
			</thead>
			<tbody>
				<tr>
					<th colspan="4">
						<?php echo $views->contents;?>
					</th>
				</tr>
			</tbody>
			<tfoot>
				<tr>
					<th colspan="4"><a href="/bbs/board/lists/<?php echo $this->uri->segment(3);?>/page/<?php echo $this->uri->segment(7);?>" class="btn btn-primary">목록</a> <a href="/bbs/board/modify/<?php echo $this->uri->segment(3);?>/board_id/<?php echo $this->uri->segment(4);?>/page/<?php echo $this->uri->segment(7);?>" class="btn btn-warning">수정</a> <a href="/bbs/board/delete/<?php echo $this->uri->segment(3);?>/board_id/<?php echo $this->uri->segment(4);?>/page/<?php echo $this->uri->segment(7);?>" class="btn btn-danger">삭제</a> <a href="/bbs/board/write/<?php echo $this->uri->segment(3);?>/page/<?php echo $this->uri->segment(7);?>" class="btn btn-success">쓰기</a></th>
				</tr>
			</tfoot>
		</table>
		<form class="form-horizontal" method="post" action="" name="com_add">
		  <fieldset>
		    <div class="control-group">
		      <label class="control-label" for="input01">댓글</label>
		      <div class="controls">
		        <textarea class="input-xlarge" id="input01" name="comment_contents" rows="3"></textarea>
				<input class="btn btn-primary" type="button" id="comment_add" value="작성">
		        <p class="help-block"></p>
		      </div>
		    </div>
		  </fieldset>
		</form>
	</article>
