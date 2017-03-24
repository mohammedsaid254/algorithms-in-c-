const int N = 1e5 + 5;
bool is_prime[N];
vector<int> primes;

void sieve(){
    is_prime[0] = is_prime[1] = 1;
    for(long long i = 2 ; i < N ; i++)
        if(!is_prime[i])
           for(long long j = i*i ; j < N ; j+=i)
                is_prime[j] = 1;


    for(int i = 0 ; i < N ; i++)
        if(!is_prime[i])
            primes.push_back(i);
}
