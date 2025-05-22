class TrieNode{
public:
    TrieNode* children[26];
    bool isWord;

    TrieNode(){
        for(int i=0; i<26; i++){
            children[i]=NULL;
        }
        isWord= false;
    }
};

class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
};

class WordDictionary {
public:
    TrieNode* root;
    Trie* trie;
    WordDictionary() {
        trie = new Trie();
        root = trie->root;
        
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        int curr =0;
        for(int i=0; i<word.size(); i++){
            curr = word[i]-'a';
            if(node->children[curr]==NULL){
                node->children[curr]=new TrieNode();
            }
            node=node->children[curr];
        }
        node->isWord=true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        return searchHelper(word, 0, root);
        
    }

    bool searchHelper(const string& word, int index, TrieNode* node){
        if(!node) return false;
        if(index==word.size()) return node->isWord;

        char ch = word[index];
        if(ch=='.'){
            for(int i=0; i<26; i++){
                if(node->children[i] && searchHelper(word, index+1, node->children[i])){
                    return true;
                }
            }
            return false;
        }
        else{
            int curr = ch - 'a';
            return searchHelper(word, index+1, node->children[curr]);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */