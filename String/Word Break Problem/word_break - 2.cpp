//using DP

#include <bits/stdc++.h> 
using namespace std; 
  
/* A utility function to check whether a word is  
  present in dictionary or not. An array of strings  
  is used for dictionary.  Using array of strings for 
  dictionary is definitely not a good idea. We have  
  used for simplicity of the program*/
int dc(string word) 
{ 
    string dictionary[] = {"mobile","samsung","sam","sung", 
                            "man","mango","icecream","and", 
                             "go","i","like","ice","cream"}; 
    int size = sizeof(dictionary)/sizeof(dictionary[0]); 
    for (int i = 0; i < size; i++) 
        if (dictionary[i].compare(word) == 0) 
           return true; 
    return false; 
} 
  
// returns true if string can be segmented into space  
// separated words, otherwise returns false 
bool wordBreak(string str) 
{ 
  int n=str.size();
  if(n==0){
  	return 1;
  }
  int visited[n+1];
  
  
  memset(visited,0,sizeof(visited));
  for(int i=1;i<=n;i++){
  	if( !visited[i] && dc(str.substr(0,i))){
  		visited[i]=1;
	  }
	if(visited[i]){
		
		if(i==n)
		return true;
		
		for(int j=i+1;j<=n;j++){
			
			  	if( !visited[j] && dc(str.substr(i,j-i))){
				  visited[j]=1;
				}
				
				if(j==n && visited[j])
				return true;

		}
		
	}
  }
  
    return false;
} 
  
// Driver program to test above functions 
int main() 
{ 
    wordBreak("ilikesamsung")? cout <<"Yes\n": cout << "No\n"; 
    wordBreak("iiiiiiii")? cout <<"Yes\n": cout << "No\n"; 
    wordBreak("")? cout <<"Yes\n": cout << "No\n"; 
    wordBreak("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n"; 
    wordBreak("samsungandmango")? cout <<"Yes\n": cout << "No\n"; 
    wordBreak("samsungandmangok")? cout <<"Yes\n": cout << "No\n"; 
    return 0; 
} 
