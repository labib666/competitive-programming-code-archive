# your code goes here
t = int ( raw_input() )
tc = 0

while tc < t:
	tc = tc + 1
	n = int ( raw_input() )
	
	res = n-1
	
	hi = 10**9
	lo = 2
	
	#print hi,lo
	while hi>=lo:
		mid = (hi+lo)/2
		if ( mid*(mid+1) ) >= n-1:
			hi = mid-1
		else:
			lo = mid+1
	
	if ( lo*(lo+1) == n-1 ):
		res = lo
	
	for i in range (2,1000001):
		tot = 0
		j = 0
		while tot<n:
			tot += i**j
			j += 1
		if tot == n:
			res = i
			break
		
	print "Case #{0:d}:".format(tc),res
