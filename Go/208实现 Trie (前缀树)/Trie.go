type Trie struct {
	child map[rune]*Trie
	isValid bool
}


/** Initialize your data structure here. */
func Constructor() Trie {
	return Trie {
		child: make(map[rune]*Trie),
		isValid: false}
}


/** Inserts a word into the trie. */
func (this *Trie) Insert(word string)  {
	trie := this
	for _, val := range word {
		if child, ok := trie.child[val]; ok {
			trie = child
		} else {
			trie.child[val] = &Trie{
				child: make(map[rune]*Trie),
				isValid: false}
			trie = trie.child[val]
		}
	}
	trie.isValid = true
}


/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
	trie := this
	for _, val := range word {
		if child, ok := trie.child[val]; ok {
			trie = child
		} else {
			return false
		}
	}
	return trie.isValid
}


/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
	trie := this
	for _, val := range prefix {
		if child, ok := trie.child[val]; ok {
			trie = child
		} else {
			return false
		}
	}
	return true
}


/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */