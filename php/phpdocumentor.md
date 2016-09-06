# phpDocumentor

## pear download
	curl -O http://pear.php.net/go-pear.phar
	sudo php -d detect_unicode=0 go-pear.phar
	
## phpDoumentor download
	$ sudo pear channel-discover pear.phpdoc.org
	$ sudo pear install phpdoc/phpDocumentor
	
## using
	$ phpdoucmentor run -f "file name" -d "directory name"