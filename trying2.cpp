#define ll long long int
ll A;
unordered_set<ll> ust;
void solve(vector<ll> &vec);
vector<ll> Solution::grayCode(ll a) {
  ust.clear();
  vector<ll> vec;
  ::A=a;
  solve(vec);
  return vec;
}

ll toNum(vector<bool> bits){
  ll num=0;
  for(ll i=0;i<bits.size();i++){
    if(bits[i]==1)num+=pow(2,A-i-1);
  }
  return num;
}

void solve(vector<ll> &vec){
  if(vec.empty()){
    vec.push_back(0);
    ust.insert(0);
    return solve(vec);
  }
  vector<bool>bits(A,0);
  ll top = vec.back();
  ll ctr=0;
  while(top>0 and ctr<A){
    bits[ctr++]=top&1;
    top>>=1;
  }
  reverse(bits.begin(), bits.end());

  for(ll i=0;i<A;i++){
    bits[i]=bits[i]^1;
    ll newNum = toNum(bits);
    if(ust.find(newNum)==ust.end()){
      ust.insert(newNum);
      vec.push_back(newNum);
      return solve(vec);
    }
    bits[i]=bits[i]^1;
  }
}
