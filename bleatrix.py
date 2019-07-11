def trotter(tests, n):
	count = 0	# Binary counting 
	n1    = 0

	if n == 0:
		print "Case #{}: {}".format(tests, "INSOMNIA")
		return

	while count != 1023:
		n1   += n
		temp = n1

		while temp > 0:
			k = temp % 10
			count |= 1 << k
			temp /= 10
	
	print "Case #{}: {}".format(tests, n1)

def main():
	tests = int(raw_input()) # First line. Number of tests.

	for i in xrange(1, tests + 1):
		n = [int(k) for k in raw_input().split()]
		n = ''.join(map(str, n))
		trotter(i, int(n))

if __name__ == '__main__':
	main()