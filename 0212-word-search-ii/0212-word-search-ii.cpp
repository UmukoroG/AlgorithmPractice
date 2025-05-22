class TrieNode{
public:
    TrieNode* children[26];
    bool isWord;
    
    TrieNode(){
        for(int i=0; i<26; i++){
            children[i]=NULL;
        }
        isWord=false;
    }
};

class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();        
    }

    void addWord(string word){
        TrieNode* node= root;
        int curr=0;
        for(int i=0; i<word.size(); i++){
            curr = word[i]-'a';
            if(node->children[curr]==NULL){
                node->children[curr]= new TrieNode();
            }
            node=node->children[curr];
        }
        node->isWord = true;
    }
};

class Solution {
public:
    TrieNode* root;
    Trie* trie;
    int ROWS,COLS;
    vector<string> res;

    Solution(){
        trie= new Trie();
        root = trie->root;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        //add all words to Trie
        for(string& w: words){
            trie->addWord(w);
        }

        ROWS = board.size();
        COLS = board[0].size();

        //start dfs from every cell
        for(int r=0; r<ROWS; r++){
            for(int c=0; c<COLS; c++){
                dfs(board, r,c , root,"");
            }
        }

        return res;
    }

private:
    void dfs(vector<vector<char>>& board, int rows, int cols, TrieNode* node, string word){
        
        if(rows < 0 || cols<0 || rows>=board.size() || cols>=board[0].size() || 
            board[rows][cols]=='#'){
            return;
        }
        char ch = board[rows][cols];
        int idx = ch - 'a';

        //check if path exist in Trie
        if(node->children[idx]==NULL) return;

        node = node->children[idx];
        word+=ch;

        //if its a valid word
        if(node->isWord){
            res.push_back(word);
            node->isWord = false; //avoid dupl entries
        }

        //mark cell as visited
        board[rows][cols]='#';

        //visits all required paths
        dfs(board,rows+1, cols, node, word);
        dfs(board,rows-1, cols, node, word);
        dfs(board,rows, cols+1, node, word);
        dfs(board,rows, cols-1,node, word);
                    
        board[rows][cols]=ch; //restore the original value;
    }

};