def make_trie(*args):
	trie={}
	for word in args:
		if type(word)!= str:
			raise TypeError("Trie work only on strings")
		# temp_trie and trie refer to the same dictionary object.
		temp_trie=trie
		for letter in word:
			# here setdefault sets the letter to {}({'y':{}}) and then returns {} to temp_trie.
			# So now temp_trie contains {} but trie points to ({'y':{}}).

			# setdefault assigns the letter their value and returns {}
			# That is why nesting takes place.
			temp_trie=temp_trie.setdefault(letter,{})
		temp_trie=temp_trie.setdefault('__end__','__end__')

	return trie

def in_trie(trie,word):
	if type(word)!= str:
		raise TypeError("Trie work only on strings")

	temp_trie=trie
	for letter in word:
		if letter not in temp_trie:
			return False
		temp_trie=temp_trie[letter]

	if "__end__" in temp_trie:
		return True
	else:
		return False

def remove(trie,word,depth):
	if word and word[depth] not in trie:
		return False

	if len(word) == depth + 1:
		if '__end__' in trie[word[depth]]:		
			del trie[word[depth]]['__end__']  
			
		if len(trie[word[depth]]) > 0 and len(trie) > 1:   
			return False
		elif len(trie) > 1 :  
			del trie[word[depth]]
			return False
		elif len(trie[word[depth]]) > 0:   
			return False
		else:
			return True
	else:
		temp_trie = trie 
		# Recursively climb up to delete.
		if remove(temp_trie[word[depth]], word, depth + 1):
			if temp_trie:
				del temp_trie[word[depth]]
			return not temp_trie
		else:
			return False



trie=make_trie('hack','hackerrank')
print trie
print in_trie(trie,'hac')
print trie
