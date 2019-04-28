#include<iostream>
#include<bitset>
using namespace std;

struct Three8bit{
    char a,b,c;
};

struct Two12Bit{
    int a, b;

    Two12Bit(char a, char b, char c){
        bitset<8> f(a), s(b), t(c);
        cout<<f<<" "<<s<<" "<<t<<"\n";  

        bitset<12> F(a);
        bitset<12> S(c);
        F = F<<4;
        cout<<F<<" "<<S<<"\n";
        for(int i = 0; i < 4; i++) F[3-i] = s[7-i];
        for(int i = 0; i < 4; i++) S[11-i] = s[3-i];
        

        cout<<F<<" "<<S<<"\n";
        this->a = int(F.to_ullong()); this->b = int(S.to_ullong());
        cout<<this->a<<" "<<this->b<<"\n";
    }
};

int main(){
    Two12Bit a('a', '3', 'Z');
    cout<<a.a<<" "<<a.b<<"\n";
    return 1;
}