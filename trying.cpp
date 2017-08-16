vector<int> Solution::grayCode(int A) {
    int lim = (1<<A) - 1;
    vector<int> ans;
    if(A==0)return ans;

    for(int i=0;i<=lim;i++){
      ans.push_back(gray(i));
    }
    return ans;
}

int gray(int num){
  if(num==0)return 0;
  vector<bool> bits;
  while(num>0){
    if(num&1)bits.push_back(1);
    else bits.push_back(0);
    num>>=1;
  }
  reverse(bits.begin(), bits.end());
  vector<bool> ans(bits.size());
  ans[0]=bits[0];
  for(int i=1;i<bits.size();i++)ans[i]=bits[i]^bits[i-1];
  int ret=0;
  for(int i=0;i<ans.size();i++){
    if(ans[i])ret+=(1<<ans.size()-i-1);
  }
  return ret;
}
