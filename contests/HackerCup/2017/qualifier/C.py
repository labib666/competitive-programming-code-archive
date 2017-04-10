import sys

t = int(sys.stdin.readline())
tc = 0
#print t

while tc<t:
	tc += 1
	#print tc, t

	[h, n] = [int(x) for x in sys.stdin.readline().split()]
	#print h, n

	spells = sys.stdin.readline().split()
	#print spells

	res = 0.000000000

	for x in spells:
		firstSplit = x.split('d')
		rolls = int(firstSplit[0])
		faces = 0
		extras = 0
		#print rolls
		
		if firstSplit[1].find('+') != -1:
			secondSplit = firstSplit[1].split('+')
			faces = int(secondSplit[0])
			extras = int(secondSplit[1])

		elif firstSplit[1].find('-') != -1:
			secondSplit = firstSplit[1].split('-')
			faces = int(secondSplit[0])
			extras = int(secondSplit[1])
			extras = -extras

		else:
			faces = int(firstSplit[1])

		#print faces, rolls, extras

		dp = []
		for i in range (405):
			dp.append(0)

		dp[0] = 1

		total = faces ** rolls
		#print total

		for turns in range(rolls):
			i = 400
			while i >= 0:
				dp[i] = 0
				j = max(0,i-faces)
				while j < i:
					dp[i] += dp[j]
					j += 1
				i -= 1
			#print dp

		good = 0
		start = max(0,h-extras)
		for i in range (start,401):
			good += dp[i]

		#print x, good, total

		rat = float(good) / float(total)
		res = max(res, rat)

	print 'Case #{:d}: {:.7f}'.format(tc,res)