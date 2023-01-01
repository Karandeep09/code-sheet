const int mod = 1e9+7;
template <typename T>
class Modular {
    
    public:
    T x;
    Modular(){
      x = T(0);
    }
    Modular(T x){
       this -> x = x;
    }
    
    Modular operator + (const Modular Rhs){ return Modular((x + Rhs.x) % mod); }
    Modular operator - (const Modular Rhs){ return Modular((x - Rhs + mod) % mod); }
    Modular operator * (const Modular Rhs){ return Modular(x * Rhs.x % mod); }
    Modular operator / (const Modular Rhs){ return Modular(x) * binpow(Rhs, mod-2); }
    
    Modular binpow (Modular a, int n){
        Modular res = Modular(1);
        for(int n = mod - 2; n > 0; n /= 2){
            if(n & 1){
                res = res * a; 
            }
            a = a * a;
        }
        return res;
    }
};

using Mint = Modular<long long>;
