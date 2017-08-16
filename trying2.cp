int A;
unordered_set<int> ust;
void solve(vector<int> &vec);
vector<int> Solution::grayCode(int a) {
  ust.clear();
  vector<int> vec;
  ::A=a;
  solve(vec);
  return vec;
}

int toNum(vector<bool> bits){
  int num=0;
  for(int i=0;i<bits.size();i++){
    if(bits[i]==1)num+=pow(2,A-i-1);
  }
  return num;
}

void solve(vector<int> &vec){
  if(vec.empty()){
    vec.push_back(0);
    ust.insert(0);
    return solve(vec);
  }
  vector<bool>bits(A,0);
  int top = vec.back();
  int ctr=0;
  while(top>0 and ctr<A){
    bits[ctr++]=top&1;
    top>>=1;
  }
  reverse(bits.begin(), bits.end());

  for(int i=0;i<A;i++){
    bits[i]=bits[i]^1;
    int newNum = toNum(bits);
    if(ust.find(newNum)==ust.end()){
      ust.insert(newNum);
      vec.push_back(newNum);
      return solve(vec);
    }
    bits[i]=bits[i]^1;
  }
}
