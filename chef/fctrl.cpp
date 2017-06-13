<pre>#include&lt;stdio.h&gt;

int main()
{

int n;

scanf(&quot;%d&quot;,&amp;n);

while(n--){
int r,c,x=0,p=1;

scanf(&quot;%d&quot;,&amp;c);

do 
x+=(r=c/(p*=5));
while(r);

printf(&quot;%d\n&quot;,x);

}

return 0;
}
</pre>