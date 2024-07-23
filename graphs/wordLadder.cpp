#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_set>

//thers a second and third part you might want to check that out aswell
//please do it
using namespace std;

int wordLadder(string startWord,string targetWrod,vector<string>&wordList){
    queue<pair<string,int>>q;
    q.push({startWord,1});
    //copying the vector in to a list
    unordered_set<string>st(wordList.begin(),wordList.end());
    st.erase(startWord);
    while(!q.empty()){  
        string word=q.front().first;
        int level=q.front().second;
        q.pop();
        if(word==targetWrod){
            return level;
        }
        for(int i=0;i<word.size();i++){ 
            string temp=word;
            for(char c='a';c<='z';c++){
                temp[i]=c;
                if(st.find(temp)!=st.end()){
                    q.push({temp,level+1});
                    st.erase(temp);
                }
            }
        }

    }
    return 0;
}

int main(){
    string startWord="hit";
    string targetWord="cog";
    vector<string>wordList={"cit","dot","dog","lot","log","cog"};
    cout<<wordLadder(startWord,targetWord,wordList);
}