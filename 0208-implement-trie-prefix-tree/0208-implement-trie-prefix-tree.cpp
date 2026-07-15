class Trie {
public:
    char data;
    Trie* children[26];
    bool isTerminal;
    Trie() {
        for(int  i =0; i < 26; i++) children[i] = nullptr;
        isTerminal = false;
    }
    
    void insertUtil(Trie* root, string word){
        if(word.length() == 0) {root->isTerminal = true; return;}

        int idx = word[0] - 'a';
        Trie* child;
        if(root->children[idx] != nullptr){
            child = root->children[idx];
        }
        else{
            child = new Trie();
            child->data = word[0];
            root->children[idx] = child;
        }
        return insertUtil(child, word.substr(1));
    }
    void insert(string word) {
        // Trie* root;
        // root->data = '/0';
        return insertUtil(this, word);
    }

    bool searchUtil(Trie* root, string word){
        if(word.length() == 0) return root->isTerminal;
        int idx = word[0] - 'a';
        Trie* child;
        if(root->children[idx] != nullptr){
            child = root->children[idx];
        }
        else{
            return false;
        }
        return searchUtil(child, word.substr(1));
    }
    
    bool search(string word) {
        // Trie* root;
        // root->data = '/0';
        return searchUtil(this, word);
    }

    bool startsWithUtil(Trie* root, string prefix){
        if(prefix.length() == 0)
            return true;

        int idx = prefix[0] - 'a';

        if(root->children[idx] == nullptr)
            return false;

        return startsWithUtil(root->children[idx], prefix.substr(1));

    }
    
    bool startsWith(string prefix) {
        return startsWithUtil(this, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */