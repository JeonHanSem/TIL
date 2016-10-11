<?php
	define( 'KAKAO_OAUTH_AUTHORIZE_URL', 'https://kauth.kakao.com/oauth/authorize' );
	define( 'KAKAO_OAUTH_TOKEN_URL', 'https://kauth.kakao.com/oauth/token' );
	define( 'KAKAO_GET_USERINFO_URL', 'https://kapi.kakao.com/v1/user/me' );
	class OAuthRequest{
		private $client_id;
		private $client_secret;
		private $redirect_url;
		private $state;
		private $session;
		private $authorize_url = KAKAO_OAUTH_AUTHORIZE_URL;
		private $accesstoken_url = KAKAO_OAUTH_TOKEN_URL;
		private $code;
		private $tokenArr; 
		private $userInfo;

		function __construct( $client_id, $redirect_url) {
			$this -> client_id = $client_id;
			$this -> redirect_url = $redirect_url;
			if(!isset($_SESSION)) {
				session_start();
			}
		}
		private function get_code(){
			$this -> code = $_GET['code'];
		}

		public function request_auth(){
			header('Location: '. $this -> get_request_url() );
		}
		public function get_request_url(){
			return $this -> authorize_url .'?response_type=code&redirect_uri=' . urlencode($this -> redirect_url) .'&client_id='.$this->client_id; 
		}
		public function get_accesstoken_url(){
			return $this -> accesstoken_url . '?grant_type=authorization_code&client_id=' . $this -> client_id .'&code=' . $this -> code;
		}
		public function call_accesstoken(){
			$this -> get_code();

			$ch = curl_init();
			curl_setopt($ch, CURLOPT_URL, $this -> get_accesstoken_url() );
			curl_setopt($ch, CURLOPT_RETURNTRANSFER, true );
			curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false );
			curl_setopt($ch, CURLOPT_COOKIE, '' );
			curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 300);
			$g = curl_exec($ch);
			curl_close($ch);
			$data = json_decode($g, true);
			$this -> tokenArr = array(
				 'Authorization: Bearer '.$data['access_token']
			);
		}
		public function get_user_profile(){
			$ch = curl_init();
			curl_setopt($ch, CURLOPT_URL, KAKAO_GET_USERINFO_URL );
			curl_setopt($ch, CURLOPT_HTTPHEADER, $this -> tokenArr );
			curl_setopt($ch, CURLOPT_RETURNTRANSFER, true );
			curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false );
			curl_setopt($ch, CURLOPT_SSLVERSION, 1);
			curl_setopt($ch, CURLOPT_POST, true);
   			curl_setopt($ch, CURLOPT_POSTFIELDS, false);
   			curl_setopt($ch, CURLOPT_COOKIE, '' );
			curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 300);
			$g = curl_exec($ch);
			curl_close($ch);
			$data = json_decode($g,true);
			$proper=$data['properties'];
			$this -> userInfo = array(
				'userID' => $data['id'],
				'nickname' => $proper['nickname'],
				'thumbImg' => $proper['thumbnail_image'],
				'profImg' => $proper['profile_image']
			);
			
		}
		public function get_userInfo(){
			return $this -> userInfo;
		}
		public function get_userID(){
			return $this -> userInfo['id'];
		}
		public function get_nickname(){
			return $this -> userInfo['nickname'];
		}
		public function get_thumbImg(){
			return $this -> userInfo['thumbImg'];
		}
		public function get_profImg(){
			return $this -> userInfo['profImg'];
		}
	}
?>
