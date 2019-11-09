//Time Complexity : O(m+n) where m: length of text, n: length of pattern

#include <iostream>
using namespace std;

int F[100];

void buildFailureFunction(string pat)
{
    F[0]=F[1]=0;
    int m=pat.length();
    
    for(int i=2;i<=m;i++)
    {
        //j is index of largest next partial match of string under index i-1
        int j=F[i-1];
        
        for(;;)
        {
            //Check if last character of pattern expands the current best partial match
            if(pat[j]==pat[i-1])
            {
                F[i]=j+1;
                break;
            }
            
            //If we can't expand even the empty substring
            if(j==0)
            {
                F[i]=0;
                break;
            }
            
            //ELse go the next best partial match
            j=F[j];
            
        }
    cout<<"Failure Function at i="<<i<<" j="<<j<<": ";
    for(int k=1;k<=i;k++)
    cout<<F[k]<<" ";
    cout<<"\n";
    }
    
    
    
}

void kmpSearch(string text, string pat)
{
    buildFailureFunction(pat);
    
    //Initial state is empty string
    int i=0;
    
    //First character of text
    int j=0,n=text.length(),m=pat.length();
    
    for(;;)
    {
        //Reached end of the text
        if(j==n)
        break;
        
        //Current character of text expands the current match
        if(text[j]==pat[i])
        {
            i++; //Change the state
            j++; //Next character from text
            
            if(i==m)
            {
                cout<<"Match found at index: "<<j-m<<"\n";
            }
        }
        
        //If current state is not zero we try to expand the largest match
        else if(i>0)
        i=F[i];
        
        //If everthing fails we goto next character of text
        else j++;
        
    }
}

int main() {
    kmpSearch("ABDABCAABAABAABABDACBA","AABAA");
    return 0;
}
