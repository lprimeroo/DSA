# Github username : yatingupta10
# Website : http://www.yatingupta.me/

# Find occurrences of pattern as a contiguous subsequence of the text.
# For the KMP versions the pattern must be a list or string, because we
# perform array indexing into it, but the text can be anything that can
# be used in a for-loop.  The naive match shown first requires the text
# to be a list or string as well.

from __future__ import generators

# Naive algorithm to find and return starting position of first match
# takes O(p*t) time e.g. for pattern='a'*(p-1)+'b', text='a'*t
def naiveMatch(pattern, text):
	for startPos in range(len(text) - len(pattern) + 1):
		matchLen = 0
		while pattern[matchLen] == text[startPos + matchLen]:
			matchLen += 1
			if matchLen == len(pattern):
				return startPos
	
# Find and return starting position of first match, or None if no match exists
#
# Time analysis:
# each iteration of the inner or outer loops increases 2*startPos + matchLen
# this quantity starts at 0 and ends at most at 2*t+p
# so the total number of iterations of both loops is O(t+p)
#
def kmpFirstMatch(pattern, text):
	shift = computeShifts(pattern)
	startPos = 0
	matchLen = 0
	for c in text:
		while matchLen >= 0 and pattern[matchLen] != c:
			startPos += shift[matchLen]
			matchLen -= shift[matchLen]
		matchLen += 1
		if matchLen == len(pattern):
			return startPos

# Slightly more complicated version to return sequence of all matches
# using Python 2.2 generators (yield keyword in place of return).
# Same time analysis as kmpFirstMatch.
def kmpAllMatches(pattern, text):
	shift = computeShifts(pattern)
	startPos = 0
	matchLen = 0
	for c in text:
		while matchLen >= 0 and pattern[matchLen] != c:
			startPos += shift[matchLen]
			matchLen -= shift[matchLen]
		matchLen += 1
		if matchLen == len(pattern):
			yield startPos
			startPos += shift[matchLen]
			matchLen -= shift[matchLen]

# Construct shift table used in KMP matching
# Time analysis: each iteration of either loop increases shift+pos
# This quantity starts at 0 and ends at most at 2*p
# So total time is O(p).
#
def computeShifts(pattern):
	shifts = [None] * (len(pattern) + 1)
	shift = 1
	for pos in range(len(pattern) + 1):
		while shift < pos and pattern[pos-1] != pattern[pos-shift-1]:
			shift += shifts[pos-shift-1]
		shifts[pos] = shift
	return shifts
	
if __name__ == "__main__":
    n = raw_input("Enter the text: ")
    print (computeShifts(n))
