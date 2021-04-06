//time complexity O(n2*m) where m is no of words
// 127. Word Ladder

#include<bits/stdc++.h>
using namespace std;

int find_transform( vector<string>&wordList,string beginWord,string endWord){
             unordered_set<string> myset;
        bool isPresent = false; //Checks if endWord is present in Dict
        //Insert all words from Dict in myset
        for(auto word: wordList)
        {   
              // may be endword not present in wordlist so we just return 0
            if(endWord.compare(word)==0)
                isPresent = true;
            myset.insert(word);    //Insert word in Dict
        }
        if(isPresent==false)    //endWord is not present in Dict
            return 0;
        
        queue<string> q;
        q.push(beginWord);
        int includeWord = 0;
        
        while(!q.empty())
        {
            includeWord+=1;
            int qsize = q.size();   //No of elements at a level
            while(qsize--)
            {
                string curr = q.front();
                q.pop();
                //check for all possible 1 depth words
                for(int i=0;i<curr.length();++i)  //For each index
                {
                    string temp = curr;
                    for(char c='a';c<='z';++c)  //Try all possible chars
                    {
                        temp[i] = c;
                        if(curr.compare(temp)==0)
                            continue;   //Skip the same word
                        if(temp.compare(endWord)==0)     
                            return includeWord+1; //endWord found
                        if(myset.find(temp)!=myset.end()==true)
                        {
                            q.push(temp);  // after find generated word from bruteforce approach we  push in a queue                                                      and remove from myset;
                            myset.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
}

int main(){



    vector<string>vec={"hot","dot","dog","lot","log","cog"};
    string start_word="hit";
    string end_word="cog";

    cout<<find_transform(vec,start_word,end_word)<<"\n";
}