string encode(string src)
{     
  //Your code here
  stack<char> st;
  string ans ="";
  for(int i=0;i<src.length();i++){
      if(!st.empty() && st.top()!=src[i]){
          char ch = st.top();
          int cnt =0;
          while(!st.empty()){
              cnt++;
              st.pop();
          }
          ans+=ch;
          ans = ans + to_string(cnt);
          st.push(src[i]);
          
      }else{
          st.push(src[i]);
      } 
  }
  if(!st.empty()){
          char ch = st.top();
          int cnt =0;
          while(!st.empty()){
              cnt++;
              st.pop();
          }
          ans+=ch;
          ans = ans + to_string(cnt);
          
  }
      
  return ans;
}

