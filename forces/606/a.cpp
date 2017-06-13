#include<bits/stdc++.h>

int main() {
	int a, b, c,x,y,z,p,q, r, f, g;
	scanf("%d%d%d",&a,&b,&c);
	scanf("%d%d%d",&x,&y,&z);
	p = a - x;
	q = b - y;
	r = c - z;
	f = 0;
	g = 0;
	
	if(p < 0)
		f += p;	
	else {
		g += p;
		g/=2;
	}
	
	if( q < 0)
		f += q;		
	else{
		g += (q/2);
	}
	
	if( r < 0)
		f += r;	
	else{
		g += (r/2);
	}	
	f = -f;
	if(f <= g )
		printf("Yes\n");
	
	else
		printf("No\n");
}
