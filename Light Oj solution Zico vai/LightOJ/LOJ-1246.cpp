#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long BigMod(long long B,long long P,long long M) {
    long long R=1;
    while(P>0) {
        if(P%2==1) {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return R;
}
int main() {
    int t;
    long long fact[52];
    fact[0]=1;
    for(long long i=1;i<=50;i++){
		fact[i]=i*fact[i-1];
		fact[i]%=mod;
    }
    scanf("%d",&t);
    for(int z=1; z<=t; z++) {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        n++;
        m++;
        int x=n*m;
        int y=x/2;
        x-=y;
        long long ans=1;
        for(int i=1;i<k;i++){
			ans*=fact[k];
			ans%=mod;
			ans*=BigMod((fact[i]*fact[k-i])%mod,mod-2,mod);
			ans%=mod;
			ans*=BigMod(i,x,mod);
			ans%=mod;
			ans*=BigMod(k-i,y,mod);
			ans%=mod;
			ans*=fact[i];
			ans%=mod;
        }
        if(k==1){
			if(n==1 && m==1)ans=1;
			else ans=0;
        }
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}
