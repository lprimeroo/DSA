class Node:
    """Node for Python Trie Implementation"""
    
    def __init__(self):
        self.word = None
        self.nodes = {} # dict of nodes
        
    def __get_all__(self):
        """Get all of the words in the trie"""
        x = []
        
        for key, node in self.nodes.iteritems() : 
            if(node.word is not None):
                x.append(node.word)
            
            x += node.__get_all__()
                
        return x
    
    def __str__(self):
        return self.word
    
    def __insert__(self, word, string_pos = 0):
        """Add a word to the node in a Trie"""
        current_letter = word[string_pos]
        
        # Create the Node if it does not already exist
        if current_letter not in self.nodes:
            self.nodes[current_letter] = Node();

        if(string_pos + 1 == len(word)):
            self.nodes[current_letter].word = word
        else:
        	self.nodes[current_letter].__insert__(word, string_pos + 1)
            
    	return True
    
    def __get_all_with_prefix__(self, prefix, string_pos):
        """Return all nodes in a trie with a given prefix or that are equal to the prefix"""
        x = []
        
        for key, node in self.nodes.iteritems() : 
            # If the current character of the prefix is one of the nodes or we have
            # already satisfied the prefix match, then get the matches
            if(string_pos >= len(prefix) or key == prefix[string_pos]):
            	if(node.word is not None):
                	x.append(node.word)
                    
                if(node.nodes != {}):
                    if(string_pos + 1 <= len(prefix)):
                        x += node.__get_all_with_prefix__(prefix, string_pos + 1)
                    else:
            			x += node.__get_all_with_prefix__(prefix, string_pos)
    
        return x       


class Trie:
   """Trie Python Implementation"""
  
   def __init__(self):
        self.root = Node()
        
   def insert(self, word):
        self.root.__insert__(word)
        
   def get_all(self):
        return self.root.__get_all__()

   def get_all_with_prefix(self, prefix, string_pos = 0):
        return self.root.__get_all_with_prefix__(prefix, string_pos)

# Create the trie and insert some words then do some tests
trie = Trie()
trie.insert("go")
trie.insert("gone")
trie.insert("gi")
trie.insert("cool")
trie.insert("comb")
trie.insert("grasshopper")
trie.insert("home")
trie.insert("hope")
trie.insert("hose")

print "Make sure that the data structure is correctly set up by accesing words manually: "
print str(trie.root.nodes['g'].nodes['o'])
print str(trie.root.nodes['g'].nodes['i'])
print str(trie.root.nodes['c'].nodes['o'].nodes['o'].nodes['l'])
print "\n"

print "print all words to make sure they are all there: "
print trie.get_all()
print "\n"

print "print out all the words with the given prefixes: "
print trie.get_all_with_prefix("g")
print trie.get_all_with_prefix("go")
print trie.get_all_with_prefix("co")
print trie.get_all_with_prefix("hom")
print trie.get_all_with_prefix("gr")