<?
    include "simple_html_dom.php";    
 
    if(!$_GET[page]) $page = 1;
    else $page = $_GET[page];
        
    $html = file_get_html("http://ibob.co.kr/source/pgr21_sample.html?id=freedom&page=".$page);
        
    if($html)
    {
        
        header('Content-Type: text/html; charset=UTF-8');

		$item = array();
		$data = array();
		$cnt = 0;
        foreach($html->find('tr[class=listtr]') as $article) {
            $title        = $article->find('td.tdsub', 0)->plaintext;        
            $comment_cnt = preg_replace("/\].*|.*?\[/", "", $title);
            $name    = $article->find('td.tdname', 0)->plaintext;
            $date        = $article->find('td.tddate', 0)->plaintext;

			$data["name"]=$name;
			$data["title"]=$title;
			$data["date"]=$date;
			
			$cnt += 1;
			$item[$cnt]=$data;
        }
		echo json_encode($item);

    }

    else
        echo "error document";
?>
