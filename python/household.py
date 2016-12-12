# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean
# 2016 2학기 컴프 프로젝트
# python3 기준

# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean

housekeeping_book = []

def add_record(date, item, price):
	global housekeeping_book
	housekeeping_book +=[{'date': date, 'item': item, 'price': price}]
	
def read_database(filename):
	f = open(filename, 'r')
	for line in f:
		fields = line.rstrip().split("\t")
		date = fields[0]
		item = fields[1]
		price = int(fields[2])
		add_record(date, item, price)
		
def print_scores(l):
	temp = []
	for x in l:
		temp +=[{'date': x['date'], 'item': x['item'], 'price': x['price']}]
	
	temp.sort(key=_price,reverse=True)
	for x in temp:
		print("%s %s %d" % (x['date'], x['item'], int(x['price'])))
		
def print_by_item(l):
	temp = []
	for x in l:
		temp +=[{'date': x['date'], 'item': x['item'], 'price': x['price']}]
	
	temp.sort(key=_price,reverse=True)
	print("max = %s %s %d" % (temp[0]['date'],temp[0]['item'],int(temp[0]['price'])))
	n=len(temp)-1
	print("min = %s %s %d" % (temp[n]['date'],temp[n]['item'],int(temp[n]['price'])))
	
def print_total_price(l):
	_sum=0
	for x in l:
		_sum+=x['price']
	print("sum = %d" % _sum)
		
def search_by_date(date):
	return [x for x in housekeeping_book if x['date'] == date]

def search_by_item(item):
	return [x for x in housekeeping_book if x['item'] == item]

def _price(t):
	return t['price']

def order_by_price():
	temp = []
	for x in housekeeping_book:
		temp +=[{'date': x['date'], 'item': x['item'], 'price': x['price']}]
		
	temp.sort(key=_price,reverse=True)
	num=0
	for x in temp:
		print("%s %s %d" % (x['date'], x['item'], int(x['price'])))
		num+=1
		if num == 10: break
	
read_database('data/expenses.txt')

while True:
	print("1. Data input    2. Search by date    3. Top ten    4. Search by item    X. Quit")
	selection = input("Selection: ")
	if selection == "X":
		break
		
	elif selection == "1":
		date = input("Date: ")
		item = input("Item: ")
		price = input("Price: ")
		add_record(date, item, int(price))
	elif selection == "2":
		date = input("Date: ")
		print_total_price(search_by_date(date))
		print_scores(search_by_date(date))
		
	elif selection == "3":
		order_by_price()
		
	elif selection == "4":
		item = input("Item: ")
		print_total_price(search_by_item(item))
		print_by_item(search_by_item(item))
		
	else:
		print("Wrong input!")

print("Bye!")
