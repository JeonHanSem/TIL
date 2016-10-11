<?php
	define( 'FACEBOOK_OAUTH_AUTHORIZE_URL', 'https://www.facebook.com/v2.7/dialog/oauth' );
	define( 'FACEBOOK_OAUTH_TOKEN_URL', 'https://graph.facebook.com/v2.7/oauth/access_token');
	define( 'FACEBOOK_GET_USERINFO_URL', 'https://graph.facebook.com/me');
	class OAuthRequest{
		private $client_id;
		private $client_secret;
		private $redirect_url;
		private $state;
		private $session;
		private $authorize_url = FACEBOOK_OAUTH_AUTHORIZE_URL;
		private $accesstoken_url = FACEBOOK_OAUTH_TOKEN_URL;
		private $verifytoken_url = FACEBOOK_GET_USERINFO_URL;
		private $code;
		private $tokenArr; 
		private $token;
		private $userInfo;

		function __construct( $client_id, $client_secret, $redirect_url) {
			$this -> client_id = $client_id;
			$this -> client_secret = $client_secret;
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
			return $this -> accesstoken_url . '?client_id=' . $this -> client_id .'&client_secret='.$this->client_secret.'&redirect_uri=' .urlencode($this->redirect_url). '&code=' . $this -> code;
		}
		public function get_verifytoken_url(){
			return $this->verifytoken_url . '?access_token='.$this->token['access_token'];
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
			$this->token = $data;
		}
		public function get_user_profile(){
			$ch = curl_init();
			curl_setopt($ch, CURLOPT_URL, $this -> get_verifytoken_url() );
			curl_setopt($ch, CURLOPT_RETURNTRANSFER, true );
			curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false );
			curl_setopt($ch, CURLOPT_SSLVERSION, 1);
   			curl_setopt($ch, CURLOPT_COOKIE, '' );
			curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 300);
			$g = curl_exec($ch);
			curl_close($ch);
			$data = json_decode($g,true);
			$this -> userInfo = array(
				'userID' => $data['id'],
				'name' => $data['name'],
			);
			
		}
		public function get_userInfo(){
			return $this -> userInfo;
		}
		public function get_userID(){
			return $this -> userInfo['id'];
		}
		public function get_name(){
			return $this -> userInfo['name'];
		}
	}
?>
