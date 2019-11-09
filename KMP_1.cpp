//Time Complexity : O(m+n) where m: length of text, n: length of pattern


#include <iostream>
using namespace std;
int lps[100];
void computeLPS(string pat)
{
    //Note: len is for measuring prefix suffix, i is for filling lps array 
    int len=0; //length of longest prefix suffix
    lps[0]=0;  
    //i starts from 1
    int i=1,m=pat.length();
    
    while(i<m)
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else //pat[i]!=pat[len]
        {
            if(len!=0) //No increment of i
            len=lps[len-1]; //len will remain as it is
            else       //len==0
            {
                lps[i]=0;
                i++;
            }
        }
        
    }
}

void kmpSearch(string txt,string pat)
{
    int m=pat.length(),n=txt.length();
    int i=0; //index for txt
    int j=0; //index for pat
    
    computeLPS(pat);
    
    while(i<n)
    {
        if(pat[j]==txt[i])
        {
            j++;
            i++;
        }
        
        if(j==m)
        {
            cout<<"Pattern found at : "<<i-j<<"\n";
            j=lps[j-1];
        }
        
        else if(i<n && pat[j]!=txt[i])
        {
            if(j!=0)
            j=lps[j-1];
            else
            i++;
        }
        
    }
}

int main() {
    kmpSearch("ABDABCAABAABAABABDACBA","AABAA");
    return 0;
}
