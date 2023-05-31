const int MAX = 1000010;
bool prime[MAX + 100];
vector<int>n_prime;
void init(){
  memset(prime, false, sizeof prime);
  for(int i = 2; i < MAX;++i){
      if(prime[i])continue;
      else n_prime.push_back(i);
      for(int j = i * 2; j < MAX;j += i){
          prime[j] = true;
      }
  }
}
