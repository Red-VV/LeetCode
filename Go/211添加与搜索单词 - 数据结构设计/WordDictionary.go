type WordDictionary struct {
	child map[rune]*WordDictionary
	isValid bool
}


/** Initialize your data structure here. */
func Constructor() WordDictionary {
	return WordDictionary {
		child: make(map[rune]*WordDictionary),
		isValid: false,
	}
}


/** Adds a word into the data structure. */
func (this *WordDictionary) AddWord(word string)  {
	trie := this
	for _, val := range word {
		if child, ok := trie.child[val]; ok {
			trie = child
		} else {
            childTrie := Constructor()
			trie.child[val] = &childTrie
			trie = trie.child[val]
		}
	}
	trie.isValid = true
}


/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
func (this *WordDictionary) Search(word string) bool {
	trie := this
	if len(word) == 0 {
		return trie.isValid
	}
	node := rune(word[0])
	word = word[1:]
	if node != '.' {
		if trie, ok := trie.child[node]; ok {
			return trie.Search(word)
		}
		return false
	} else {
		for _, val := range trie.child {
			if val.Search(word) {
				return true
			}
		}
	}
	return false
}


/**
 * Your WordDictionary object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddWord(word);
 * param_2 := obj.Search(word);
 */